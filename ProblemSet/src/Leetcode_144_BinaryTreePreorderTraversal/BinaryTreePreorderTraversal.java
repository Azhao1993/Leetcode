package Leetcode_144_BinaryTreePreorderTraversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

import TreeNode.TreeNode;

/*
	给定一个二叉树，返回它的 前序 遍历。
	
	前序遍历：
		根节点，左子树，右子树。
	
	 示例:	
		输入: [1,null,2,3]  
		   1
		    \
		     2
		    /
		   3 
		
		输出: [1,2,3]
	进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */
public class BinaryTreePreorderTraversal {
	// 144. 二叉树的前序遍历
	// 递归
	List<Integer> res = new ArrayList<Integer>();// 全局变量

	public List<Integer> preorderTraversal0(TreeNode root) {
		loop(root);
		return res;
	}

	public void loop(TreeNode root) {
		if (root == null) {
			return;
		}
		res.add(root.val);
		loop(root.left);
		loop(root.right);
	}

	// 迭代
	public List<Integer> preorderTraversal2(TreeNode root) {
		Stack<TreeNode> stack = new Stack<>();
		List<Integer> res = new ArrayList<>();
		if (root == null) {
			return res;
		}
		stack.push(root);

		while (!stack.isEmpty()) {
			TreeNode temp = stack.pop();
			res.add(temp.val);
			if (temp.right != null) {
				stack.push(temp.right);
			}
			if (temp.left != null) {
				stack.push(temp.left);
			}
		}
		return res;
	}

}
