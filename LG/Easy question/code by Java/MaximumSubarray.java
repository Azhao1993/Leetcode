package Leetcode_053_MaximumSubarray;

/*
	给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
	
	示例:	
		输入: [-2,1,-3,4,-1,2,1,-5,4],
		输出: 6
		解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
	进阶:	
		如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 */
public class MaximumSubarray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
		System.out.println(new MaximumSubarray().maxSubArray(nums));
	}

	// 53. 最大子序和
	public int maxSubArray(int[] nums) {
		
		// Kadane算法
		// 遍历该数组， 在遍历过程中， 将遍历到的元素依次累加起来， 当累加结果小于或等于0时， 从下一个元素开始，重新开始累加。
		// 累加过程中， 要用一个变量(max_so_far)记录所获得过的最大值
		// 一次遍历之后， 变量 max_so_far 中存储的即为最大子片段的和值。
		int sum = 0;
		int max_so_far = Integer.MIN_VALUE;
		for(int i = 0;i<nums.length;i++) {
			sum += nums[i];
			max_so_far = Math.max(max_so_far, sum);
			if(sum<=0) {
				sum = 0;
			}
		}
		return max_so_far;
	}

}
