package Leetcode_146_LRUCache;

import java.util.HashMap;

/*
	运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。
	它应该支持以下操作： 获取数据 get 和 写入数据 put 。
	
	获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
	写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
	
	进阶:	
		你是否可以在 O(1) 时间复杂度内完成这两种操作？
	
	示例:	
		LRUCache cache = new LRUCache( 2 /* 缓存容量  );
		
		cache.put(1, 1);
		cache.put(2, 2);
		cache.get(1);       // 返回  1
		cache.put(3, 3);    // 该操作会使得密钥 2 作废
		cache.get(2);       // 返回 -1 (未找到)
		cache.put(4, 4);    // 该操作会使得密钥 1 作废
		cache.get(1);       // 返回 -1 (未找到)
		cache.get(3);       // 返回  3
		cache.get(4);       // 返回  4
 */
/*
	Your LRUCache object will be instantiated and called as such:
	LRUCache obj = new LRUCache(capacity);
	int param_1 = obj.get(key);
	obj.put(key,value);
*/
public class LRUCache {
	// Map key-key Value-Node
	private HashMap<Integer, Node<Integer>> keyNodeMap;
	// Map key-Node Value-key
	private HashMap<Node<Integer>, Integer> nodeKeyMap;
	// 优先级
	private NodeDoubleLinkedList<Integer> nodeList;
	// 容量
	private int capacity;

	public LRUCache(int capacity) {
		this.capacity = capacity;
		keyNodeMap = new HashMap<Integer, Node<Integer>>();
		nodeKeyMap = new HashMap<Node<Integer>, Integer>();
		nodeList = new NodeDoubleLinkedList<Integer>();
	}

	public int get(int key) {
		if (keyNodeMap.containsKey(key)) {
			// 拿到key对应的节点
			Node<Integer> node = keyNodeMap.get(key);
			// 将此节点挪至尾部
			nodeList.moveNodeToTail(node);
			return node.value;
		} else {
			return -1;
		}

	}

	public void put(int key, int value) {
		// 包含当前key
		if (keyNodeMap.containsKey(key)) {
			Node<Integer> node = keyNodeMap.get(key);
			node.value = value;
			nodeList.moveNodeToTail(node);
			// value值相同
//			if (keyNodeMap.get(key).value == value) {
//				nodeList.moveNodeToTail(keyNodeMap.get(key));
//			} else {
//				// 值不同
//				nodeKeyMap.remove(keyNodeMap.get(key));
//				Node<Integer> node = new Node<Integer>(value);
//				keyNodeMap.put(key, node);
//				nodeKeyMap.put(node, key);
//			}
		} else {
			// 不存在key
			Node<Integer> node = new Node<Integer>(value);
			keyNodeMap.put(key, node);
			nodeKeyMap.put(node, key);
			nodeList.addNode(node);
			// 容量是否越界
			if (keyNodeMap.size() == capacity + 1) {
				removeMostUnusedCache();
			}

		}

	}

	public void removeMostUnusedCache() {
		Node<Integer> oldHead = nodeList.removeHead();
		Integer oldkey = nodeKeyMap.get(oldHead);
		keyNodeMap.remove(oldkey);
		nodeKeyMap.remove(oldHead);
	}

	// 哈希表+双向链表
	class Node<V> {
		V value;
		Node<V> last;
		Node<V> next;

		Node(V value) {
			this.value = value;
		}
	}

	// 自定义双向链表
	class NodeDoubleLinkedList<V> {
		private Node<V> head;
		private Node<V> tail;

		// 构造
		public NodeDoubleLinkedList() {
			this.head = null;
			this.tail = null;
		}

		// 增加一个节点
		public void addNode(Node<V> newNode) {
			// 新节点为空
			if (newNode == null) {
				return;
			}
			// 双向链表为空
			if (this.head == null) {
				this.head = newNode;
				this.tail = newNode;
			} else {
				// 不为空
				this.tail.next = newNode;
				newNode.last = this.tail;
				this.tail = newNode;
			}
		}

		// 将某个节点挪向尾结点（调整有优先级）
		public void moveNodeToTail(Node<V> node) {
			// 当前节点已经在尾部
			if (node == this.tail) {
				return;
			}
			// 当前节点在头部
			if (node == this.head) {
				this.head = node.next;
				this.head.last = null;
			} else {
				// 当前节点在中间
				node.next.last = node.last;
				node.last.next = node.next;
			}
			// 将node节点放在尾部
			this.tail.next = node;
			node.last = this.tail;
			node.next = null;// ！！！
			this.tail = node;
		}

		// 当空间不够时，移除优先级最低的节点（head）
		public Node<V> removeHead() {
			// 链表为空
			if (this.head == null) {
				return null;
			}

			Node<V> res = this.head;
			// 链表只有一个节点
			if (this.head == this.tail) {
				this.head = null;
				this.tail = null;
			} else {
				// 链表上有多个节点
				this.head = res.next;
				res.next = null;// 断开此处！！！
				this.head.last = null;
			}
			return res;
		}
	}

}
