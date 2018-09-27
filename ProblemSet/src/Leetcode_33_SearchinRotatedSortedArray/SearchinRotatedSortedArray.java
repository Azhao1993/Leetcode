package Leetcode_33_SearchinRotatedSortedArray;
/*
	假设按照升序排序的数组在预先未知的某个点上进行了旋转。
	( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
	搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
		
	你可以假设数组中不存在重复的元素。	
	你的算法时间复杂度必须是 O(log n) 级别。
	
	示例 1:
		输入: nums = [4,5,6,7,0,1,2], target = 0
		输出: 4
	
	示例 2:
		输入: nums = [4,5,6,7,0,1,2], target = 3
		输出: -1
*/
public class SearchinRotatedSortedArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SearchinRotatedSortedArray srsa = new SearchinRotatedSortedArray();
		int[] nums = {4,5,6,7,0,1,2};
		int target = 0;
		System.out.println(srsa.search(nums, target));
	}
	//33. 搜索旋转排序数组
    public int search(int[] nums, int target) {
    	if((nums==null)||(nums.length==0)) {
    		return -1;
    	}
    	//将数组分为[first,second]旋转后[second,first]
        int left = 0;
        int right = nums.length-1;
        while(left<=right) {
        	int mid = left + (right-left)/2;
        	if(nums[mid]==target) {
        		return mid;
        	}else if(nums[mid]<nums[right]) {
        		//mid属于后部分
        		//mid比target小，比right小，
        		if((nums[mid]<target)&&(nums[right]>=target)) {
        			//在右边
        			left = mid +1;
        		}else {
        			//在左边
        			right = mid -1;
        		}
        	}else {
        		//mid属于前部分
        		//left比target小，比mid比target大
        		if((nums[left]<=target)&&(nums[mid]>target)) {
        			//在左边
        			right = mid -1;
        		}else {
        			//在右边
        			left = mid + 1;
        		}
        	}
        }
        return -1;
    }

}
