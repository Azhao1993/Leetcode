package Leetcode_941_ValidMountainArray;

/*
	给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。	
	让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：	
		A.length >= 3
		在 0 < i < A.length - 1 条件下，存在 i 使得：
			A[0] < A[1] < ... A[i-1] < A[i]
			A[i] > A[i+1] > ... > A[B.length - 1]	 
	
	示例 1：	
		输入：[2,1]
		输出：false
	
	示例 2：	
		输入：[3,5,5]
		输出：false
	
	示例 3：	
		输入：[0,3,2,1]
		输出：true	 
	
	提示：	
		0 <= A.length <= 10000
		0 <= A[i] <= 10000 
 */
public class ValidMountainArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ValidMountainArray vma = new ValidMountainArray();
		int[] A = { 0, 3, 2, 1 };
		System.out.println(vma.validMountainArray(A));
	}

	// 941. 有效的山脉数组(4ms)
	public boolean validMountainArray(int[] A) {
		int srcIndex = 0;
		if (A == null || A.length < 3) {
			return false;
		}
		// 上山
		for (int i = 0; i < A.length - 1; i++) {
			if (A[i] < A[i + 1]) {
				continue;
			}
			if (A[i] == A[i + 1]) {
				return false;
			}
			srcIndex = i;
			break;
		}
		// 悬崖
		if (srcIndex == 0 || srcIndex == A.length - 1) {
			return false;
		}
		// 下山
		for (int i = srcIndex + 1; i < A.length - 1; i++) {
			if (A[i] <= A[i + 1]) {
				return false;
			}
		}
		return true;
	}

	// 5ms
	public boolean validMountainArray2(int[] A) {
		if (A.length < 3) {
			return false;
		}
		// 找最大值的索引
		int index = 0;
		for (int i = 1; i < A.length; i++) {
			if (A[index] <= A[i]) {
				index = i;
			}
		}
		if ((index == 0) || (index == A.length - 1)) {
			return false;
		}
		for (int i = 0; i < index; i++) {
			if (A[i] > A[i + 1]) {
				return false;
			}
		}
		for (int i = index + 1; i < A.length; i++) {
			if (A[i - 1] < A[i]) {
				return false;
			}
		}
		return true;

	}

}
