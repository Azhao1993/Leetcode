package Leetcode_460_LFUCache;

import java.util.HashMap;

/*
	设计并实现最不经常使用（LFU）缓存的数据结构。
	它应该支持以下操作：get 和 put。
	
	get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
	put(key, value) - 如果键不存在，请设置或插入值。
				当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。
				在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
	
	进阶：
		你是否可以在 O(1) 时间复杂度内执行两项操作？
	
	示例：	
		LFUCache cache = new LFUCache( 2 /* capacity (缓存容量)  );
		
		cache.put(1, 1);
		cache.put(2, 2);
		cache.get(1);       // 返回 1
		cache.put(3, 3);    // 去除 key 2
		cache.get(2);       // 返回 -1 (未找到key 2)
		cache.get(3);       // 返回 3
		cache.put(4, 4);    // 去除 key 1
		cache.get(1);       // 返回 -1 (未找到 key 1)
		cache.get(3);       // 返回 3
		cache.get(4);       // 返回 4
 */

//460. LFU缓存
public class LFUCache {
	// 双向链表实现

	// 定义节点类型
	class Node {
		int key;
		int value;
		int times;
		Node up;
		Node down;

		Node(int key, int value, int time) {
			this.times = time;
			this.key = key;
			this.value = value;
		}
	}

	// 双向链表
	class NodeList {
		// list内部的结构
		Node head;// 频率相同的情况下，最近的操作
		Node tail;// 频率相同，删除尾
		// list前后的结构
		NodeList last;
		NodeList next;

		// 构造
		NodeList(Node node) {
			this.head = node;
			this.tail = node;
		}

		// 向list中增加一个新节点
		public void addNodeFromHead(Node newHead) {
			newHead.down = head;
			head.up = newHead;
			head = newHead;
		}

		// 判空
		public boolean isEmpty() {
			return head == null;
		}

		// 删除节点
		public void deleteNode(Node node) {
			// 只有一个节点
			if (head == tail) {
				head = null;
				tail = null;
			} else {
				// 多个节点

				if (head == node) {
					// node是头节点
					head = node.down;
					head.up = null;
					// node.down = null;// ???
				} else if (tail == node) {
					// node是尾节点
					tail = node.up;
					tail.down = null;
					// node.up = null;// ???
				} else {
					// node是中间的节点
					node.up.down = node.down;
					node.down.up = node.up;
				}
			}
			node.up = null;
			node.down = null;
		}

	}

	// LFUCache的构造
	private int capacity;// 容量
	private int size;// 实际大小

	private HashMap<Integer, Node> records;// key-Node
	private HashMap<Node, NodeList> heads;// 节点对应的双向列表
	private NodeList headList;

	// 构造方法
	public LFUCache(int capacity) {
		this.capacity = capacity;
		this.size = 0;
		records = new HashMap<Integer, Node>();
		heads = new HashMap<Node, NodeList>();
		headList = null;
	}

	public int get(int key) {
		if (!records.containsKey(key)) {
			return -1;
		}
		Node node = records.get(key);
		node.times++;
		NodeList curNodeList = heads.get(node);
		move(node, curNodeList);
		return node.value;
	}

	//
	public void put(int key, int value) {
		if (capacity == 0) {
			return;
		}
		// 判断key是否存在
		if (records.containsKey(key)) {
			Node node = records.get(key);
			node.value = value;
			node.times++;
			NodeList curNodeList = heads.get(node);
			move(node, curNodeList);
		} else {
			// 不存在key

			// 容量不够
			if (size == capacity) {
				// 头list的tail节点删除
				Node node = headList.tail;
				headList.deleteNode(node);
				modifyHeadList(headList);
				records.remove(node.key);
				heads.remove(node);
				size--;
			}
			Node node = new Node(key, value, 1);
			if (headList == null) {
				headList = new NodeList(node);
			} else {
				if (headList.head.times == node.times) {
					headList.addNodeFromHead(node);
				} else {
					NodeList newList = new NodeList(node);
					newList.next = headList;
					headList.last = newList;
					headList = newList;
				}
			}
			records.put(key, node);
			heads.put(node, headList);
			size++;
		}
	}

	// 将一个node移动至新list
	public void move(Node node, NodeList oldNodeList) {
		// 从原来的list中删除当前节点
		oldNodeList.deleteNode(node);
		// 获取当前节点所在的list的前一个list
		NodeList preList = modifyHeadList(oldNodeList) ? oldNodeList.last : oldNodeList;
		NodeList nextList = oldNodeList.next;
		if (nextList == null) {
			// 不存在下一个list
			NodeList newList = new NodeList(node);
			if (preList != null) {
				// 前一个节点不为空
				preList.next = newList;
			}
			newList.last = preList;
			if (headList == null) {
				headList = newList;
			}
			heads.put(node, newList);
		} else {
			// 下一list存在

			// times是否匹配
			if (nextList.head.times == node.times) {
				nextList.addNodeFromHead(node);
				heads.put(node, nextList);
			} else {
				NodeList newList = new NodeList(node);
				if (preList != null) {
					preList.next = newList;
				}
				newList.last = preList;
				newList.next = nextList;
				nextList.last = newList;
				if (headList == nextList) {
					headList = newList;
				}
				heads.put(node, newList);
			}
		}
	}

	// 判断删除的列表是否是头链表
	private boolean modifyHeadList(NodeList nodeList) {
		if (nodeList.isEmpty()) {
			if (headList == nodeList) {
				headList = nodeList.next;
				// 判空！！！
				if (headList != null) {
					headList.last = null;
				}
			} else {
				nodeList.last.next = nodeList.next;
				if (nodeList.next != null) {
					nodeList.next.last = nodeList.last;
				}
			}
			return true;
		}
		return false;
	}
}
