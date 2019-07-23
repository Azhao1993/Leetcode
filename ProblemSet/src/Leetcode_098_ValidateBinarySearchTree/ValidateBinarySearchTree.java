package Leetcode_098_ValidateBinarySearchTree;

import java.util.ArrayList;
import java.util.List;

import TreeNode.TreeNode;

/*
	给定一个二叉树，判断其是否是一个有效的二叉搜索树。
	
	假设一个二叉搜索树具有如下特征：	
		节点的左子树只包含小于当前节点的数。
		节点的右子树只包含大于当前节点的数。
		所有左子树和右子树自身必须也是二叉搜索树。
	示例 1:	
		输入:
			    2
			   / \
			  1   3
		输出: true
	示例 2:	
		输入:
			    5
			   / \
			  1   4
			     / \
			    3   6
		输出: false
	解释: 
		输入为: [5,1,4,null,null,3,6]。
		根节点的值为 5 ，但是其右子节点值为 4 。
 */
public class ValidateBinarySearchTree {
	public static void main(String[] args) {
//		TreeNode root = new TreeNode(5);
//		TreeNode node1 = new TreeNode(1);
//		TreeNode node4 = new TreeNode(4);
//		TreeNode node3 = new TreeNode(3);
//		TreeNode node6 = new TreeNode(6);
//		root.left = node1;
//		root.right = node4;
//		node4.left = node3;
//		node4.right = node6;
		TreeNode root = new TreeNode(2);
		TreeNode node1 = new TreeNode(1);
		TreeNode node3 = new TreeNode(3);
		root.left = node1;
		root.right = node3;
		ValidateBinarySearchTree vbst = new ValidateBinarySearchTree();
		vbst.isValidBST0(root);
	}

	// 98. 验证二叉搜索树
	public boolean isValidBST(TreeNode root) {
		if ((root == null) || (root.left == null && root.right == null)) {
			return true;
		}
		ArrayList<Integer> list = new ArrayList<Integer>();
		list = inorder(list, root);
		for (int i = 1; i < list.size(); i++) {
			if (list.get(i) <= list.get(i - 1)) {
				return false;
			}
		}
		return true;

	}
	// 中序遍历

	private ArrayList<Integer> inorder(ArrayList<Integer> list, TreeNode root) {
		if (root == null) {
			return list;
		}
		list = inorder(list, root.left);
		list.add(root.val);
		list = inorder(list, root.right);
		return list;
	}

	// 0ms
	int last = 0;// 前驱
	boolean first = true;// flag

	public boolean isValidBST0(TreeNode node) {

		if (node == null) {
			return true;
		}
		// 查找左边
		if (!isValidBST0(node.left)) {
			return false;
		}
		// 如果是第一个根
		if (first) {
			last = node.val;
			first = false;
		} else {
			if (last >= node.val) {
				return false;
			}
			last = node.val;
		}
		// 判断右边
		if (!isValidBST0(node.right)) {
			return false;
		}
		return true;
	}

}
