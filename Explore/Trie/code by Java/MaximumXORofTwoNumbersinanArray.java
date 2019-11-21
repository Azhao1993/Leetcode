package Leetcode_421_MaximumXORofTwoNumbersinanArray;

/*
	给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 2^31 。	
	找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。
	
	你能在O(n)的时间解决这个问题吗？
	
	示例:	
		输入: [3, 10, 5, 25, 2, 8]	
		输出: 28	
		解释: 最大的结果是 5 ^ 25 = 28.
 */
//421. 数组中两个数的最大异或值
public class MaximumXORofTwoNumbersinanArray {
	public int findMaximumXOR(int[] nums) {
		if (nums == null || nums.length <= 1) {
			return 0;
		}
		NumTrie nt = new NumTrie();
		nt.add(nums[0]);
		int res = Integer.MIN_VALUE;

		for (int i = 1; i < nums.length; i++) {
			res = Math.max(res, nt.maxXor(nums[i]));
			nt.add(nums[i]);
		}

		return res;
	}
}

//前缀树节点
class Node {
	Node[] nexts;

	Node() {
		nexts = new Node[2];
	}
}
//0 xor 0 = 0;1 xor 1 = 0
//0 xor 1 = 1;1 xor 0 = 1
//不同为1

//生成前缀树
class NumTrie {
	// 头结点
	public Node head = new Node();

	// 填num到前缀树
	public void add(int num) {
		Node cur = head;
		// path 位高位
		for (int move = 31; move >= 0; move--) {
			int path = ((num >> move) & 1);
			cur.nexts[path] = cur.nexts[path] == null ? new Node() : cur.nexts[path];
			cur = cur.nexts[path];
		}
	}

	// 求与num的最大异或和
	public int maxXor(int num) {
		Node cur = head;
		int res = 0;
		// path 从高到低
		for (int move = 31; move >= 0; move--) {
			int path = (num >> move) & 1;
			// 期望得到的值

			// 最高位期望获得0
			// 其他位期望获得1
			int best = move == 31 ? path : (path ^ 1);
			// 如果存在期望值，取期望值，不存在取异或
			best = cur.nexts[best] != null ? best : (best ^ 1);
			res |= (path ^ best) << move;
			cur = cur.nexts[best];
		}
		return res;
	}

}