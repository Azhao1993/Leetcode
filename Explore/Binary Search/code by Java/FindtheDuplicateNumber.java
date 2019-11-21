package Leetcode_287_FindtheDuplicateNumber;

/*
	给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
	假设只有一个重复的整数，找出这个重复的数。
	
	示例 1:
		输入: [1,3,4,2,2]
		输出: 2
	示例 2:	
		输入: [3,1,3,4,2]
		输出: 3
	说明：	
		不能更改原数组（假设数组是只读的）。
		只能使用额外的 O(1) 的空间。
		时间复杂度小于 O(n^2) 。
		数组中只有一个重复的数字，但它可能不止重复出现一次。
*/
public class FindtheDuplicateNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FindtheDuplicateNumber fdn = new FindtheDuplicateNumber();
		int[] nums = { 0, 1, 3, 4, 4 };
		System.out.println(fdn.findDuplicate(nums));
	}

	// 287. 寻找重复数
	public int findDuplicate(int[] nums) {
		for (int i = 0; i < nums.length; i++) {
			// 让对应的数字交换到自己数字对应的位置
			while (nums[i] != i) {
				if (nums[i] == nums[nums[i]]) {
					return nums[i];
				}
				swap(nums, i, nums[i]);
			}
		}
		return -1;
	}

	public void swap(int[] nums, int x, int y) {
		int temp = nums[x];
		nums[x] = nums[y];
		nums[y] = temp;
	}

	// 暴力搜索
	public int findDuplicate2(int[] nums) {
		int result = -1;
		for (int i = 1; i < nums.length; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] == nums[j]) {
					return nums[i];
				}
			}
		}
		return result;
	}
}
