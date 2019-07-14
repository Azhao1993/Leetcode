package Leetcode_1123_LowestCommonAncestorofDeepestLeaves;

import TreeNode.TreeNode;

/*
	给你一个有根节点的二叉树，找到它最深的叶节点的最近公共祖先。
	
	回想一下：	
	叶节点 是二叉树中没有子节点的节点
	树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
	如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。
	 
	
	示例 1：	
		输入：root = [1,2,3]
		输出：[1,2,3]
	示例 2：	
		输入：root = [1,2,3,4]
		输出：[4]
	示例 3：	
		输入：root = [1,2,3,4,5]
		输出：[2,4,5]
	 
	
	提示：	
		给你的树中将有 1 到 1000 个节点。
		树中每个节点的值都在 1 到 1000 之间。
 */

//1123.节点的最近公共祖先
public class LowestCommonAncestorofDeepestLeaves {
	class ResultType {
		TreeNode result;
		int maxLevel;

		ResultType(TreeNode result, int maxLevel) {
			this.result = result;
			this.maxLevel = maxLevel;
		}
	}

	public TreeNode lcaDeepestLeaves(TreeNode root) {
		if (root == null) {
			return root;
		}
		ResultType resType = helper(root, 0);
		return resType.result;
	}

	private ResultType helper(TreeNode root, int level) {
		if (root == null) {
			return null;
		}
		ResultType left = helper(root.left, level + 1);
		ResultType right = helper(root.right, level + 1);
		if (left == null && right == null) {
			return new ResultType(root, level);
		} else if (left == null) {
			return right;
		} else if (right == null) {
			return left;
		} else {
			if (left.maxLevel > right.maxLevel) {
				return left;
			} else if (left.maxLevel < right.maxLevel) {
				return right;
			} else {
				return new ResultType(root, left.maxLevel);
			}
		}

	}
}
