package Leetcode_5031_RecoveraTreeFromPreorderTraversal;

import java.util.ArrayList;
import java.util.Stack;

import TreeNode.TreeNode;

/*
	我们从二叉树的根节点 root 开始进行深度优先搜索。	
	在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。
	（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。
	
	如果节点只有一个子节点，那么保证该子节点为左子节点。	
	给出遍历输出 S，还原树并返回其根节点 root。 
	
	示例 1：	
		输入："1-2--3--4-5--6--7"
		输出：[1,2,5,3,4,6,7]
	示例 2：	
		输入："1-2--3---4-5--6---7"
		输出：[1,2,5,3,null,6,null,4,null,7]
	示例 3：	
		输入："1-401--349---90--88"
		输出：[1,401,null,349,88,90] 
	
	提示：	
		原始树中的节点数介于 1 和 1000 之间。
		每个节点的值介于 1 和 10 ^ 9 之间。
 */

//5031.从先序遍历还原二叉树
public class RecoveraTreeFromPreorderTraversal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String S = "1-2--3--4-5--6--7";
		RecoveraTreeFromPreorderTraversal rtfpt = new RecoveraTreeFromPreorderTraversal();
		rtfpt.recoverFromPreorder(S);

	}

	public TreeNode recoverFromPreorder(String S) {
		int[] headarr = getNum(0, S);
		TreeNode head = new TreeNode(headarr[0]);
		Stack<TreeNode> stack = new Stack<>();
		stack.push(head);
		// int lastheight = 0;
		ArrayList<Integer> lastheight = new ArrayList<>();
		lastheight.add(0);
		int begin = headarr[1];
		process(begin, head, S, stack, lastheight);
		return head;

	}

	public void process(int begin, TreeNode head, String S, Stack<TreeNode> stack, ArrayList<Integer> lastheight) {
		// 获取层数
		int[] heightarr = getHeight(begin, S);
		if (heightarr == null) {
			return;
		}
		int height = heightarr[0];
		begin = heightarr[1];
		// 获取数字
		int[] numarr = getNum(begin, S);
		int num = numarr[0];
		TreeNode newNode = new TreeNode(num);
		begin = numarr[1];
		int lasth = lastheight.get(lastheight.size() - 1);
		while (lasth > height) {
			stack.pop();
			lastheight.remove(lastheight.size() - 1);
			lasth = lastheight.get(lastheight.size() - 1);
		}
		if (lasth == height - 1) {
			TreeNode node = stack.peek();
			node.left = newNode;
		}

		if (lasth == height) {
			stack.pop();
			lastheight.remove(lastheight.size() - 1);
			TreeNode node = stack.peek();
			node.right = newNode;
		}

		stack.add(newNode);
		lastheight.add(height);
		process(begin, head, S, stack, lastheight);

	}

	// getNum
	public int[] getNum(int begin, String S) {
		int i = begin;
		for (; i < S.length(); i++) {
			if (!isNum(S.charAt(i))) {
				break;
			}
		}
		return new int[] { Integer.parseInt(S.substring(begin, i)), i };
	}

	// getHeight
	public int[] getHeight(int begin, String S) {
		if (begin == S.length()) {
			return null;
		}
		int i = begin;
		for (; i < S.length(); i++) {
			if (isNum(S.charAt(i))) {
				break;
			}
		}
		return new int[] { i - begin, i };
	}

	public boolean isNum(char ch) {
		if (ch >= '0' && ch <= '9') {
			return true;
		} else {
			return false;
		}
	}

}
