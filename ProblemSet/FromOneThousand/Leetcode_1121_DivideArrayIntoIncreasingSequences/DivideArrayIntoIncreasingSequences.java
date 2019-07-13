package Leetcode_1121_DivideArrayIntoIncreasingSequences;

import java.util.Arrays;
import java.util.HashMap;

/*
	给你一个 非递减 的正整数数组 nums 和整数 K，判断该数组是否可以被分成一个或几个 长度至少 为 K 的 不相交的递增子序列。 
	
	示例 1：
		输入：nums = [1,2,2,3,3,4,4], K = 3
		输出：true
		解释：
			该数组可以分成两个子序列 [1,2,3,4] 和 [2,3,4]，每个子序列的长度都至少是 3。
	示例 2：
		输入：nums = [5,6,6,7,8], K = 3
		输出：false
		解释：
			没有办法根据条件来划分数组。
	
	提示：
		1 <= nums.length <= 10^5
		1 <= K <= nums.length
		1 <= nums[i] <= 10^5
 */

//1121. 将数组分成几个递增序列
public class DivideArrayIntoIncreasingSequences {
	public boolean canDivideIntoSubsequences2(int[] nums, int K) {
		HashMap<Integer, Integer> map = new HashMap<>();
		int maxCount = Integer.MIN_VALUE;
		for (int i : nums) {
			int count = map.getOrDefault(i, 0) + 1;
			map.put(i, count);
			maxCount = Math.max(maxCount, count);
		}
		return nums.length >= maxCount * K;
	}
}
