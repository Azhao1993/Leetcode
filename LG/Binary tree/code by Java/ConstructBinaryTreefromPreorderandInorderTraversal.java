package Leetcode_105_ConstructBinaryTreefromPreorderandInorderTraversal;

import TreeNode.TreeNode;

/*
	根据一棵树的前序遍历与中序遍历构造二叉树。
	
	注意:
		你可以假设树中没有重复的元素。
	
	例如，给出	
		前序遍历 preorder = [3,9,20,15,7]
		中序遍历 inorder = [9,3,15,20,7]
		返回如下的二叉树：		
		    3
		   / \
		  9  20
		    /  \
		   15   7
 */
public class ConstructBinaryTreefromPreorderandInorderTraversal {
	public static void main(String[] args) {
		int[] preorder = { 1, 2, 3 };
		int[] inorder = { 2, 3, 1 };
		ConstructBinaryTreefromPreorderandInorderTraversal cbtpit = new ConstructBinaryTreefromPreorderandInorderTraversal();
		cbtpit.buildTree(preorder, inorder);
	}

	// 105. 从前序与中序遍历序列构造二叉树
	public TreeNode buildTree(int[] preorder, int[] inorder) {
		return build(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
	}

	// 前序遍历的第一个值为根节点
	public TreeNode build(int[] preorder, int[] inorder, int pre_left, int pre_right, int in_left, int in_right) {
		if (in_left > in_right) {
			return null;
		} else {
			// 根节点
			int rootVal = preorder[pre_left];
			TreeNode root = new TreeNode(rootVal);
			int rootIndex = 0;
			for (int i = in_right; i >= in_left; i--) {
				if (inorder[i] == rootVal) {
					rootIndex = i;
					break;
				}
			}
			root.left = build(preorder, inorder, pre_left + 1, pre_left + rootIndex - in_left, in_left, rootIndex - 1);
			root.right = build(preorder, inorder, pre_right - (in_right - rootIndex) + 1, pre_right, rootIndex + 1,
					in_right);
			return root;
		}

	}

	// 1ms
	public TreeNode buildTree0(int[] preorder, int[] inorder) {
		if (preorder.length == 0) {
			return null;
		}
		return func(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
	}

	private TreeNode func(int[] preorder, int[] inorder, int begin1, int end1, int begin2, int end2) {
		if (begin1 == preorder.length) {
			return null;
		}
		TreeNode root = new TreeNode(preorder[begin1]);
		if (begin1 == end1) {
			return root;
		}

		for (int index = end2; index >= begin2; index--) {
			if (preorder[begin1] == inorder[index]) {
				int length = index - begin2;
				root.left = func(preorder, inorder, begin1 + 1, begin1 + length, begin2, index - 1);
				root.right = func(preorder, inorder, begin1 + length + 1, end1, index + 1, end2);
				return root;
			}
		}
		return null;
	}
}
