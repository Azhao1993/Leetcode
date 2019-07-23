package Leetcode_257_BinaryTreePaths;

import java.util.LinkedList;
import java.util.List;

import TreeNode.TreeNode;

/*
	给定一个二叉树，返回所有从根节点到叶子节点的路径。	
	说明: 叶子节点是指没有子节点的节点。
		
	示例:	
		输入:	
			   1
			 /   \
			2     3
			 \
			  5		
		输出: ["1->2->5", "1->3"]	
		解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/binary-tree-paths
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class BinaryTreePaths {
	// 257. 二叉树的所有路径
	public List<String> binaryTreePaths(TreeNode root) {
		List<String> res = new LinkedList<String>();

		if (root == null) {
			return res;
		}

		if (root.left == null && root.right == null) {
			res.add(String.valueOf(root.val));
		}

		List<String> leftS = binaryTreePaths(root.left);
		for (int i = 0; i < leftS.size(); i++) {
			res.add(String.valueOf(root.val) + "->" + leftS.get(i));
		}

		List<String> rightS = binaryTreePaths(root.right);
		for (int i = 0; i < rightS.size(); i++) {
			res.add(String.valueOf(root.val) + "->" + rightS.get(i));
		}
		return res;

	}
}
