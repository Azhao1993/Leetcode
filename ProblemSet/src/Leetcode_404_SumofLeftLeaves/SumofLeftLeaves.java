package Leetcode_404_SumofLeftLeaves;

import TreeNode.TreeNode;

/*
	计算给定二叉树的所有左叶子之和。
	
	示例：	
	    3
	   / \
	  9  20
	    /  \
	   15   7
	
	在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/sum-of-left-leaves
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class SumofLeftLeaves {
	// 404. 左叶子之和
	public int sumOfLeftLeaves(TreeNode root) {
		if (root == null) {
			return 0;
		}
		int ans = 0;
		if (root.left != null) {
			// 找左叶子节点
			if (root.left.left == null && root.left.right == null) {
				ans += root.left.val;
			} else {
				ans += sumOfLeftLeaves(root.left);
			}
		}
		ans += sumOfLeftLeaves(root.right);
		return ans;

	}
}
