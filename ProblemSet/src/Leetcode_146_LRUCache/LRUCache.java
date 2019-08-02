package Leetcode_146_LRUCache;

import java.util.HashMap;
import java.util.Hashtable;
import java.util.LinkedHashMap;
import java.util.Map;

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

//146. LRU缓存机制
public class LRUCache {
	// 利用LinkedHashMap
	class LRUCache0 extends LinkedHashMap<Integer, Integer> {
		private int capacity;

		public LRUCache0(int capacity) {
			super(capacity, 0.75F, true);
			this.capacity = capacity;
		}

		public int get(int key) {
			return super.getOrDefault(key, -1);
		}

		public void put(int key, int value) {
			super.put(key, value);
		}

		@Override
		protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
			return size() > capacity;
		}
	}

	// 哈希表+双端队列

	// 哈希表 key=value
	// 双端队列：head + tail + removeNode + moveToHead + addNode + poptail
	public class LRUCache1 {

		// 定义双端队列的结点
		class DLinkedNode {
			int key;
			int value;
			DLinkedNode prev;
			DLinkedNode next;
		}

		private void addNode(DLinkedNode node) {
			// 总是将新节点增加在head后面
			node.prev = head;
			node.next = head.next;

			head.next.prev = node;
			head.next = node;
		}

		private void removeNode(DLinkedNode node) {
			// 删除已经存在的结点.
			DLinkedNode prev = node.prev;// 前一个节点
			DLinkedNode next = node.next;// 后一个节点
			// 跨过当前节点
			prev.next = next;
			next.prev = prev;
		}

		private void moveToHead(DLinkedNode node) {
			// 将已存在的结点挪至头的下一个 removeNode(node);
			DLinkedNode res = tail.prev;
			removeNode(res);
			// return res;
		}

		private DLinkedNode popTail() {
			// 超过当前容量时将tail的前一个节点删除
			DLinkedNode res = tail.prev;
			removeNode(res);
			return res;
		}

		private Hashtable<Integer, DLinkedNode> cache = new Hashtable<Integer, DLinkedNode>();
		private int size;
		private int capacity;
		private DLinkedNode head, tail;

		public LRUCache1(int capacity) {
			this.size = 0;
			this.capacity = capacity;

			head = new DLinkedNode();
			// head.prev = null;

			tail = new DLinkedNode();
			// tail.next = null;

			head.next = tail;
			tail.prev = head;
		}

		public int get(int key) {
			DLinkedNode node = cache.get(key);
			if (node == null)
				return -1;

			// move the accessed node to the head;
			moveToHead(node);

			return node.value;
		}

		public void put(int key, int value) {
			DLinkedNode node = cache.get(key);

			if (node == null) {
				DLinkedNode newNode = new DLinkedNode();
				newNode.key = key;
				newNode.value = value;

				cache.put(key, newNode);
				addNode(newNode);

				++size;

				if (size > capacity) {
					// pop the tail
					DLinkedNode tail = popTail();
					cache.remove(tail.key);
					--size;
				}
			} else {
				// update the value.
				node.value = value;
				moveToHead(node);
			}
		}
	}

}
