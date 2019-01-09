package Leetcode_094_BinaryTreeInorderTraversal;

import TreeNode.TreeNode;

public class BinaryTreeInorderTraversalTest {

	public static void main(String[] args) {
		BinaryTreeInorderTraversal btit = new BinaryTreeInorderTraversal();
		TreeNode root = new TreeNode(1);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		root.right = node2;
		node2.right = node3;
		for (int val : btit.inorderTraversal(root)) {
			System.out.println(val);
		}

	}

}
