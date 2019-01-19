package Leetcode_015_ThreeSum;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	给定一个包含 n 个整数的数组 nums，
	判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找
	出所有满足条件且不重复的三元组。
	
	注意：答案中不可以包含重复的三元组。
	
	例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
	
	满足要求的三元组集合为：
	[
	  [-1, 0, 1],
	  [-1, -1, 2]
	]
 */
public class ThreeSum {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}

	// 15. 三数之和
	public List<List<Integer>> threeSum(int[] nums) {		
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		Map<Integer,Integer> map = new HashMap<Integer,Integer>();
		for(int temp:nums) {
			map.put(temp, map.getOrDefault(temp, 0)+1);
		}
		
		return result;
	}

}
