package Leetcode_494_TargetSum;

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
		System.out.println((5 + 3) >>> 1);
	}

	// 494. 目标和

	public int findTargetSumWays(int[] nums, int s) {
		int sum = 0;
		for (int n : nums) {
			sum += n;
		}
		// 元素和sum达不到目标值s；
		// 元素和sum和目标值s的奇偶性不同
		return sum < s || (s + sum) % 2 > 0 ? 0 : subsetSum(nums, (s + sum) >>> 1);
	}

	/**
	 * s:新目标值=（s+num）/ 2.
	 */

	public int subsetSum(int[] nums, int s) {
		// dp[i]：nums的子集组成目标值i的方案数
		int[] dp = new int[s + 1];
		// 空集方案有且只有1种
		dp[0] = 1;
		// 遍历所有元素
		for (int n : nums) {
			for (int i = s; i >= n; i--) {
				// 目标值为i的方案数=当前方案数+目标值为i-n的方案数
				dp[i] += dp[i - n];
			}
		}
		return dp[s];
	}
}
