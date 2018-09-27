package Leetcode_704_BinarySearch;
/*
	给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
	写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
	
	示例 1:
		输入: nums = [-1,0,3,5,9,12], target = 9
		输出: 4
	解释: 9 出现在 nums 中并且下标为 4
	
	示例 2:
		输入: nums = [-1,0,3,5,9,12], target = 2
		输出: -1
	解释: 2 不存在 nums 中因此返回 -1 
	
	提示：
		你可以假设 nums 中的所有元素是不重复的。
		n 将在 [1, 10000]之间。
		nums 的每个元素都将在 [-9999, 9999]之间。
*/
public class BinarySearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BinarySearch bs = new BinarySearch();
		int[] nums = {0,0,0,0,0,1,1,2,4,5};
		int target = 1;
		bs.binarySearch3(nums, target);
	}

	// 模板1:
	public int binarySearch(int[] nums, int target) {
		if (nums == null || nums.length == 0)
			return -1;

		int left = 0, right = nums.length - 1;
		while (left <= right) {
			// Prevent (left + right) overflow
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				//System.out.println("mid:"+mid);
				return mid;
			} else if (nums[mid] < target) {
				left = mid + 1;
				//System.out.println("left:"+left);
			} else {
				right = mid - 1;
				System.out.println("right:"+right);
			}
		}

		// End Condition: left > right
		return -1;
	}
	// 模板2:找不到target时，指针会停在target右侧
	public int binarySearch2(int[] nums, int target) {
		if (nums == null || nums.length == 0)
			return -1;

		int left = 0, right = nums.length;
		while (left < right) {
			// Prevent (left + right) overflow
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				//System.out.println("mid:"+mid);
				return mid;				
			} else if (nums[mid] < target) {
				left = mid + 1;
				//System.out.println("left:"+left);
			} else {
				right = mid;
				//System.out.println("right:"+right);
			}
		}
		// Post-processing:
		// End Condition: left == right
		if (left != nums.length && nums[left] == target) {
			System.out.println(left);
			return left;
		}
		return -1;
	}
	//模板3:找不到target时left和right会收缩在target两边,如果target小于最左边（0,1）,大于最右边(nums.length-2,length-1)
	public int binarySearch3(int[] nums, int target) {
	    if (nums == null || nums.length == 0)
	        return -1;

	    int left = 0;
	    int right = nums.length - 1;
	    while (left + 1 < right){
	        // Prevent (left + right) overflow
	        int mid = left + (right - left) / 2;
	        if (nums[mid] == target) {
	        	System.out.println("mid"+mid);
	            return mid;
	            
	        } else if (nums[mid] < target) {
	            left = mid;
	            System.out.println("left:"+left);
	        } else {	        	
	            right = mid;
	            System.out.println("right:"+right);
	        }
	    }

	    // Post-processing:
	    // End Condition: left + 1 == right
	    if(nums[left] == target) return left;
	    if(nums[right] == target) return right;
	    return -1;
	}

}
