package Leetcode_1099_TwoSumLessThanK;

import java.util.Arrays;

/*
	给你一个整数数组 A 和一个整数 K，请在该数组中找出两个元素，
	使它们的和小于 K 但尽可能地接近 K，返回这两个元素的和。
	
	如不存在这样的两个元素，请返回 -1。 
	
	示例 1：	
		输入：A = [34,23,1,24,75,33,54,8], K = 60
		输出：58
		解释：
		34 和 24 相加得到 58，58 小于 60，满足题意。
	示例 2：	
		输入：A = [10,20,30], K = 15
		输出：-1
		解释：
		我们无法找到和小于 15 的两个元素。
	
	提示：	
		1 <= A.length <= 100
		1 <= A[i] <= 1000
		1 <= K <= 2000
 */
//1099.小于 K 的两数之和
public class TwoSumLessThanK {

	// O(N^2)
	public int twoSumLessThanK(int[] A, int K) {
		int res = -1;
		for (int i = 0; i < A.length - 1; i++) {
			for (int j = i + 1; j < A.length; j++) {
				if (A[i] + A[j] < K) {
					res = Math.max(res, A[i] + A[j]);
				}
			}
		}
		return res;
	}

	// O(NlogN)
	public int twoSumLessThanK2(int[] A, int K) {
		Arrays.sort(A);
		int res = -1;
		int lo = 0;
		int hi = A.length - 1;
		while (lo < hi) {
			if (A[lo] + A[hi] >= K) {
				hi--;
			} else {
				res = Math.max(A[lo] + A[hi], res);
				lo++;
			}
		}
		return res;
	}
}
