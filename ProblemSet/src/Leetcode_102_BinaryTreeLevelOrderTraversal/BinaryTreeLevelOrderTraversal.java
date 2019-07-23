package Leetcode_102_BinaryTreeLevelOrderTraversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import TreeNode.TreeNode;
import javafx.util.Pair;

/*
	给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
	
	例如:
		给定二叉树: [3,9,20,null,null,15,7],
		
		    3
		   / \
		  9  20
		    /  \
		   15   7
		   
		返回其层次遍历结果：		
			[
			  [3],
			  [9,20],
			  [15,7]
			]
 */
public class BinaryTreeLevelOrderTraversal {
	// 102. 二叉树的层次遍历
	public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		if (root == null) {
			return res;
		}

		Queue<List<TreeNode>> queue = new LinkedList<List<TreeNode>>();
		List<TreeNode> nodelist = new ArrayList<TreeNode>();
		nodelist.add(root);
		queue.offer(nodelist);
		List<Integer> valList = new ArrayList<Integer>();
		valList.add(root.val);
		res.add(valList);
		while (!queue.isEmpty()) {
			List<TreeNode> nextNodeList = new ArrayList<TreeNode>();
			List<Integer> nextValList = new ArrayList<Integer>();
			for (TreeNode cur : queue.peek()) {
				if (cur.left != null) {
					nextNodeList.add(cur.left);
					nextValList.add(cur.left.val);
				}
				if (cur.right != null) {
					nextNodeList.add(cur.right);
					nextValList.add(cur.right.val);
				}
			}
			if (!nextNodeList.isEmpty()) {
				queue.offer(nextNodeList);
				res.add(nextValList);
			}
			queue.poll();
		}
		return res;

	}

	// 递归
	public List<List<Integer>> levelOrder0(TreeNode root) {
		List<List<Integer>> list = new ArrayList<List<Integer>>();
		function(root, list, 0);
		return list;
	}

	public void function(TreeNode node, List<List<Integer>> list, int level) {
		if (node == null) {
			return;
		}
		if (list.size() <= level) {
			list.add(new ArrayList<Integer>());
		}
		list.get(level).add(node.val);
		function(node.left, list, level + 1);
		function(node.right, list, level + 1);
	}

	// 迭代
	class TreeNodeWithLevel {
		int level;
		TreeNode node;

		public TreeNodeWithLevel(int level, TreeNode node) {
			this.level = level;
			this.node = node;
		}
	}

	public List<List<Integer>> levelOrder2(TreeNode root) {
		List<List<Integer>> list = new ArrayList<List<Integer>>();
		Queue<TreeNodeWithLevel> queue = new LinkedList<>();
		queue.add(new TreeNodeWithLevel(0, root));
		while (!queue.isEmpty()) {
			TreeNodeWithLevel cur = queue.poll();
			if (cur.level == list.size()) {
				List<Integer> temp = new ArrayList<>();
				list.add(temp);
			}
			list.get(cur.level).add(cur.node.val);

			if (cur.node.left != null) {
				queue.add(new TreeNodeWithLevel(cur.level + 1, cur.node.left));
			}

			if (cur.node.right != null) {
				queue.add(new TreeNodeWithLevel(cur.level + 1, cur.node.right));
			}
		}
		return list;
	}

}
