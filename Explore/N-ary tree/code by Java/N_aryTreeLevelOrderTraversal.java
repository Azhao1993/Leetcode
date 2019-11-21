package Leetcode_429_N_aryTreeLevelOrderTraversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import Node.Node;

/*
	给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
	
	例如，给定一个 3叉树 :
	图片：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png	 
	
	返回其层序遍历:	
		[
		     [1],
		     [3,2,4],
		     [5,6]
		]
	
	说明:	
		树的深度不会超过 1000。
		树的节点总数不会超过 5000。
 */
public class N_aryTreeLevelOrderTraversal {
	// 429. N叉树的层序遍历
	// 递归
	public List<List<Integer>> levelOrder(Node root) {
		List<List<Integer>> list = new ArrayList<List<Integer>>();
		function(root, list, 0);
		return list;
	}

	private void function(Node root, List<List<Integer>> list, int level) {
		if (root == null) {
			return;
		}
		if (list.size() <= level) {
			list.add(new ArrayList<Integer>());
		}
		list.get(level).add(root.val);
		for (Node node : root.children) {
			function(node, list, level + 1);
		}
	}

	// 迭代
	public List<List<Integer>> levelOrder2(Node root) {
		List<List<Integer>> ret = new LinkedList<>();

		if (root == null) {
			return ret;
		}

		Queue<Node> queue = new LinkedList<Node>();

		queue.offer(root);

		while (!queue.isEmpty()) {
			// 每一层的结果
			List<Integer> curLevel = new LinkedList<Integer>();
			// 每一层的长度
			int len = queue.size();
			// 遍历每一层
			for (int i = 0; i < len; i++) {
				Node curr = queue.poll();
				curLevel.add(curr.val);
				for (Node c : curr.children) {
					queue.offer(c);
				}
			}
			ret.add(curLevel);
		}
		return ret;
	}
}
