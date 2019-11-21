package Leetcode_701_InsertintoaBinarySearchTree;

import TreeNode.TreeNode;

/*
	给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 
	返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。
	
	注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。
	 你可以返回任意有效的结果。
	
	例如, 	
		给定二叉搜索树:
		
		        4
		       / \
		      2   7
		     / \
		    1   3
		
		和 插入的值: 5
		你可以返回这个二叉搜索树:
		
		         4
		       /   \
		      2     7
		     / \   /
		    1   3 5
		或者这个树也是有效的:
		
		         5
		       /   \
		      2     7
		     / \   
		    1   3
		         \
		          4
 */
public class InsertintoaBinarySearchTree {
	// 701. 二叉搜索树中的插入操作
	public TreeNode insertIntoBST(TreeNode root, int val) {
		TreeNode insertNode = new TreeNode(val);
		inserIntoBST(root, val, insertNode);
		return root;
	}

	private void inserIntoBST(TreeNode root, int val, TreeNode insertNode) {
		if (root.val < val) {
			if (root.right != null) {
				inserIntoBST(root.right, val, insertNode);
			} else {
				root.right = insertNode;
				return;
			}
		} else {
			if (root.left != null) {
				inserIntoBST(root.left, val, insertNode);
			} else {
				root.left = insertNode;
				return;
			}
		}
	}
}
