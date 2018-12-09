package Leetcode_594_LongestHarmoniousSubsequence;

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
		int[] nums = {1,3,2,2,5,2,3,7};
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
		int maxLength = Integer.MIN_VALUE;
		for (int i = min; i <= max; i++) {
			int count = 0;
			if(map.containsKey(i+1)&&(map.containsKey(i))) {
				count += map.get(i)+map.get(i+1);
				maxLength = Math.max(count, maxLength);
			}
		}
		return maxLength;
	}

}
