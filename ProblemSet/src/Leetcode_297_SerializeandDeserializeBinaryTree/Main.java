package Leetcode_297_SerializeandDeserializeBinaryTree;

import TreeNode.TreeNode;

public class Main {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		TreeNode root = new TreeNode(1);
		TreeNode node2 = new TreeNode(2);
		TreeNode node3 = new TreeNode(3);
		TreeNode node4 = new TreeNode(4);
		TreeNode node5 = new TreeNode(5);
		TreeNode node6 = new TreeNode(6);
		TreeNode node7 = new TreeNode(7);
		TreeNode node8 = new TreeNode(8);
		TreeNode node9 = new TreeNode(9);
		root.left = node2;
		root.right = node7;
		node2.left = node3;
		node2.right = node4;
		node4.left = node5;
		node4.right = node6;
		node7.right = node8;
		node8.left = node9;
		String result = new Codec().serialize(root);
		System.out.println(result);
		new Codec().deserialize(result);

	}

}
