package Leetcode_977_SquaresofaSortedArray;

import java.util.Arrays;

/*
	给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。 
	
	示例 1：
		输入：[-4,-1,0,3,10]
		输出：[0,1,9,16,100]
	
	示例 2：
		输入：[-7,-3,2,3,11]
		输出：[4,9,9,49,121]
	
	提示：
		1 <= A.length <= 10000
		-10000 <= A[i] <= 10000
		A 已按非递减顺序排序。
 */

//有序数组的平方
public class SquaresofaSortedArray {
	public int[] sortedSquares(int[] A) {
		// ArrayList<Integer> list = new ArrayList();
		int[] result = new int[A.length];
		for (int i = 0; i < A.length; i++) {
			result[i] = A[i] * A[i];
		}
		Arrays.sort(result);
		return result;
	}

	// O(N)
	public int[] sortedSquares0(int[] A) {
		int n = A.length;// 长度
		int[] result = new int[n];
		int i = 0;// 头指针
		int j = n - 1;// 尾指针
		for (int p = n - 1; p >= 0; p--) {
			// 绝对值越大，平方越大
			if (Math.abs(A[i]) > Math.abs(A[j])) {
				// 前面的大
				result[p] = A[i] * A[i];
				i++;
			} else {
				// 后面的大
				result[p] = A[j] * A[j];
				j--;
			}
		}
		return result;
	}
}
