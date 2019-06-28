package Leetcode_016_3SumClosest;

import java.util.Arrays;

/*
	给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
	找出 nums 中的三个整数，使得它们的和与 target 最接近。
	返回这三个数的和。假定每组输入只存在唯一答案。
	
	例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.	
	与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 */
public class ThreeSumClosest {
	public static void main(String[] args) {
		int[] nums = { 1, 2, 4, 8, 16, 32, 64, 128 };
		int target = 82;
		System.out.println(new ThreeSumClosest().threeSumClosest(nums, target));
	}

	// 16.最接近的三数之和
	// O(n^2)
	public int threeSumClosest0(int[] num, int target) {
		int result = num[0] + num[1] + num[num.length - 1];
		Arrays.sort(num);
		for (int i = 0; i < num.length - 2; i++) {
			int start = i + 1, end = num.length - 1;
			while (start < end) {
				int sum = num[i] + num[start] + num[end];
				if (sum > target) {
					end--;
				} else {
					start++;
				}
				if (Math.abs(sum - target) < Math.abs(result - target)) {
					result = sum;
				}
			}
		}
		return result;
	}
}
