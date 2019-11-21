package Leetcode_703_KthLargestElementinaStream;

import TreeNode.TreeNode;

/*
	设计一个找到数据流中第K大元素的类（class）。
	注意是排序后的第K大元素，不是第K个不同的元素。
	
	你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。
	每次调用 KthLargest.add，返回当前数据流中第K大的元素。
	
	示例:	
		int k = 3;
		int[] arr = [4,5,8,2];
		KthLargest kthLargest = new KthLargest(3, arr);
		kthLargest.add(3);   // returns 4
		kthLargest.add(5);   // returns 5
		kthLargest.add(10);  // returns 5
		kthLargest.add(9);   // returns 8
		kthLargest.add(4);   // returns 8
	说明: 
	你可以假设 nums 的长度≥ k-1 且k ≥ 1。
 */
//703. 数据流中的第K大元素
public class KthLargest {
	TreeNode root;
	int k;

	public KthLargest(int k, int[] nums) {
		this.k = k;
		for (int num : nums) {
			root = add(root, num);
		}
	}

	public int add(int val) {
		root = add(root, val);
		return findKthLargest();
	}

	private TreeNode add(TreeNode root, int val) {
		if (root == null) {
			return new TreeNode(val);
		}
		root.count++;
		// val<root.val在左边
		if (val < root.val) {
			root.left = add(root.left, val);
		} else {
			// val>root在右边
			root.right = add(root.right, val);
		}
		return root;
	}

	public int findKthLargest() {
		int count = k;
		TreeNode walker = root;

		while (count > 0) {
			// 先检查右子树中节点的个数
			int pos = 1 + (walker.right != null ? walker.right.count : 0);
			// 刚好==count,说明walker是第k大数
			if (count == pos) {
				break;
			}
			// 如果count>pos，说明第k大数在左边
			if (count > pos) {
				// 跟新count
				count -= pos;
				// 在walker.left中找第count大的数
				walker = walker.left;
			} else if (count < pos) {
				// count<pos说明第k大的数在右边
				walker = walker.right;
			}
		}
		return walker.val;
	}

	class TreeNode {
		int val;
		// 记录此节点下有多少子节点（包含自己在内）
		int count = 1;
		TreeNode left, right;

		TreeNode(int v) {
			val = v;
		}
	}
}
