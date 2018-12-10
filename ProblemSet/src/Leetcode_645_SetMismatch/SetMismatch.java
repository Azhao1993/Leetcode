package Leetcode_645_SetMismatch;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
	集合 S 包含从1到 n 的整数。
	不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。	
	给定一个数组 nums 代表了集合 S 发生错误后的结果。
	你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
	
	示例 1:	
		输入: nums = [1,2,2,4]
		输出: [2,3]
	
	注意:	
		给定数组的长度范围是 [2, 10000]。
		给定的数组是无序的。
 */
public class SetMismatch {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] nums = { 1, 2, 2, 4 };
		new SetMismatch().findErrorNums(nums);
	}

	// 645. 错误的集合
	public int[] findErrorNums(int[] nums) {
		int[] result = new int[2];
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int key : nums) {
			if (map.containsKey(key)) {
				result[0] = key;
			} else {
				map.put(key, key);
			}
		}
		for (int i = 1; i <= nums.length; i++) {
			if (!map.containsKey(i)) {
				result[1] = i;
				break;
			}
		}

		return result;

	}

	// 5ms
	public int[] findErrorNums0(int[] nums) {
		int[] nums2 = new int[nums.length + 1];
		for (int i = 0; i < nums.length; i++) {
			nums2[nums[i]]++;
		}
		int repeat = 0, lose = 0;
		for (int i = 1; i < nums2.length; i++) {
			if (nums2[i] == 2)
				repeat = i;
			else if (nums2[i] == 0)
				lose = i;
			if (repeat != 0 && lose != 0)
				break;
		}
		return new int[] { repeat, lose };
	}

}
