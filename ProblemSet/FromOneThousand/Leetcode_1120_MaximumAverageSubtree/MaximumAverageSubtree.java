package Leetcode_1120_MaximumAverageSubtree;

import TreeNode.TreeNode;

/*
	给你一棵二叉树的根节点 root，找出这棵树的 每一棵 子树的 平均值 中的 最大 值。	
	子树是树中的任意节点和它的所有后代构成的集合。	
	树的平均值是树中节点值的总和除以节点数。	 
	
	示例：
		https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/07/12/1308_example_1.png	
		输入：[5,6,1]
		输出：6.00000
		解释： 
		以 value = 5 的节点作为子树的根节点，得到的平均值为 (5 + 6 + 1) / 3 = 4。
		以 value = 6 的节点作为子树的根节点，得到的平均值为 6 / 1 = 6。
		以 value = 1 的节点作为子树的根节点，得到的平均值为 1 / 1 = 1。
		所以答案取最大值 6。 
	
	提示：	
		树中的节点数介于 1 到 5000之间。
		每个节点的值介于 0 到 100000 之间。
		如果结果与标准答案的误差不超过 10^-5，那么该结果将被视为正确答案。
 */
public class MaximumAverageSubtree {
	// 1120. 子树的最大平均值
	double res = Double.MIN_VALUE;

	public double maximumAverageSubtree(TreeNode root) {
		dfs(root);
		return res;
	}

	private double[] dfs(TreeNode root) {
		double[] ans = new double[2];
		if (root == null) {
			return ans;
		}
		double[] left = dfs(root.left);
		double[] right = dfs(root.right);
		ans[0] = (double) root.val + left[0] + right[0];
		ans[1] = (double) 1 + left[1] + right[1];

		res = Math.max(res, ans[0] / ans[1]);

		return ans;

	}
}
