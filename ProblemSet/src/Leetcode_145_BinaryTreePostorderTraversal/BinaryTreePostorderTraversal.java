package Leetcode_145_BinaryTreePostorderTraversal;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import TreeNode.TreeNode;

/*
	给定一个二叉树，返回它的 后序 遍历。
	后序遍历：
		左子树，右子树，根节点
	
	示例:	
		输入: [1,null,2,3]  
		   1
		    \
		     2
		    /
		   3 
		
		输出: [3,2,1]
	进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 */
public class BinaryTreePostorderTraversal {

	// 145. 二叉树的后序遍历
	List<Integer> list = new ArrayList<Integer>();

	public List<Integer> postorderTraversal(TreeNode root) {
		loop(root);
		return list;
	}

	private void loop(TreeNode root) {
		if (root == null) {
			return;
		}

		loop(root.left);
		loop(root.right);
		list.add(root.val);

	}

	// 迭代
	public List<Integer> postorderTraversal2(TreeNode root) {
		List<Integer> results = new ArrayList<>();
		Stack<TreeNode> stack = new Stack<>();

		TreeNode cur = root;
		TreeNode last = null;
		while (cur != null || !stack.empty()) {
			while (cur != null) {
				stack.push(cur);
				cur = cur.left;
			}
			cur = stack.peek();
			if (cur.right == null || cur.right == last) {
				results.add(cur.val);
				stack.pop();
				// 记录上一个访问的节点
				// 用于判断“访问根节点之前，右子树是否已访问过”
				last = cur;
				// 表示不需要转向，继续弹栈
				cur = null;
			} else {
				cur = cur.right;
			}
		}

		return results;
	}

	// 0ms
	public List<Integer> postorderTraversal0(TreeNode root) {
		List<Integer> res = new ArrayList<>();
		pos(root, res);
		return res;
	}

	public void pos(TreeNode root, List<Integer> res) {
		if (root == null) {
			return;
		}
		pos(root.left, res);
		pos(root.right, res);
		res.add(root.val);
	}
}
