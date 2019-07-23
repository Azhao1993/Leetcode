package Leetcode_113_PathSumII;

import java.util.ArrayList;
import java.util.List;

import TreeNode.TreeNode;

/*
	给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。	
	说明: 叶子节点是指没有子节点的节点。
	
	示例:
		给定如下二叉树，以及目标和 sum = 22，
		
		              5
		             / \
		            4   8
		           /   / \
		          11  13  4
		         /  \    / \
		        7    2  5   1
	返回:	
		[
		   [5,4,11,2],
		   [5,8,4,5]
		]
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/path-sum-ii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class PathSumII {
	// 113. 路径总和 II
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		List<List<Integer>> res = new ArrayList<>();
		if (root == null) {
			return res;
		}

		if (root.left == null && root.right == null && root.val == sum) {
			List<Integer> temp = new ArrayList<>();
			temp.add(root.val);
			res.add(temp);
			return res;
		}

		List<List<Integer>> left = pathSum(root.left, sum - root.val);

		for (int i = 0; i < left.size(); i++) {
			List<Integer> temp = new ArrayList<>();
			temp.add(root.val);
			temp.addAll(left.get(i));
			res.add(temp);
		}

		List<List<Integer>> right = pathSum(root.right, sum - root.val);
		for (int i = 0; i < right.size(); i++) {
			List<Integer> temp = new ArrayList<>();
			temp.add(root.val);
			temp.addAll(right.get(i));
			res.add(temp);
		}
		return res;
	}

	// DFS+回溯
	public List<List<Integer>> pathSum2(TreeNode root, int sum) {
		List<List<Integer>> res = new ArrayList<>();
		List<Integer> path = new ArrayList<>();
		dfs(root, sum, res, path);
		return res;
	}

	public void dfs(TreeNode root, int sum, List<List<Integer>> res, List<Integer> path) {
		if (root == null)
			return;
		path.add(root.val);

		if (root.left == null && root.right == null) {
			if (root.val == sum)
				res.add(new ArrayList<Integer>(path));
			return;
		}
		if (root.left != null) {
			dfs(root.left, sum - root.val, res, path);
			path.remove(path.size() - 1);
		}
		if (root.right != null) {
			dfs(root.right, sum - root.val, res, path);
			path.remove(path.size() - 1);
		}

	}
}
