package Leetcode_1110_DeleteNodesAndReturnForest;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import TreeNode.TreeNode;

/*
	给出二叉树的根节点 root，树上每个节点都有一个不同的值。	
	如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。	
	返回森林中的每棵树。你可以按任意顺序组织答案。	 
	
	示例：	
		输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
		输出：[[1,2,null,4],[6],[7]]	 
	
	提示：	
		树中的节点数最大为 1000。
		每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
		to_delete.length <= 1000
		to_delete 包含一些从 1 到 1000、各不相同的值。
 */

//1110.删点成林
public class DeleteNodesAndReturnForest {
	public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
		List<TreeNode> res = new ArrayList<>();
		res.add(root);
		HashSet<Integer> delSet = new HashSet<>();
		for (int i : to_delete) {
			delSet.add(i);
		}

		// 按层遍历树
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		while (!queue.isEmpty()) {
			TreeNode temp = queue.poll();
			// 将删除节点的叶子节点加入list
			if (delSet.contains(temp.val)) {
				if (res.contains(temp)) {
					res.remove(temp);
				}

				if (temp.left != null) {
					res.add(temp.left);
				}
				if (temp.right != null) {
					res.add(temp.right);
				}
			}
			// 将删除的节点与其父节点断开
			if (temp.left != null) {
				queue.add(temp.left);
				if (delSet.contains(temp.left.val)) {
					temp.left = null;
				}
			}
			if (temp.right != null) {
				queue.add(temp.right);
				if (delSet.contains(temp.right.val)) {
					temp.right = null;
				}
			}

		}
		return res;
	}
}
