package TreeNode;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class TreeNodeUtils {
	public static void main(String[] args) {
		String[] arr = { "1", "2", "3", "null", "4", "5", "6" };
		TreeNode root = TreeNodeUtils.createTree(arr);
		TreeNodeUtils.printTree(root);
	}

	public static void printTree(TreeNode root) {
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		while (!queue.isEmpty()) {
			for (int size = queue.size(); size > 0; size--) {
				TreeNode cur = queue.poll();
				if (cur == null) {
					System.out.print("null,");
				} else {
					int val = cur.val;
					System.out.print(val + ",");
					queue.add(cur.left);
					queue.add(cur.right);
				}
			}
			System.out.println();
		}

	}

	public static TreeNode createTree(String[] arr) {
		List<TreeNode> queue = new LinkedList<>();

		for (String str : arr) {
			TreeNode cur = null;
			if (str.equals("null")) {
				cur = null;
			} else {
				int val = Integer.valueOf(str);
				cur = new TreeNode(val);
			}
			queue.add(cur);
		}
		TreeNode root = queue.get(0);
		for (int i = 0; i < arr.length; i++) {
			int left = (i * 2 + 1) < arr.length ? i * 2 + 1 : -1;
			if (left != -1) {
				queue.get(i).left = queue.get(left);
			}
			int right = (i * 2 + 2) < arr.length ? i * 2 + 2 : -1;
			if (right != -1) {
				queue.get(i).right = queue.get(right);
			}
		}

		return root;

	}
}
