package Leetcode_104_MaximumDepthofBinaryTree;

import org.w3c.dom.Node;

import TreeNode.TreeNode;

/*
	给定一个二叉树，找出其最大深度。	
	二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。	
	说明: 叶子节点是指没有子节点的节点。
	
	示例：
		给定二叉树 [3,9,20,null,null,15,7]，
		
		    3
		   / \
		  9  20
		    /  \
		   15   7
		返回它的最大深度 3 。
 */
public class MaximumDepthofBinaryTree {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(3);
		TreeNode node9 = new TreeNode(9);
		TreeNode node20 = new TreeNode(20);
		TreeNode node15 = new TreeNode(15);
		TreeNode node7 = new TreeNode(7);
		root.left = node9;
		root.right = node20;
		node20.left = node15;
		node20.right = node7;
		MaximumDepthofBinaryTree mdb = new MaximumDepthofBinaryTree();
		System.out.println(mdb.maxDepth(root));

	}

	// 104. 二叉树的最大深度
	public int maxDepth(TreeNode root) {
		int depth = 0;
		int result = 0;
		if (root == null) {
			return 0;
		}
		return getMaxDepth(root, depth + 1, result);
	}

	private int getMaxDepth(TreeNode root, int depth, int result) {
		if (root == null) {
			return result;
		}

		if (root.left == null && root.right == null) {
			result = Math.max(result, depth);
			return result;
		}

		result = getMaxDepth(root.left, depth + 1, result);
		result = getMaxDepth(root.right, depth + 1, result);
		return result;
	}

	// 0ms
	public int maxDepth0(TreeNode root) {
		return root == null ? 0 : Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
	}

}
