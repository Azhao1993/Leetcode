package Leetcode_1133_LargestUniqueNumber;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.TreeMap;

/*
	给你一个整数数组 A，请找出并返回在该数组中仅出现一次的最大整数。
	如果不存在这个只出现一次的整数，则返回 -1。
	
	示例 1：
		输入：[5,7,3,9,4,9,8,3,1]
		输出：8
		解释： 
			数组中最大的整数是 9，但它在数组中重复出现了。而第二大的整数是 8，它只出现了一次，所以答案是 8。
	示例 2：
		输入：[9,9,8,8]
		输出：-1
		解释： 
			数组中不存在仅出现一次的整数。
	
	提示：
		1 <= A.length <= 2000
		0 <= A[i] <= 1000
 */
public class LargestUniqueNumber {
	public int largestUniqueNumber1(int[] A) {
		TreeMap<Integer, Integer> map = new TreeMap<>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return o2 - o1;
			}
		});
		for (int i : A) {
			map.put(i, map.getOrDefault(i, 0) + 1);
		}
		for (Integer key : map.keySet()) {
			if (map.get(key) == 1) {
				return key;
			}
		}
		return -1;

	}

	public int largestUniqueNumber(int[] A) {
		if (A == null) {
			return -1;
		}
		if (A.length == 1) {
			return A[0];
		}
		Arrays.sort(A);
		Stack<Integer> stack = new Stack<>();
		boolean flag = false;
		int res = -1;
		for (int i = A.length - 1; i >= 0; i--) {
			if (stack.isEmpty()) {
				stack.push(A[i]);
			} else if (A[i] == stack.peek()) {
				flag = true;// 重复
			} else if (A[i] != stack.peek()) {
				if (!flag) {
					res = stack.peek();
					break;
				}
				stack.pop();
				flag = false;// false
				stack.push(A[i]);
			}
		}
		if (!stack.isEmpty() && !flag) {
			res = stack.peek();
		}
		return res;
	}
}
