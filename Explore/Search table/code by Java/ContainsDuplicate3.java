package Leetcode_220_ContainsDuplicate3;

import java.util.TreeSet;

/*
	给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，
	使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，
	并且 i 和 j 之间的差的绝对值最大为 k。
	
	示例 1:	
		输入: nums = [1,2,3,1], k = 3, t = 0
		输出: true
		
	示例 2:	
		输入: nums = [1,0,1,1], k = 1, t = 2
		输出: true
		
	示例 3:	
		输入: nums = [1,5,9,1,5,9], k = 2, t = 3
		输出: false
 */

public class ContainsDuplicate3 {
	// 220. 存在重复元素 III

	public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
		// k>=|i-j|
		// t>=|nums[i]-nums[j]|
		if (nums == null || nums.length == 0 || k <= 0) {
			return false;
		}

		for (int i = 0; i < nums.length; i++) {
			for (int j = 1; j <= k && i + j < nums.length; j++) {
				long n1 = nums[i];
				long n2 = nums[i + j];
				if (Math.abs(n1 - n2) <= t) {
					return true;
				}
			}
		}
		return false;
	}
}
