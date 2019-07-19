package Leetcode_039_CombinationSum;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
	给定一个无重复元素的数组 candidates 和一个目标数 target ，
	找出 candidates 中所有可以使数字和为 target 的组合	
	candidates 中的数字可以无限制重复被选取。
	
	说明：	
		所有数字（包括 target）都是正整数。
		解集不能包含重复的组合。 
	示例 1:	
		输入: candidates = [2,3,6,7], target = 7,
		所求解集为:
		[
		  [7],
		  [2,2,3]
		]
	示例 2:	
		输入: candidates = [2,3,5], target = 8,
		所求解集为:
		[
		  [2,2,2,2],
		  [2,3,3],
		  [3,5]
		]
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/combination-sum
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//39. 组合总和
public class CombinationSum {
	List<List<Integer>> res = new ArrayList<>();
	int[] candidates;
	int target;

	public List<List<Integer>> combinationSum(int[] candidates, int target) {
		if (candidates == null || candidates.length == 0) {
			return res;
		}
		this.candidates = candidates;
		this.target = target;
		getCombination(0, 0, new LinkedList<Integer>());
		return res;
	}

	private void getCombination(int start, int sum, LinkedList<Integer> list) {
		if (sum == target) {
			res.add(new ArrayList<Integer>(list));
		}

		for (int i = start; i < candidates.length; i++) {
			if (sum + candidates[i] <= target) {
				list.add(candidates[i]);
				getCombination(i, sum + candidates[i], list);
				list.removeLast();
			}
		}
	}

}
