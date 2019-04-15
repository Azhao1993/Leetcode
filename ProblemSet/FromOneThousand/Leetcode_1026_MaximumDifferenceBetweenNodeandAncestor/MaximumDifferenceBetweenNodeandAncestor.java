package Leetcode_1026_MaximumDifferenceBetweenNodeandAncestor;

import java.util.Stack;

/*
	给定二叉树的根节点 root，
	找出存在于不同节点 A 和 B 之间的最大值 V，
	其中 V = |A.val - B.val|，且 A 是 B 的祖先。
	
	（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）
	
	 
	
	示例：	
	
	输入：[8,3,10,1,6,null,14,null,null,4,7,13]
	输出：7
	解释： 
		我们有大量的节点与其祖先的差值，其中一些如下：
		|8 - 3| = 5
		|3 - 7| = 4
		|8 - 1| = 7
		|10 - 13| = 3
		在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
	 
	
	提示：	
		树中的节点数在 2 到 5000 之间。
		每个节点的值介于 0 到 100000 之间。
 */
import TreeNode.TreeNode;
//1026.节点与其父节点之间的最大差值
public class MaximumDifferenceBetweenNodeandAncestor {
	public int maxAncestorDiff(TreeNode root) {
		int res = 0;
		if (root == null) {
			return res;
		}

		Stack<Integer> minNum = new Stack<Integer>();
		Stack<Integer> maxNum = new Stack<Integer>();
		Stack<TreeNode> sta = new Stack<TreeNode>();

		sta.push(root);
		minNum.push(root.val);
		maxNum.push(root.val);

		TreeNode cur = root.left;
		TreeNode pre = null;

		while (cur != null) {
			sta.push(cur);
			int tem = cur.val;
			minNum.push(Math.min(tem, minNum.peek()));
			maxNum.push(Math.max(tem, maxNum.peek()));
			cur = cur.left;
		}

		while (!sta.isEmpty()) {
			cur = sta.peek();
			if (cur.right == null || cur.right == pre) {
				int tem = cur.val;
				res = Math.max(res, Math.abs(tem - minNum.peek()));
				res = Math.max(res, Math.abs(tem - maxNum.peek()));
				sta.pop();
				minNum.pop();
				maxNum.pop();
				pre = cur;
			} else {
				cur = cur.right;
				while (cur != null) {
					sta.push(cur);
					int tem = cur.val;
					minNum.push(Math.min(tem, minNum.peek()));
					maxNum.push(Math.max(tem, maxNum.peek()));
					cur = cur.left;
				}
			}
		}
		return res;

	}
}
