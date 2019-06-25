package Leetcode_041_FirstMissingPositive;

import java.util.HashSet;

/*
	给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
	
	示例 1:	
		输入: [1,2,0]
		输出: 3
	示例 2:	
		输入: [3,4,-1,1]
		输出: 2
	示例 3:	
		输入: [7,8,9,11,12]
		输出: 1
	说明:	
		你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/first-missing-positive
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//41. 缺失的第一个正数
public class FirstMissingPositive {

	public static void main(String[] args) {
		int[] nums = { 3, 4, -1, 1 };
		new FirstMissingPositive().firstMissingPositive1(nums);

	}

	// 时间复杂度：O(2N)
	// 空间复杂度：O(N)
	public int firstMissingPositive0(int[] nums) {
		HashSet<Integer> set = new HashSet<>();
		for (int i : nums) {
			if (i > 0) {
				set.add(i);
			}
		}
		int i = 1;
		while (set.contains(i)) {
			i++;
		}
		return i;
	}

	//
	public int firstMissingPositive1(int[] nums) {
		for (int i = 0; i < nums.length;) {
			if (nums[i] <= 0 || nums[i] > nums.length) {
				nums[i] = 0;
				i++;
			} else if (nums[i] == i + 1) {
				i++;
				continue;
			} else if (nums[nums[i] - 1] == nums[i] || nums[nums[i] - 1] == 0) {
				nums[nums[i] - 1] = nums[i];
				nums[i] = 0;
				i++;
			} else {
				int temp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = temp;
			}
		}
		int i = 1;
		while (i <= nums.length && nums[i - 1] == i) {
			i++;
		}
		return i;
	}

}
