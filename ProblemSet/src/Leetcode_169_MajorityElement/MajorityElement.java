package Leetcode_169_MajorityElement;

/*
	给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 [n/2]的元素。
	你可以假设数组是非空的，并且给定的数组总是存在众数。
	
	示例 1:	
		输入: [3,2,3]
		输出: 3
		
	示例 2:	
		输入: [2,2,1,1,1,2,2]
		输出: 2
*/
public class MajorityElement {
	public int majorityElement(int[] nums) {

		int i;
		// 数组长度为1
		if (nums.length == 1) {
			return nums[0];
		}

		// 对数组进行排序,中间位置的数一定是众数
		for (i = 0; i < nums.length - 1; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				// 从小到大
				if (nums[i] > nums[j]) {
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
			}

		}
		

		return nums[nums.length / 2];

	}
}
