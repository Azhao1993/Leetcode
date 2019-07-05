package Leetcode_217_ContainsDuplicate;

import java.util.HashSet;
import java.util.Set;

//import java.lang.reflect.Array;
//import java.util.HashSet;
//import java.util.Set;

/*

	给定一个整数数组，判断是否存在重复元素。	
	如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
	
	示例 1:	
		输入: [1,2,3,1]
		输出: true
		
	示例 2:	
		输入: [1,2,3,4]
		输出: false
		
	示例 3:	
		输入: [1,1,1,3,3,4,3,2,4,2]
		输出: true	
*/
public class ContainsDuplicate {
	// 217. 存在重复元素
	public boolean containsDuplicate(int[] nums) {
		if (nums != null && nums.length > 1) {
			Set<Integer> set = new HashSet<Integer>(nums.length);
			for (int i : nums) {
				if (set.contains(i)) {
					return true;
				} else {
					set.add(i);
				}
			}
		}
		return false;
	}

	// 暴力解法
	public boolean containsDuplicate2(int[] nums) {
		// 长度为0或1肯定问false
		if (nums.length == 0 || nums.length == 1) {
			return false;
		}
		// 依次查找前面的数
		for (int i = 1; i < nums.length; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] == nums[j]) {
					return true;
				}
			}
		}
		return false;
	}

}
