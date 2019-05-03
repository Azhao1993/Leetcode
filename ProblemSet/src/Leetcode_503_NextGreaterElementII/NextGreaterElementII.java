package Leetcode_503_NextGreaterElementII;

import java.util.Arrays;
import java.util.Stack;

/*
	给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），
	输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，
	这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
	如果不存在，则输出 -1。
	
	示例 1:	
		输入: [1,2,1]
		输出: [2,-1,2]
		解释: 第一个 1 的下一个更大的数是 2；
		数字 2 找不到下一个更大的数； 
		第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
	注意: 输入数组的长度不会超过 10000。
 */
//503. 下一个更大元素 II
public class NextGreaterElementII {
	public static void main(String[] args) {
		int[] nums = { 1, 2, 1 };
		new NextGreaterElementII().nextGreaterElements(nums);
	}

	public int[] nextGreaterElements(int[] nums) {
		int length = nums.length;
		int[] res = new int[length];
		Arrays.fill(res, -1);
		Stack<int[]> stack = new Stack<>();
		for (int i = 0; i < length * 2; i++) {
			int n = nums[i % length];
			while (!stack.isEmpty() && stack.peek()[0] < n) {
				res[stack.peek()[1]] = n;
				stack.pop();
			}
			stack.push(new int[] { n, i % length });
		}
		return res;
	}

	// 6ms
	public int[] nextGreaterElements0(int[] nums) {
		int[] stack = new int[nums.length * 2];
		// a = nums*2
		int[] a = new int[nums.length * 2];
		// 结果
		int[] res = new int[nums.length];
		for (int i = 0; i < nums.length; i++) {
			a[i] = a[i + nums.length] = nums[i];
		}
		Arrays.fill(res, -1);
		int top = 0;
		int j = 0;
		while (j < a.length) {
			if (top == 0) {
				stack[top++] = j;
			} else {
				while (top > 0 && a[j] > a[stack[top - 1]]) {
					if (stack[top - 1] >= nums.length)
						res[stack[top - 1] - nums.length] = a[j];
					else
						res[stack[top - 1]] = a[j];
					top--;
				}
				stack[top++] = j;
			}
			j++;
		}
		return res;
	}
}
