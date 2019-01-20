package Leetcode_590_N_aryTreePostorderTraversal;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

import Node.Node;

/*
	给定一个 N 叉树，返回其节点值的后序遍历。
	
	例如，给定一个 3叉树 : 
		图片：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png
	返回其后序遍历: [5,6,3,2,4,1].
 */
public class N_aryTreePostorderTraversal {
	// 590. N叉树的后序遍历

	// 递归
	List<Integer> list = new ArrayList<Integer>();

	public List<Integer> postorder(Node root) {
		if (root == null) {
			return list;
		}
		for (Node temp : root.children) {
			list = postorder(temp);
		}
		list.add(root.val);
		return list;
	}

	// 迭代
	public List<Integer> postorder2(Node root) {
		List<Integer> result = new ArrayList<>();
		if (root == null) {
			return result;
		}

		Stack<Node> stack = new Stack<Node>();
		stack.add(root);

		while (!stack.isEmpty()) {
			root = stack.pop();
			result.add(root.val);
			for (Node node : root.children) {
				stack.add(node);
			}
		}
		Collections.reverse(result);
		return result;
	}
}
