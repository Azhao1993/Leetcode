package Leetcode_561_ArrayPartition1;

import java.util.Arrays;

/*
	给定长度为 2n 的数组, 你的任务是将这些数分成 n对, 
	例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

	示例 1:
		输入: [1,4,3,2]		
		输出: 4
		解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
*/

public class ArrayPartition1 {
	public static void main(String[] args) {
		ArrayPartition1 ap = new ArrayPartition1();
		int[] nums = { 1, 4, 3, 2 };
		System.out.println(ap.arrayPairSum(nums));
	}
	//561. 数组拆分 I
	public int arrayPairSum(int[] nums) {
		Arrays.sort(nums);
		System.out.println(Arrays.toString(nums));
		int sum = 0;
		for (int i = 0; i < nums.length - 1; i++) {
			if (nums[i] >= nums[i + 1]) {
				sum += nums[i + 1];
			} else {
				sum += nums[i];
			}
			i++;
		}
		return sum;
	}
}
