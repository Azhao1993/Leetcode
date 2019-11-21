package Leetcode_103_BinaryTreeZigzagLevelOrderTraversal;

import java.util.ArrayList;
import java.util.List;

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
