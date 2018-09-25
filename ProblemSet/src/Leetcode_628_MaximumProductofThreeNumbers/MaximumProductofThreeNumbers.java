package Leetcode_628_MaximumProductofThreeNumbers;

/*
	给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
	
	示例 1:	
		输入: [1,2,3]
		输出: 6
		
	示例 2:	
		输入: [1,2,3,4]
		输出: 24
		
	注意:	
		给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
		输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
*/
public class MaximumProductofThreeNumbers {
	public int maximumProduct(int[] nums) {
		//最大的三个正数，最小的两个负数和最大的正数
		//找到最大的三个数
		for(int i = 0;i<3;i++) {
			for(int j =i+1;j<nums.length;j++) {
				if(nums[i]<nums[j]) {
					int temp = nums[i];
					nums[i]= nums[j];
					nums[j]= temp;
				}
			}
		}
		//找到最小的两个负数
		for(int i = nums.length-1;i>nums.length-3;i--) {
			for(int j = i-1;j>=0;j-- ) {
				if(nums[i]>nums[j]) {
					int temp = nums[i];
					nums[i]= nums[j];
					nums[j]= temp;
				}
			}
		}
		
		return Math.max(nums[0]*nums[1]*nums[2], nums[0]*nums[nums.length-2]*nums[nums.length-1]);
	}
}
