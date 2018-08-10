package Leetcode_414_ThirdMaximumNumber;

/*

	给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

	示例 1:	
		输入: [3, 2, 1]	
		输出: 1	
		解释: 第三大的数是 1.
		
	示例 2:	
		输入: [1, 2]	
		输出: 2	
		解释: 第三大的数不存在, 所以返回最大的数 2 .
		
	示例 3:	
		输入: [2, 2, 3, 1]	
		输出: 1	
		解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
		存在两个值为2的数，它们都排第二。
*/
public class ThirdMaximumNumber {
	public int thirdMax(int[] nums) {
		// 计数器
		int count = 1;
		//int max;
		// 从大到小排序，找到第三大的数
		for (int i = 0; i < nums.length - 1; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if(nums[i]<nums[j]) {
					int temp = nums[i];
					nums[i] =nums[j];
					nums[j] = temp;
				}
			}
			//从nums[1]开始检查
			if(i>0) {
				if(nums[i-1]!=nums[i]) {
					//max = nums[i];
					count++;
					if(count==3) {
						return nums[i];
					}				
				}
			}

		}
		
		return nums[0];
		
	}
}
