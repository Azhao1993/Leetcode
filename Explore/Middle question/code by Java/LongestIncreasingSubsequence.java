package Leetcode_300_LongestIncreasingSubsequence;

/*
	给定一个无序的整数数组，找到其中最长上升子序列的长度。
	
	示例:	
		输入: [10,9,2,5,3,7,101,18]
		输出: 4 
	解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
	说明:	
		可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
		你算法的时间复杂度应该为 O(n2) 。
	进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 */
//300.最长的上升子序列
public class LongestIncreasingSubsequence {
	public int lengthOfLIS(int[] nums) {
		int length = nums.length;
		int[] dp = new int[length];
		int result = Integer.MIN_VALUE;
		for (int i = 0; i < length; i++) {
			dp[i] = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (nums[i] > nums[j]) {
					dp[i] = Math.max(dp[i], dp[j] + 1);
				}
			}
			result = Math.max(result, dp[i]);
		}
		return result;
	}

	// 0ms
	public int lengthOfLIS0(int[] nums) {
		if (nums == null || nums.length == 0)
			return 0;
		int len = nums.length;
		int last = 0;
		int[] dp = new int[len];
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				dp[0] = nums[0];
			} else if (dp[last] < nums[i]) {
				dp[++last] = nums[i];
			} else {
				for (int j = 0; j <= last; j++) {
					if (dp[j] >= nums[i]) {
						dp[j] = nums[i];
						break;
					}
				}
			}
		}
		return last + 1;
	}
}
