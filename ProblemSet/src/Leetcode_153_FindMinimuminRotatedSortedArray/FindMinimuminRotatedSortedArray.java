package Leetcode_153_FindMinimuminRotatedSortedArray;

/*
	假设按照升序排序的数组在预先未知的某个点上进行了旋转。	
	( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。	
	请找出其中最小的元素。
	
	你可以假设数组中不存在重复元素。
	
	示例 1:
		输入: [3,4,5,1,2]
		输出: 1
	示例 2:	
		输入: [4,5,6,7,0,1,2]
		输出: 0
*/
public class FindMinimuminRotatedSortedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FindMinimuminRotatedSortedArray fmrsa = new FindMinimuminRotatedSortedArray();
		int[] nums = {4,5,6,7,0,1,2};
		System.out.println(fmrsa.findMin(nums));
	}

	// 153. 寻找旋转排序数组中的最小值
	//right是后半段的最大值
	//left是前半段的最小值
	//【大，小】，此时小组中的每一个值 都比大组的最小值小。left(大组的最小值),right(小组的最大值),right一定比left一定比小。
	//【小，大】left一定比right一定比小
	public int findMin(int[] nums) {
		// 二分查找
		if (nums.length == 1) {
			return nums[0];
		}
		int left = 0;
		int right = nums.length - 1;
		//left<right，【小，大】
		if(nums[left]<nums[right]) {
			return nums[left];
		}		
		//[大，小]		
		while (left < right) {
			int mid = left + (right - left) / 2;
			//mid>left,mid属于大。
			if(nums[mid]>nums[right]) {
				//最小值在右
				left = mid +1;
			}else {
				//最大值在左
				right = mid;
			}
		}
		return nums[left];

	}

}
