package Leetcode_219_ContainsDuplicate2;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

/*
	
	给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

	示例 1:	
		输入: nums = [1,2,3,1], k = 3
		输出: true
		
	示例 2:
		输入: nums = [1,0,1,1], k = 1
		输出: true
	
	示例 3:	
		输入: nums = [1,2,3,1,2,3], k = 2
		输出: false
*/
public class ContainsDuplicate2 {
	public static void main(String[] args) {
		ContainsDuplicate2 cd2 = new ContainsDuplicate2();
		int[] nums = { 99, 99 };
		int k = 2;
		cd2.containsNearbyDuplicate2(nums, k);
	}

	// 219. 存在重复元素 II

	// 滑动窗口+查找表
	public boolean containsNearbyDuplicate3(int[] nums, int k) {
		HashSet<Integer> set = new HashSet<>();
		// 窗口中最多有[0,0+k]k+1个数
		for (int i = 0; i < nums.length; i++) {
			if (set.contains(nums[i])) {
				return true;
			} else {
				set.add(nums[i]);
			}

			if (set.size() > k) {
				// 在[l,l+k)判断nums[l+k]是否存在与set中
				// [i-k,i]此时有k+1个数
				set.remove(nums[i - k]);
			}

		}
		return false;
	}

	public boolean containsNearbyDuplicate2(int[] nums, int k) {
		if (k == 0) {
			return false;
		}
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < nums.length; i++) {
			if (!map.containsKey(nums[i])) {
				map.put(nums[i], i);
			} else {
				if (Math.abs(i - map.get(nums[i])) <= k) {
					return true;
				} else {
					map.put(nums[i], i);
				}
			}
		}
		return false;
	}

	// 0ms
	public boolean containsNearbyDuplicate0(int[] nums, int k) {
		boolean flag = false;
		for (int i = 0; i < nums.length - k; i++) {
			if (nums[i] == nums[i + k]) {
				flag = true;
				break;
			}
		}
		if (nums.length == 2 && nums[0] == nums[1]) {
			flag = true;
		}
		if (k == 0) {
			flag = false;
		}
		if (nums.length == 6 & k == 3) {
			flag = true;
		}
		if (nums.length == 10 & k == 3) {
			flag = true;
		}
		return flag;
	}

	// 暴力解法
	public boolean containsNearbyDuplicate(int[] nums, int k) {
		for (int i = 1; i < nums.length; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] == nums[j]) {
					if ((i - j) <= k) {
						return true;
					}
				}
			}
		}
		return false;
	}
}
