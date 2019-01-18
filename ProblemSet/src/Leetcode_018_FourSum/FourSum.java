package Leetcode_018_FourSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
	给定一个包含 n 个整数的数组 nums 和一个目标值 target，
	判断 nums 中是否存在四个元素 a，b，c 和 d ，
	使得 a + b + c + d 的值与 target 相等？
	找出所有满足条件且不重复的四元组。
	
	注意：	
		答案中不可以包含重复的四元组。
	
	示例：	
		给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
	
	满足要求的四元组集合为：
		[
		  [-1,  0, 0, 1],
		  [-2, -1, 1, 2],
		  [-2,  0, 0, 2]
		]
 */
public class FourSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 18. 四数之和
	public List<List<Integer>> fourSum(int[] nums, int target) {
		ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
		int len = nums.length;
		if (nums == null || len < 4) {
			return res;
		}

		Arrays.sort(nums);
		// 最大值
		int max = nums[len - 1];
		// 最小值太大，最大值太小
		if (4 * nums[0] > target || 4 * max < target) {
			return res;
		}

		int i;// 第一个数的索引i
		int z;// 第一个数nums[i]
		for (i = 0; i < len; i++) {
			z = nums[i];
			// 与前一个数重复
			if (i > 0 && z == nums[i - 1])
				continue;
			// z太小
			if (z + 3 * max < target)
				continue;
			// z太大
			if (4 * z > target)
				break;
			// 存在4个相同的z且满足条件
			if (4 * z == target) { // z is the boundary
				if (i + 3 < len && nums[i + 3] == z)
					res.add(Arrays.asList(z, z, z, z));
				break;
			}

			// 在数组nums中找到3个数和为target-z,索引位置为从i+1,len-1,找到后与第一个数z返回到res
			threeSumForFourSum(nums, target - z, i + 1, len - 1, res, z);
		}

		return res;
	}

	/*
	 * Find all possible distinguished three numbers adding up to the target in
	 * sorted array nums[] between indices low and high. If there are, add all of
	 * them into the ArrayList fourSumList, using fourSumList.add(Arrays.asList(z1,
	 * the three numbers))
	 */
	public void threeSumForFourSum(int[] nums, int target, int low, int high, ArrayList<List<Integer>> fourSumList,
			int z1) {
		// 长度不够3
		if (low + 1 >= high) {
			return;
		}
		// 最大值是max
		int max = nums[high];
		// 最小值太大，最大值太小
		if (3 * nums[low] > target || 3 * max < target) {
			return;
		}
		int i;// 第二个数的索引
		int z;// 第二个数z
		for (i = low; i < high - 1; i++) {
			z = nums[i];
			// avoid duplicate
			if (i > low && z == nums[i - 1]) {
				continue;
			}
			// z is too small
			if (z + 2 * max < target) {
				continue;
			}
			// z is too large
			if (3 * z > target) {
				break;
			}
			// z is the boundary
			if (3 * z == target) {
				if (i + 1 < high && nums[i + 2] == z)
					fourSumList.add(Arrays.asList(z1, z, z, z));
				break;
			}
			// 在nums的[i+1,high]的范围内找到两个数的和为target-z,第一个数为z1,第二个数为z,添加到结果fourSumList中
			twoSumForFourSum(nums, target - z, i + 1, high, fourSumList, z1, z);
		}

	}

	/*
	 * Find all possible distinguished two numbers adding up to the target in sorted
	 * array nums[] between indices low and high. If there are, add all of them into
	 * the ArrayList fourSumList, using fourSumList.add(Arrays.asList(z1, z2, the
	 * two numbers))
	 */
	public void twoSumForFourSum(int[] nums, int target, int low, int high, ArrayList<List<Integer>> fourSumList,
			int z1, int z2) {
		// 长度不够2
		if (low >= high) {
			return;
		}
		// 最小值太大，最大值太小
		if (2 * nums[low] > target || 2 * nums[high] < target) {
			return;
		}
		int i = low;// 最小值的索引
		int j = high;// 最大值的索引
		int sum;// 两数之和
		int x;
		while (i < j) {
			sum = nums[i] + nums[j];
			if (sum == target) {
				fourSumList.add(Arrays.asList(z1, z2, nums[i], nums[j]));
				// avoid duplicate
				x = nums[i];
				while (++i < j && x == nums[i])
					;
				// avoid duplicate
				x = nums[j];
				while (i < --j && x == nums[j])
					;
			}
			if (sum < target)
				i++;
			if (sum > target)
				j--;
		}
		return;
	}

}
