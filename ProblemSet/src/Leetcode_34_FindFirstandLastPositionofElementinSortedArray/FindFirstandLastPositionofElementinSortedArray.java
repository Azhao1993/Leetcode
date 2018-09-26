package Leetcode_34_FindFirstandLastPositionofElementinSortedArray;

import java.util.Arrays;

/*
	给定一个按照升序排列的整数数组 nums，和一个目标值 target。
	找出给定目标值在数组中的开始位置和结束位置。	
	你的算法时间复杂度必须是 O(log n) 级别。	
	如果数组中不存在目标值，返回 [-1, -1]。
	
	示例 1:	
		输入: nums = [5,7,7,8,8,10], target = 8
		输出: [3,4]
	
	示例 2:	
		输入: nums = [5,7,7,8,8,10], target = 6
		输出: [-1,-1]
*/
public class FindFirstandLastPositionofElementinSortedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FindFirstandLastPositionofElementinSortedArray fflpesa = new FindFirstandLastPositionofElementinSortedArray();
		int[] nums = { 1 };
		int target = 0;
		System.out.println(Arrays.toString(fflpesa.searchRange(nums, target)));
	}

	// 34. 在排序数组中查找元素的第一个和最后一个位置
	public int[] searchRange(int[] nums, int target) {
		int[] result = { -1, -1 };
		if ((nums.length == 0) || (nums == null)) {
			return result;
		}		
		int left = 0;
		int right = nums.length - 1;		
		while (left < right) {
			// Prevent (left + right) overflow
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid+1;
			} else if (nums[mid] > target) {
				right = mid;
			} else {
				break;
			}
		}
		while(left<=right) {
			if((left<=nums.length-1)&&(nums[left]!=target)) {
				left++;
			}
			if((right>=0)&&(nums[right]!=target)) {
				right--;
			}
			if(left>right) {
				return result;
			}
			if((nums[left]==target)&&(nums[right]==target)) {
				result[0] = left;
				result[1] =  right ;
				return result;
			}
		}
		return result;
		
		
	}

}
