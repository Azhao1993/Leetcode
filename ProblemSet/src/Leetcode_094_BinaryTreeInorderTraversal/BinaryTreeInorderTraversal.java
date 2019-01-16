package Leetcode_094_BinaryTreeInorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import TreeNode.TreeNode;

/*
	给定一个二叉树，返回它的中序 遍历。
	中序遍历：
		左子树，根节点，右子树
	
	示例:	
		输入: [1,null,2,3]
		   1
		    \
		     2
		    /
		   3
		
		输出: [1,3,2]
	进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */
public class BinaryTreeInorderTraversal {

	// 94. 二叉树的中序遍历
	List<Integer> list = new ArrayList<Integer>();

	public List<Integer> inorderTraversal(TreeNode root) {
		loop(root);
		return list;
	}

	public void loop(TreeNode root) {
		if (root == null) {
			return;
		}

		loop(root.left);
		list.add(root.val);
		loop(root.right);
	}

	// 迭代
	public List<Integer> inorderTraversal2(TreeNode root) {
	    List<Integer> results = new ArrayList<>();
	    Stack<TreeNode> stack = new Stack<TreeNode>();
	    TreeNode cur = root;
	    while (cur != null || !stack.empty()) {
	        while (cur != null) {
	            stack.push(cur);
	            cur = cur.left;
	        }
	        cur = stack.pop();
	        results.add(cur.val);
	        cur = cur.right;
	    }
	    return results;	
	}

	// 0ms
	public List<Integer> inorderTraversal0(TreeNode root) {
		List<Integer> result = new ArrayList<>();
		help(result, root);
		return result;
	}

	private static void help(List<Integer> result, TreeNode root) {
		if (root == null) {
			return;
		}
		help(result, root.left);
		result.add(root.val);
		help(result, root.right);
	}
}
