package Leetcode_450_DeleteNodeinaBST;

import TreeNode.TreeNode;

/*
	给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
	返回二叉搜索树（有可能被更新）的根节点的引用。
	
	一般来说，删除节点可分为两个步骤：	
		首先找到需要删除的节点；
		如果找到了，删除它。
	说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
	
	示例:	
		root = [5,3,6,2,4,null,7]
		key = 3
		
		    5
		   / \
		  3   6
		 / \   \
		2   4   7
	
	给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
	
	一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。	
		    5
		   / \
		  4   6
		 /     \
		2       7
	
	另一个正确答案是 [5,2,6,null,4,null,7]。	
		    5
		   / \
		  2   6
		   \   \
		    4   7
 */
public class DeleteNodeinaBST {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(5);
		TreeNode node3 = new TreeNode(3);
		TreeNode node6 = new TreeNode(6);
		TreeNode node2 = new TreeNode(2);
		TreeNode node4 = new TreeNode(4);
		TreeNode node7 = new TreeNode(7);
		root.left = node3;
		root.right = node6;
		node3.left = node2;
		node3.right = node4;
		node6.right = node7;
		DeleteNodeinaBST dnbst = new DeleteNodeinaBST();
		dnbst.deleteNode(root, 3);

	}

	// 450. 删除二叉搜索树中的节点
	public TreeNode deleteNode(TreeNode root, int key) {
		if (root == null) {
			return null;
		}
		if (key < root.val) {
			root.left = deleteNode(root.left, key);
		} else if (key > root.val) {
			root.right = deleteNode(root.right, key);
		} else {
			// left和right都不为空
			if (root.left == null) {
				return root.right;
			} else if (root.right == null) {
				return root.left;
			}

			TreeNode minNode = findMin(root.right);
			// 将右子树中最小值节点放在root位置
			root.val = minNode.val;
			// 删除右子树中的最小值节点
			root.right = deleteNode(root.right, root.val);
		}
		return root;
	}

	// 找到右子树中的最小值
	private TreeNode findMin(TreeNode node) {
		while (node.left != null) {
			node = node.left;
		}
		return node;
	}
}
