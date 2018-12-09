package Leetcode_594_LongestHarmoniousSubsequence;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
	和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。	
	现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
	
	示例 1:	
		输入: [1,3,2,2,5,2,3,7]
		输出: 5
	原因:
		最长的和谐数组是：[3,2,2,2,3].
	说明: 
		输入的数组长度最大不超过20,000.
 */
public class LongestHarmoniousSubsequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = { 1, 3, 2, 2, 5, 2, 3, 7 };
		System.out.println(new LongestHarmoniousSubsequence().findLHS(nums));
	}

	// 594. 最长和谐子序列
	public int findLHS(int[] nums) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		for (int num : nums) {
			if (num > max) {
				max = num;
			}
			if (num < min) {
				min = num;
			}
			map.put(num, map.getOrDefault(num, 0) + 1);
		}
		int maxLength = 0;
		for (Integer i : map.keySet()) {
			int count = 0;
			if (map.containsKey(i + 1) && (map.containsKey(i))) {
				count += map.get(i) + map.get(i + 1);
				maxLength = Math.max(count, maxLength);
			}
		}
		return maxLength;
	}

	// 31ms
	public int findLHS0(int[] nums) {
		if (nums == null || nums.length == 0 || nums.length == 1) {
			return 0;
		}
		Arrays.sort(nums);
		int max = 0, temp = nums[0], begin = 0, index = 0;
		boolean isStart = true;
		for (int i = 1; i <= nums.length; i++) {
			if (i == nums.length || nums[i] != temp) {
				if (!isStart) {
					max = max > (i - begin) ? max : (i - begin);
					begin = index;
				}
				if (i == nums.length)
					break;
				if (nums[i] - temp == 1) {
					isStart = false;
				} else {
					isStart = true;
					begin = i;
				}
				temp = nums[i];
				index = i;
			}
		}
		return max;
	}

}
