package Leetcode_697_DegreeofanArray;

import java.util.HashMap;
import java.util.Set;

/*
	给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。	
	你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
	
	示例 1:	
		输入: [1, 2, 2, 3, 1]
		输出: 2
		解释: 
		输入数组的度是2，因为元素1和2的出现频数最大，均为2.
		连续子数组里面拥有相同度的有如下所示:
		[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
		最短连续子数组[2, 2]的长度为2，所以返回2.
	
	示例 2:	
		输入: [1,2,2,3,1,4,2]
		输出: 6
		
	注意:	
		nums.length 在1到50,000区间范围内。
		nums[i] 是一个在0到49,999范围内的整数。
 */
public class DegreeofanArray {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		DegreeofanArray da = new DegreeofanArray();
		int[] nums = { 1 };
		da.findShortestSubArray(nums);
	}

	// 697. 数组的度
	public int findShortestSubArray(int[] nums) {
		HashMap<Integer, Integer> map = new HashMap<>();
		int result = Integer.MAX_VALUE;
		int maxCount = 0;
		for (int i = 0; i < nums.length; i++) {
			if (map.containsKey(nums[i])) {
				int temp = map.get(nums[i]);
				temp++;
				map.put(nums[i], temp);
				maxCount = Math.max(maxCount, temp);
			} else {
				map.put(nums[i], 1);
				maxCount = Math.max(maxCount, 1);
			}
		}
		Set<Integer> set = map.keySet();
		int maxCountNum = 0;
		for (Integer temp : set) {
			if (map.get(temp) == maxCount) {
				maxCountNum = temp;
				int minindex = 0;
				int maxindex = 0;
				for (int i = 0; i < nums.length; i++) {
					if (nums[i] == maxCountNum) {
						minindex = i;
						break;
					}
				}
				for (int j = nums.length - 1; j >= 0; j--) {
					if (nums[j] == maxCountNum) {
						maxindex = j;
						break;
					}
				}
				result = Math.min(result, maxindex - minindex + 1);
			}
		}
		return result;
	}

}
