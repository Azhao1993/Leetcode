package Leetcode_561_ArrayPartition1;
//失败
/*
	给定长度为 2n 的数组, 你的任务是将这些数分成 n对, 
	例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

	示例 1:
		输入: [1,4,3,2]		
		输出: 4
		解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
*/

public class ArrayPartition1 {
	public int arrayPairSum(int[] nums) {
		int sum = 0;
		for (int i = 0; i < nums.length - 1; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if (nums[i] > nums[j]) {
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}				
			}
			if (i % 2 == 0) {
				sum += nums[i];
			}
		}
		return sum;
	}
}
