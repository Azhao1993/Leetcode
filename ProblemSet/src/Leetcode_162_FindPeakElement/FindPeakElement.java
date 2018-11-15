package Leetcode_162_FindPeakElement;

/*
	峰值元素是指其值大于左右相邻值的元素。
	给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
	数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
	
	你可以假设 nums[-1] = nums[n] = -∞。
	
	示例 1:
		输入: nums = [1,2,3,1]
		输出: 2
	解释: 
		3 是峰值元素，你的函数应该返回其索引 2。
	
	示例 2:
		输入: nums = [1,2,1,3,5,6,4]
		输出: 1 或 5 
	解释: 
		你的函数可以返回索引 1，其峰值元素为 2；
	 	或者返回索引 5， 其峰值元素为 6。
	     
	说明:	
		你的解法应该是 O(logN) 时间复杂度的。
*/
public class FindPeakElement {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FindPeakElement fpe = new FindPeakElement();
		int[] nums = { 1,2,3,1 };
		System.out.println(fpe.findPeakElement2(nums));
	}

	// 162. 寻找峰值
	public int findPeakElement(int[] nums) {
		// 长度为1
		if (nums.length == 1) {
			return 0;
		}
		// 长度为2
		if (nums.length == 2) {
			if (nums[0] > nums[1]) {
				return 0;
			} else {
				return 1;
			}
		}
		// 长度>=3
		int left = 0;
		int right = nums.length-1;		
		while (left < right) {
			int mid = left + (right - left) / 2;
			if ((mid - 1 >= 0) && (nums[mid] > nums[mid - 1]) && (mid + 1 <= nums.length - 1)
					&& (nums[mid] > nums[mid + 1])) {
				return mid;
			} else if (nums[mid] < nums[mid + 1]) {
				// mid比mid+1小，最值在右边
				if(mid+1==nums.length-1) {
					return mid+1;
				}
				left = mid + 1;
			} else {
				if (mid == 0) {
					return mid;
				}
				right = mid;
			}
		}
		//此处返回值不影响结果
		return left;
		
	}
	
	//模板3
	public int findPeakElement2(int[] nums) {
		// 长度为1
		if (nums.length == 1) {
			return 0;
		}		
		int left = 0;
		int right = nums.length-1;
		if(nums[left]>nums[left+1]){
			return left;
		}
		if(nums[right]>nums[right-1]) {
			return right;
		}
		
		while(left+1<right) {			
			int mid = left + (right-left)/2;
			//mid是峰值
			if((mid>0)&&(nums[mid]>nums[mid-1])&&(mid<nums.length-1)&&(nums[mid]>nums[mid+1])) {
				return mid;
			}else if(nums[mid]<nums[mid+1]) {
				left = mid;
			}else  {
				right = mid;
			}			
		}
		return left;
	}

}
