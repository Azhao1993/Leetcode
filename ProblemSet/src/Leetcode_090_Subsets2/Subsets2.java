package Leetcode_090_Subsets2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/*
	给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。	
	说明：解集不能包含重复的子集。	
	示例:
		输入:
			[1,2,2]
		输出:
			[
			  [2],
			  [1],
			  [1,2,2],
			  [2,2],
			  [1,2],
			  []
			]
 */

//90. 子集 II
public class Subsets2 {

	List<List<Integer>> res = new ArrayList<>();
	int[] nums;

	public List<List<Integer>> subsetsWithDup(int[] nums) {
		if (nums == null || nums.length == 0) {
			res.add(new ArrayList<>());
			return res;
		}
		Arrays.sort(nums);
		this.nums = nums;

		getSubsetsWithDup(0, new LinkedList<Integer>());
		return res;
	}

	private void getSubsetsWithDup(int start, LinkedList<Integer> list) {
		res.add(new ArrayList<>(list));
		for (int i = start; i < nums.length; i++) {
			if (i > start && nums[i] == nums[i - 1]) {
				continue;
			}
			list.add(nums[i]);
			getSubsetsWithDup(i + 1, list);
			list.removeLast();
		}

	}

}
