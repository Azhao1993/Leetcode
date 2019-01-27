package Leetcode_559_MaximumDepthofN_aryTree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

import Node.Node;

/*
	给定一个 N 叉树，找到其最大深度。	
	最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。	
	例如，给定一个 3叉树 :
		图片：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png	
	我们应返回其最大深度，3。	
	说明:	
		树的深度不会超过 1000。
		树的节点总不会超过 5000。
 */
public class MaximumDepthofN_aryTree {
	public static void main(String[] args) {
		Node root = new Node(1, new ArrayList<Node>());
		Node node3 = new Node(3, new ArrayList<Node>());
		Node node2 = new Node(2, new ArrayList<Node>());
		Node node4 = new Node(4, new ArrayList<Node>());
		Node node5 = new Node(5, new ArrayList<Node>());
		Node node6 = new Node(6, new ArrayList<Node>());
		root.children.add(node3);
		root.children.add(node2);
		root.children.add(node4);
		node3.children.add(node5);
		node3.children.add(node6);

		MaximumDepthofN_aryTree mdnt = new MaximumDepthofN_aryTree();
		System.out.println(mdnt.maxDepth(root));
	}

	// 559. N叉树的最大深度
	public int maxDepth(Node root) {
		if (root == null) {
			return 0;
		}
		int result = 1;
		return getmaxDepth(root, 1, result);
	}

	// 自顶向下
	private int getmaxDepth(Node root, int depth, int result) {
		for (Node node : root.children) {
			result = Math.max(result, getmaxDepth(node, depth + 1, result));
		}
		return Math.max(result, depth);
	}

	// 迭代
	public int maxDepth0(Node root) {
		if (root == null) {
			return 0;
		}
		Queue<Node> queue = new LinkedList<Node>();
		queue.offer(root);
		int depth = 0;
		while (!queue.isEmpty()) {
			int size = queue.size();

			for (int i = 0; i < size; i++) {
				Node current = queue.poll();
				for (Node child : current.children) {
					queue.offer(child);
				}
			}
			depth++;
		}
		return depth;
	}
}
