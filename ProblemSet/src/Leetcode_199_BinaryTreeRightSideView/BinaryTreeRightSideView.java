package Leetcode_199_BinaryTreeRightSideView;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import TreeNode.TreeNode;

/*
	给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
	
	示例:	
		输入: [1,2,3,null,5,null,4]
		输出: [1, 3, 4]
		解释:		
			   1            <---
			 /   \
			2     3         <---
			 \     \
			  5     4       <---
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class BinaryTreeRightSideView {
	// 199. 二叉树的右视图
	public List<Integer> rightSideView(TreeNode root) {
		List<Integer> res = new LinkedList<>();
		if (root == null) {
			return res;
		}
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		while (!queue.isEmpty()) {
			int size = queue.size();
			for (int i = 0; i < size; i++) {
				TreeNode cur = queue.poll();
				if (i == size - 1) {
					res.add(cur.val);
				}
				if (cur.left != null) {
					queue.add(cur.left);
				}
				if (cur.right != null) {
					queue.add(cur.right);
				}
			}
		}
		return res;

	}

	List<Integer> res;
	int maxDepth;

	public List<Integer> rightSideView2(TreeNode root) {
		maxDepth = -1;
		res = new ArrayList<>();
		trans(root, 0);
		return res;
	}

	private void trans(TreeNode root, int curDepth) {
		if (root == null) {
			return;
		}

		if (curDepth > maxDepth) {
			maxDepth = curDepth;
			res.add(root.val);
		}

		trans(root.right, curDepth + 1);
		trans(root.left, curDepth + 1);
	}
}
