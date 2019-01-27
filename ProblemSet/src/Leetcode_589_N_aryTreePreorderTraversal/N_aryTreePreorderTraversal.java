package Leetcode_589_N_aryTreePreorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import Node.Node;

/*
	给定一个 N 叉树，返回其节点值的前序遍历。	
	例如，给定一个 3叉树 :	 
	图片：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png
	返回其前序遍历: [1,3,5,6,2,4]。	 
	
	说明: 递归法很简单，你可以使用迭代法完成此题吗?
 */
public class N_aryTreePreorderTraversal {
	public static void main(String[] args) {
		Node root = new Node(1, new ArrayList<Node>());
		Node node3 = new Node(3, new ArrayList<Node>());
		Node node2 = new Node(2, new ArrayList<Node>());
		Node node4 = new Node(4, new ArrayList<Node>());
		Node node5 = new Node(5, new ArrayList<Node>());
		Node node6 = new Node(6, new ArrayList<Node>());
		root.children.add(node4);
		root.children.add(node2);
		root.children.add(node3);
		node3.children.add(node6);
		node3.children.add(node5);
		N_aryTreePreorderTraversal ntpt = new N_aryTreePreorderTraversal();
		ntpt.preorder(root);
	}

	// 589. N叉树的前序遍历
	// 递归
	List<Integer> list = new ArrayList<Integer>();

	public List<Integer> preorder(Node root) {
		if (root == null) {
			return list;
		}
		list.add(root.val);
		for (Node temp : root.children) {
			list = preorder(temp);
		}
		return list;
	}

	// 迭代
	public List<Integer> preorder2(Node root) {
		List<Integer> list = new ArrayList<>();
		if (root == null) {
			return list;
		}

		Stack<Node> stack = new Stack<>();
		stack.add(root);

		while (!stack.empty()) {
			root = stack.pop();
			list.add(root.val);
			for (int i = root.children.size() - 1; i >= 0; i--)
				stack.add(root.children.get(i));
		}

		return list;
	}
}
