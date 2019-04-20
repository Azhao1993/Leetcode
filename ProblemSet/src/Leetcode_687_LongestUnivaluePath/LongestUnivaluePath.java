package Leetcode_687_LongestUnivaluePath;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

import TreeNode.TreeNode;

/*
	给定一个二叉树，找到最长的路径，
	这个路径中的每个节点具有相同值。 
	这条路径可以经过也可以不经过根节点。

	注意：两个节点之间的路径长度由它们之间的边数表示。
	
	Example 1:	
		Input:
		
		              5
		             / \
		            4   5
		           / \   \
		          1   1   5
		Output: 2	 
	
	Example 2:	
		Input:
		
		              1
		             / \
		            4   5
		           / \   \
		          4   4   5
		Output: 2 
	
	注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000.
 */
// 687. 最长同值路径
public class LongestUnivaluePath {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(1);
		TreeNode node24 = new TreeNode(4);
		TreeNode node25 = new TreeNode(5);
		TreeNode node34 = new TreeNode(4);
		TreeNode node324 = new TreeNode(4);
		TreeNode node35 = new TreeNode(5);
		root.left = node24;
		root.right = node25;
		node24.left = node34;
		node24.right = node324;
		node25.right = node35;
		LongestUnivaluePath lup = new LongestUnivaluePath();
		System.out.println(lup.longestUnivaluePath(root));

	}

	public int longestUnivaluePath(TreeNode root) {
		if (root == null || (root.left == null && root.right == null)) {
			return 0;
		}
		// 遍历
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		// 节点信息
		HashMap<TreeNode, int[]> map = new HashMap<>();
		int res = 0;
		queue.add(root);
		while (!queue.isEmpty()) {
			TreeNode curNode = queue.poll();
			int curres = 0;
			if (curNode.left != null) {
				queue.add(curNode.left);
			}
			if (curNode.right != null) {
				queue.add(curNode.right);
			}
			process(curNode, map);
			int left = map.get(curNode)[0];
			int right = map.get(curNode)[1];
			if (left != 0 && right != 0) {
				curres = left + right;
			} else {
				curres = Math.max(left, right);
			}
			res = Math.max(res, curres);

		}
		return res;
	}

	private int process(TreeNode curNode, HashMap<TreeNode, int[]> map) {
		// 终止条件
		if (curNode == null) {
			return 0;
		}
		// 当前接点的val
		int val = curNode.val;
		// 结果
		int res = 0;
		// 左子树结果
		int left = 0;
		// 右子树结果
		int right = 0;
		if (map.containsKey(curNode)) {
			left = map.get(curNode)[0];
			right = map.get(curNode)[1];
			res = Math.max(left + 1, right + 1);
			return res;
		}

		if (curNode.left != null && curNode.left.val == val) {
			left = process(curNode.left, map);
		}
		if (curNode.right != null && curNode.right.val == val) {
			right = process(curNode.right, map);
		}
		map.put(curNode, new int[] { left, right });
		res = Math.max(left + 1, right + 1);
		return res;
	}

	// clean
	public int longestUnivaluePath0(TreeNode root) {
		// 全局变量res
		int[] res = new int[1];
		if (root != null)
			dfs(root, res);
		return res[0];
	}

	private int dfs(TreeNode node, int[] res) {
		// 可能在左子树
		int l = node.left != null ? dfs(node.left, res) : 0;
		// 可能在右子树
		int r = node.right != null ? dfs(node.right, res) : 0;
		// 左子树+当前节点
		int resl = node.left != null && node.left.val == node.val ? l + 1 : 0;
		// 右子树+当前节点
		int resr = node.right != null && node.right.val == node.val ? r + 1 : 0;
		// 更新全局结果
		res[0] = Math.max(res[0], resl + resr);
		// 将结果返回给上一层
		return Math.max(resl, resr); 
	}
}
