package Leetcode_154_FindMinimuminRotatedSortedArray2;

/*
	假设按照升序排序的数组在预先未知的某个点上进行了旋转。	
	( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
	
	请找出其中最小的元素。
	
	注意数组中可能存在重复的元素。
	
	示例 1：	
		输入: [1,3,5]
		输出: 1
	示例 2：	
		输入: [2,2,2,0,1]
		输出: 0
	说明：	
		这道题是 寻找旋转排序数组中的最小值 的延伸题目。
		允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
*/
public class FindMinimuminRotatedSortedArray2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = {3,3,1,3};
		FindMinimuminRotatedSortedArray2 fmrsa2 = new FindMinimuminRotatedSortedArray2();
		System.out.println(fmrsa2.findMin(nums));
	
	}

	// 154. 寻找旋转排序数组中的最小值 II
	public int findMin(int[] nums) {
		// 二分查找
		if (nums.length == 1) {
			return nums[0];
		}
		int left = 0;
		int right = nums.length - 1;
		// left<right，【小，大】，未发生旋转
		if (nums[left] < nums[right]) {
			//left<mid<right
			return nums[left];
		}
		// 发生旋转
		while (left <= right) {
			int mid = left + (right - left) / 2;
			//mid大，right小,mid属于前（大）半段
			if (nums[mid] > nums[right]) {
				//最小值在右边
				left = mid + 1;
			} else if(nums[mid]<nums[left]) {
				// mid小，left大，最小值在左边，mid属于后（小）半段
				right = mid;
			}else {
				//nums[left] >= nums[right];
				//nums[mid]<=nums[right] ,nums[mid]>=nums[left]
				right--;
			}
		}
		return nums[left];
	}

}
