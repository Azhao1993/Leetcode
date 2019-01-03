package Leetcode_102_BinaryTreeLevelOrderTraversal;

import TreeNode.TreeNode;

public class BinaryTreeLevelOrderTraversalTest {

	public static void main(String[] args) {
		BinaryTreeLevelOrderTraversal btlot = new BinaryTreeLevelOrderTraversal();
		TreeNode root = new TreeNode(3);
		TreeNode node9 = new TreeNode(9);
		TreeNode node20 = new TreeNode(20);
		TreeNode node15 = new TreeNode(15);
		TreeNode node7 = new TreeNode(7);
		root.left = node9;
		root.right = node20;
		node20.left = node15;
		node20.right= node7;
		btlot.levelOrder(root);

	}

}
