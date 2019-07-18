package Leetcode_235_LowestCommonAncestorofaBinarySearchTree;

import TreeNode.TreeNode;

/*
	给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
	
	百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
	
	例如，给定如下二叉搜索树:  
		root = [6,2,8,0,4,7,9,null,null,3,5]	
		图片：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png	 
	
	示例 1:	
		输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
		输出: 6 
		解释: 节点 2 和节点 8 的最近公共祖先是 6。
	示例 2:	
		输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
		输出: 2
		解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 */
public class LowestCommonAncestorofaBinarySearchTree {
	// 235. 二叉搜索树的最近公共祖先
	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		if (root == null) {
			return null;
		}
		if (p.val > root.val && q.val > root.val) {
			return lowestCommonAncestor(root.right, p, q);
		}
		if (p.val < root.val && q.val < root.val) {
			return lowestCommonAncestor(root.left, p, q);
		}
		return root;
	}

	// 5ms
	public TreeNode lowestCommonAncestor0(TreeNode root, TreeNode p, TreeNode q) {
		if (root == null)
			return null;
		// 要么在左子树，要么在右子树，要么就是根节点
		while (root != null) {
			if (p.val > root.val && q.val > root.val)
				root = root.right;
			else if (p.val < root.val && q.val < root.val)
				root = root.left;
			else
				return root;
		}
		return root;
	}
}
