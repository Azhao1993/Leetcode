package Leetcode_103_BinaryTreeZigzagLevelOrderTraversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import TreeNode.TreeNode;

/*
	给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
	
	例如：
		给定二叉树 [3,9,20,null,null,15,7],	
			    3
			   / \
			  9  20
			    /  \
			   15   7
		返回锯齿形层次遍历如下：	
			[
			  [3],
			  [20,9],
			  [15,7]
			]
 */

//103.二叉树的锯齿形层次遍历
public class BinaryTreeZigzagLevelOrderTraversal {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(3);
		TreeNode node9 = new TreeNode(9);
		TreeNode node20 = new TreeNode(20);
		TreeNode node15 = new TreeNode(15);
		TreeNode node7 = new TreeNode(7);
		root.left = node9;
		root.right = node20;
		node20.left = node15;
		node20.right = node7;
		BinaryTreeZigzagLevelOrderTraversal btzlot = new BinaryTreeZigzagLevelOrderTraversal();
		btzlot.zigzagLevelOrder(root);

	}

	// 2 ms 35.6 MB
	public List<List<Integer>> zigzagLevelOrder2(TreeNode root) {
		List<List<Integer>> res = new ArrayList<>();
		if (root == null) {
			return res;
		}
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		boolean flag = true;
		while (!queue.isEmpty()) {
			int size = queue.size();
			LinkedList<Integer> list = new LinkedList<>();
			for (int i = 0; i < size; i++) {
				TreeNode cur = queue.poll();
				if (flag) {
					list.addLast(cur.val);
				} else {
					list.addFirst(cur.val);
				}
				if (cur.left != null) {
					queue.add(cur.left);
				}

				if (cur.right != null) {
					queue.add(cur.right);
				}
			}
			res.add(list);
			flag = !flag;
		}
		return res;

	}

	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		zigzagLevelOrder(result, 1, root);
		return result;
	}

	private void zigzagLevelOrder(List<List<Integer>> result, int level, TreeNode root) {
		if (root == null) {
			return;
		}
		if (level > result.size()) {
			result.add(new ArrayList<Integer>());
		}
		if (level % 2 == 1) {
			result.get(level - 1).add(root.val);
		} else {
			result.get(level - 1).add(0, root.val);
		}

		zigzagLevelOrder(result, level + 1, root.left);
		zigzagLevelOrder(result, level + 1, root.right);

	}
}
