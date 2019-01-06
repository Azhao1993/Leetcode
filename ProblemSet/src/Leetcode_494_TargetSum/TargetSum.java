package Leetcode_494_TargetSum;

import java.util.Stack;

/*
	给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
	现在你有两个符号 + 和 -。
	对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
	
	返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
	
	示例 1:	
		输入: nums: [1, 1, 1, 1, 1], S: 3
		输出: 5
		解释: 		
			-1+1+1+1+1 = 3
			+1-1+1+1+1 = 3
			+1+1-1+1+1 = 3
			+1+1+1-1+1 = 3
			+1+1+1+1-1 = 3
		
		一共有5种方法让最终目标和为3。
	注意:	
		数组的长度不会超过20，并且数组中的值全为正数。
		初始的数组的和不会超过1000。
		保证返回的最终结果为32位整数。
 */
public class TargetSum {
	public static void main(String[] args) {
		int[] nums = { 1, 1, 1, 1, 1 };
		int S = 3;
		TargetSum ts = new TargetSum();
		ts.findTargetSumWays(nums, S);
	}

	// 494. 目标和（不明白）
	public int findTargetSumWays(int[] nums, int S) {
		if (nums == null || nums.length == 0) {
			return 0;
		}
		//

		return helper(nums, S, 0, 0, 0);
	}

	// 这里不传入全局变量count的原因是每次的count都已返回值形式返回
	public int helper(int[] nums, int S, int sum, int index, int count) {
		// System.out.println("sum:" + sum + ";index:" + index);
		if (index == nums.length) {
			if (sum == S) {
				count++;
			}
			return count;
		}
		return helper(nums, S, sum + nums[index], index + 1, count)

				+ helper(nums, S, sum - nums[index], index + 1, count);
	}

	// 7ms
	public int findTargetSumWays0(int[] nums, int s) {
		int sum = 0;
		for (int n : nums)
			sum += n;
		//将所有数字加在一起与s比较
		//如果sum<s或者(s + sum) % 2 > 0，返回0；
		//否则subsetSum(nums, (s + sum) >>> 1)
		return sum < s || (s + sum) % 2 > 0 ? 0 : subsetSum(nums, (s + sum) >>> 1);
	}

	public int subsetSum(int[] nums, int s) {
		int[] dp = new int[s + 1];
		dp[0] = 1;
		for (int n : nums)
			for (int i = s; i >= n; i--)
				dp[i] += dp[i - n];
		return dp[s];
	}
}
