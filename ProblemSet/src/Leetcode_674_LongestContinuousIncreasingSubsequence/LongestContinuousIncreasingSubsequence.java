package Leetcode_674_LongestContinuousIncreasingSubsequence;

/*
	给定一个未经排序的整数数组，找到最长且连续的的递增序列。
	
	示例 1:	
		输入: [1,3,5,4,7]
		输出: 3
		解释: 最长连续递增序列是 [1,3,5], 长度为3。
		尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
		
	示例 2:	
		输入: [2,2,2,2,2]
		输出: 1
		解释: 最长连续递增序列是 [2], 长度为1。
	注意：数组长度不会超过10000。
*/
public class LongestContinuousIncreasingSubsequence {
	public int findLengthOfLCIS(int[] nums) {
		// 获取数组长度
		int length = nums.length;
		// 空数组
		if (length == 0) {
			return 0;
		} else if (length == 1) {
			return 1;
		}
		// 定义最大长度
		int maxlength = 0;

		// 计数器
		int count = 1;
		// 遍历数组
		for (int i = 1; i < length; i++) {
			if (nums[i] > nums[i - 1]) {
				count++;
			} else {
				maxlength = Math.max(count, maxlength);
				count = 1;
			}
		}
		maxlength = Math.max(count, maxlength);
		return maxlength;
	}
}
