package Leetcode_001_TwoSum;

import java.util.HashMap;
import java.util.Map;

/*
 	给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
	你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
	示例
		给定 nums = [2, 7, 11, 15], target = 9
		因为 nums[0] + nums[1] = 2 + 7 = 9
		所以返回 [0, 1]
 */
public class TwoSum {
	// 1.两数之和
	// 双索引对撞
	// 先排序后，后使用双索引对撞，时间复杂度为：O(n log n) + O(n) = O(n log n)， 可以试一试，也是可以 AC 的。
	public int[] twoSum3(int[] nums, int target) {
		return new int[] {-1,-1};
	}

	// 使用查找表
	// 将所有元素放入查找表，之后对于每一个元素 a，查找 target - a 是否存在。
	public int[] twoSum2(int[] nums, int target) {
		int[] result = { -1, -1 };
		Map<Integer, Integer> hm = new HashMap<Integer, Integer>();
		for (int i = 0; i < nums.length; i++) {
			int temp = target - nums[i];
			if (hm.containsKey(temp)) {
				result[0] = i;
				result[1] = hm.get(temp);
				return result;
			}
			hm.put(nums[i], i);
		}
		return result;
	}

	// 1刷
	// 暴力解法
	// 遍历所有数据对，判断是否等于 target，时间复杂度度 O(n^2)。
	public int[] twoSum(int[] nums, int target) {
		int[] result = new int[] { -1, -1 };
		for (int i = 0; i < nums.length - 1; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if (nums[i] + nums[j] == target) {
					result[0] = i;
					result[1] = j;
				}
			}
		}
		return result;
	}

}
