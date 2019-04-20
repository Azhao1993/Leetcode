package Leetcode_677_MapSumPairs;

import java.util.LinkedList;
import java.util.Queue;

/*
	实现一个 MapSum 类里的两个方法，insert 和 sum。
	
	对于方法 insert，你将得到一对（字符串，整数）的键值对。
	字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。
	
	对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。
	
	示例 1:
	
	输入: insert("apple", 3), 输出: Null
	输入: sum("ap"), 输出: 3
	输入: insert("app", 2), 输出: Null
	输入: sum("ap"), 输出: 5
 */
//677. 键值映射
public class MapSum {
	private Node root;

	public MapSum() {
		root = new Node(0);
	}

	public void insert(String key, int val) {
		Node cur = root;
		for (int i = 0; i < key.length(); i++) {
			int temp = key.charAt(i) - 'a';
			if (cur.child[temp] == null) {
				Node node = new Node(0);
				cur.child[temp] = node;
			}
			cur = cur.child[temp];
		}
		cur.val = val;
	}

	public int sum(String prefix) {
		int sum = 0;
		Node cur = root;
		for (int i = 0; i < prefix.length(); i++) {
			int temp = prefix.charAt(i) - 'a';
			if (cur.child[temp] == null) {
				return 0;
			}
			cur = cur.child[temp];
		}
		//
		Queue<Node> queue = new LinkedList<>();
		queue.add(cur);
		while (!queue.isEmpty()) {
			Node temp = queue.poll();
			sum += temp.val;
			for (Node node : temp.child) {
				if (node != null) {
					queue.add(node);
					sum += node.val;
				}
			}

		}
		return sum;

	}
}

class Node {
	int val;
	Node[] child;

	Node(int val) {
		this.val = val;
		child = new Node[26];

	}
}