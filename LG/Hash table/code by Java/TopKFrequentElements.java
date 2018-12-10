package Leetcode_347_TopKFrequentElements;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
	
	示例 1:	
		输入: nums = [1,1,1,2,2,3], k = 2
		输出: [1,2]
	
	示例 2:	
		输入: nums = [1], k = 1
		输出: [1]
	说明：	
		你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
		你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 */
public class TopKFrequentElements {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TopKFrequentElements tfe = new TopKFrequentElements();
		int[] nums = { 1 };
		int k = 1;
		tfe.topKFrequent(nums, k);
	}

	// 347. 前K个高频元素
	public List<Integer> topKFrequent(int[] nums, int k) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < nums.length; i++) {
			if (map.containsKey(nums[i])) {
				int value = map.get(nums[i]) + 1;
				map.put(nums[i], value);
			} else {
				map.put(nums[i], 1);
			}

		}
		List<Integer> list = new ArrayList<Integer>();
		for (int i = nums.length; i >= 1; i--) {
			for (Integer num : map.keySet()) {
				if (map.get(num) == i) {
					list.add(num);
					if (list.size() == k) {
						return list;
					}
				}
			}
		}
		return list;
	}

	// 2ms
	public List<Integer> topKFrequent0(int[] nums, int k) {
		if (nums == null || nums.length == 0)
			return null;
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;

		for (int i : nums) {
			if (i < min)
				min = i;
			if (i > max)
				max = i;
		}

		int[] count = new int[max - min + 1]; // 各个数字出现的频数

		for (int i : nums) {
			count[i - min]++;
		}

		int max_count = Integer.MIN_VALUE;

		for (int i : count) {
			if (i > max_count)
				max_count = i;
		}

		int[] aid = new int[max_count + 1]; // 各个频数所包含的key数

		for (int i : count) {
			if (i > 0) {
				aid[i]++;
			}
		}

		int min_count = 1;
		int curr = 0;
		for (int i = aid.length - 1; i >= 1; i--) {
			if (aid[i] > 0) {
				curr += aid[i];
				if (curr >= k) {
					min_count = i;
					break;
				}
			}
		}

		List<Integer> ans = new ArrayList<>(k);
		for (int i = 0; i < count.length; i++) {
			if (count[i] >= min_count) {
				ans.add(i + min);
			}
		}
		return ans;

	}

}
