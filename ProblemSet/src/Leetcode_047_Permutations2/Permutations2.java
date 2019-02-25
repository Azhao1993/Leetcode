package Leetcode_047_Permutations2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
	给定一个可包含重复数字的序列，返回所有不重复的全排列。
	
	示例:
	输入:
		[1,1,2]
	输出:
		[
		  [1,1,2],
		  [1,2,1],
		  [2,1,1]
		]
 */

//47. 全排列 II
public class Permutations2 {
	public static void main(String[] args) {
		int[] nums = { 3, 3, 0, 3 };
		Permutations2 p2 = new Permutations2();
		p2.permuteUnique(nums);
	}

	public List<List<Integer>> permuteUnique(int[] nums) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		if (nums == null || nums.length == 0) {
			return result;
		}
		boolean[] used = new boolean[nums.length];
		List<Integer> list = new ArrayList<Integer>();
		Arrays.sort(nums);
		dfs(nums, used, list, result);
		return result;

	}

	private void dfs(int[] nums, boolean[] used, List<Integer> list, List<List<Integer>> result) {
		if (list.size() == nums.length) {
			result.add(new ArrayList<Integer>(list));
			return;
		}
		for (int i = 0; i < nums.length; i++) {
			if (used[i]) {
				continue;
			}
			// nums[i] == nums[i - 1] 但nums[i-1]未用，说明情况相同
			if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
				continue;
			}
			list.add(nums[i]);
			used[i] = true;
			dfs(nums, used, list, result);
			used[i] = false;
			list.remove(list.size() - 1);
		}

	}
}
