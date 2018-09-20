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

	}
	//153. 寻找旋转排序数组中的最小值
    public int findMin(int[] nums) {
        //二分查找,找到两个组数的端点，比较两个端点    	
    	int min=0;
    	int max=nums.length-1;
    	int mid = (min+max)/2;
    	while(min<max) {
    		//中间的数比左边的大，最小值在右边
    		if(nums[mid]>nums[mid]) {
    			min = mid+1;
    		}else {
    			max
    		}
    	}
        
    }

}
