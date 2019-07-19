package Leetcode_230_KthSmallestElementinaBST;

import TreeNode.TreeNode;
import TreeNode.TreeNodeUtils;

/*
	给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
	
	说明：
		你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
	
	示例 1:	
		输入: root = [3,1,4,null,2], k = 1
		   3
		  / \
		 1   4
		  \
		   2
		输出: 1
	示例 2:	
		输入: root = [5,3,6,2,4,null,null,1], k = 3
			       5
			      / \
			     3   6
			    / \
			   2   4
			  /
			 1
		输出: 3
	进阶：
		如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
 */

//230.二叉搜索树中第K小的元素
public class KthSmallestElementinaBST {
	public static void main(String[] args) {
		String[] arr = { "3", "1", "4", "null", "2" };
		TreeNode root = TreeNodeUtils.createTree(arr);
		TreeNodeUtils.printTree(root);
		new KthSmallestElementinaBST().kthSmallest(root, 1);
	}

	public int kthSmallest(TreeNode root, int k) {
		int[] res = new int[2];
		// res[0]当前已经遍历了多少节点
		// res[1]第k个值是多少
		traverse(root, k, res);
		return res[1];
	}

	// 中序遍历，查找记录左子树有多少个节点
	public void traverse(TreeNode root, int k, int[] res) {
		if (root == null) {
			return;
		}

		// 判断加速
		if (res[0] < k) {
			traverse(root.left, k, res);
			res[0]++;
			if (res[0] == k) {
				res[1] = root.val;
				return;
			}
			traverse(root.right, k, res);
		}

	}
}
