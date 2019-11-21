package Leetcode_110_BalancedBinaryTree;

import TreeNode.TreeNode;

/*
	给定一个二叉树，判断它是否是高度平衡的二叉树。	
	本题中，一棵高度平衡二叉树定义为：	
		一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
	
	示例 1:	
		给定二叉树 [3,9,20,null,null,15,7]	
			    3
			   / \
			  9  20
			    /  \
			   15   7
		返回 true 。
	
	示例 2:	
		给定二叉树 [1,2,2,3,3,null,null,4,4]
		
		       1
		      / \
		     2   2
		    / \
		   3   3
		  / \
		 4   4
		返回 false 。
 */
public class BalancedBinaryTree {
	// 110. 平衡二叉树
	public boolean isBalanced(TreeNode root) {
		if (root == null) {
			return true;
		}

		int left = depth(root.left);
		int right = depth(root.right);

		return Math.abs(left - right) <= 1 && isBalanced(root.left) && isBalanced(root.right);

	}

	// 计算深度
	private int depth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		return Math.max(depth(root.left), depth(root.right)) + 1;
	}

	// DFS计算深度
	public boolean isBalanced2(TreeNode root) {
		return dfsHeight(root) != -1;
	}

	private int dfsHeight(TreeNode root) {
		if (root == null)
			return 0;

		int leftHeight = dfsHeight(root.left);
		if (leftHeight == -1) {
			return -1;
		}
		int rightHeight = dfsHeight(root.right);
		if (rightHeight == -1) {
			return -1;
		}

		if (Math.abs(leftHeight - rightHeight) > 1) {
			return -1;
		}
		return Math.max(leftHeight, rightHeight) + 1;
	}

	// 0ms
	public boolean isBalanced0(TreeNode root) {
		// -1代表左右节点的深度差超过1
		return depth0(root) != -1;
	}

	private int depth0(TreeNode root) {
		if (root == null) {
			return 0;
		}
		// left，right分别表示左、右节点的深度差是否超过1，-1表示超过
		int left = depth0(root.left);
		if (left == -1) {
			return -1;
		}
		int right = depth0(root.right);
		if (right == -1) {
			return -1;
		}
		// 左右节点深度差超过1
		if (Math.abs(left - right) > 1) {
			return -1;
		}
		// 不超过1返回最大值+1
		return Math.max(left, right) + 1;
	}

}
