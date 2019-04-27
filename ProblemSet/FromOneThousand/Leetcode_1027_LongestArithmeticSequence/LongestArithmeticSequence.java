package Leetcode_1027_LongestArithmeticSequence;

import java.util.HashMap;
import java.util.HashSet;

/*
	给定一个整数数组 A，返回 A 中最长等差子序列的长度。	
	回想一下，A 的子序列是列表 A[i_1], A[i_2], ..., A[i_k] 
	其中 0 <= i_1 < i_2 < ... < i_k <= A.length - 1。
	并且如果 B[i+1] - B[i]( 0 <= i < B.length - 1) 的值都相同，那么序列 B 是等差的。	 
	
	示例 1：	
		输入：[3,6,9,12]
		输出：4
		解释： 
		整个数组是公差为 3 的等差数列。
	示例 2：	
		输入：[9,4,7,2,10]
		输出：3
		解释：
		最长的等差子序列是 [4,7,10]。
	示例 3：	
		输入：[20,1,15,3,10,5,8]
		输出：4
		解释：
		最长的等差子序列是 [20,15,10,5]。
	
	提示：	
		2 <= A.length <= 2000
		0 <= A[i] <= 10000
 */

//1027. 最长等差数列
public class LongestArithmeticSequence {
	public int longestArithSeqLength(int[] A) {
		int n = A.length;
		HashSet<Integer> h = new HashSet<>();
		int ans = 2;
		for (int a : A) {
			h.add(a);
		}
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				// 等差d
				int d = (A[j] - A[i]);
				// 期望出现的下一个数t
				int t = A[j] + d;
				// 开始的长度为2
				int l = 2;
				// 不存在t
				if (!h.contains(t))
					continue;
				// 存在t
				// 从j+1的位置开始找
				for (int k = j + 1; k < n; ++k) {
					if (A[k] == t) {
						t += d;
						++l;
					}
				}
				ans = Math.max(ans, l);

			}
		}
		return ans;
	}

	// 24ms
	public int longestArithSeqLength0(int[] A) {
		int len = A.length;
		HashMap<Integer, Integer> map[] = new HashMap[len];
		for (int i = 0; i < len; i++) {
			map[i] = new HashMap<>();
		}
		int rs = 0;
		// key:d -> value:l
		for (int i = 1; i < len; i++) {
			for (int j = 0; j < i; j++) {
				int d = A[i] - A[j];
				int temp = map[j].get(d) == null ? 0 : map[j].get(d);
				int l = temp + 1;
				map[i].put(d, l);
				rs = rs > l ? rs : l;
			}
		}
		return rs + 1;
	}
}
