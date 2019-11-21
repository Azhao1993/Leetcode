package Leetcode_739_DailyTemperatures;

import java.util.Arrays;

/*
	根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 0 来代替。
	
	例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
					  你的输出应该是   [ 1,  1,  4,  2,  1,  1,  0,  0]。
	
	提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。
 */
public class DailyTemperatures {
	public static void main(String[] args) {
		int[] T = { 73, 74, 75, 71, 69, 72, 76, 73 };
		Arrays.toString(new DailyTemperatures().dailyTemperatures(T));
	}

	// 739. 每日温度
	public int[] dailyTemperatures(int[] T) {
		if (T.length == 1) {
			return new int[] { 0 };
		}
		int[] result = new int[T.length];
		for (int i = 0; i < T.length; i++) {
			int res = 0;
			for (int j = i + 1; j < T.length; j++) {
				if (T[j] > T[i]) {
					res++;
					break;
				} else if (j == T.length - 1) {
					res = 0;
					break;
				} else {
					res++;
				}
			}
			result[i] = res;
		}
		return result;
	}

	// 7ms
	public int[] dailyTemperatures0(int[] T) {
		if (T == null || T.length == 0)
			return T;
		int[] result = new int[T.length];
		int[] stack = new int[T.length]; // 用int数组代替stack
		int top = -1;
		for (int i = 0; i < T.length; i++) {
			while (top > -1 && T[i] > T[stack[top]]) {
				int index = stack[top--];
				result[index] = i - index;
			}
			stack[++top] = i;
		}
		return result;
	}
}
