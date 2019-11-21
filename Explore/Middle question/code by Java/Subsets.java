package Leetcode_078_Subsets;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
	给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。	
	说明：解集不能包含重复的子集。	
	示例:	
		输入: 
			nums = [1,2,3]
		输出:
			[
			  [3],
			  [1],
			  [2],
			  [1,2,3],
			  [1,3],
			  [2,3],
			  [1,2],
			  []
			]
 */

//78. 子集
public class Subsets {
	public static void main(String[] args) {
		int[] nums = {1,2,3};
		Subsets s = new Subsets();
		s.subsets(nums);
	}
	public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> list = new ArrayList<>();
		Arrays.sort(nums);
		backtrack(list, new ArrayList<>(), nums, 0);
		return list;
	}

	private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int start) {
		list.add(new ArrayList<>(tempList));
		for (int i = start; i < nums.length; i++) {
			tempList.add(nums[i]);
			backtrack(list, tempList, nums, i + 1);
			tempList.remove(tempList.size() - 1);
		}
	}
}
