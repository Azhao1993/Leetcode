package Leetcode_144_BinaryTreePreorderTraversal;

import TreeNode.TreeNode;

public class BinaryTreePreorderTraversalTest {

	public static void main(String[] args) {
		BinaryTreePreorderTraversal btpt = new BinaryTreePreorderTraversal();
		TreeNode root = new TreeNode(3);
		TreeNode node2 = new TreeNode(1);
		TreeNode node3 = new TreeNode(2);
		root.right = node2;
		node2.left = node3;
		for (int val : btpt.preorderTraversal2(root)) {
			System.out.println(val);
		}

	}

}
