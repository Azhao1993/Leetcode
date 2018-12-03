package Leetcode_922_SortArrayByParity2;

import java.util.Arrays;

/*
	给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。	
	对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。	
	你可以返回任何满足上述条件的数组作为答案。 
	
	示例：	
		输入：[4,2,5,7]
		输出：[4,5,2,7]
		解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。	 
	
	提示：	
		2 <= A.length <= 20000
		A.length % 2 == 0
		0 <= A[i] <= 1000
 */
public class SortArrayByParity2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SortArrayByParity2 sab2 = new SortArrayByParity2();
		int[] A = { 4,2,5,7 };
		sab2.sortArrayByParityII(A);
		System.out.println(Arrays.toString(A));
	}

	// 922. 按奇偶排序数组 II
	public int[] sortArrayByParityII(int[] A) {
		// i只判断偶数位
		int j = 1;// j只判断奇数位
		for (int i = 0; i < A.length - 1; i = i + 2) {
			// 如果A[i]是奇数
			if (A[i] % 2 == 1) {
				while (j < A.length) {
					// 如果A[j]是偶数
					if (A[j] % 2 == 0) {
						int temp = A[i];
						A[i] = A[j];
						A[j] = temp;
						break;
					} else {
						j += 2;
					}
				}
			}
		}
		return A;
	}

	// 5ms
	public int[] sortArrayByParityII2(int[] A) {
		int j = 1;
		// 只判断偶数位
		for (int i = 0; i < A.length - 1; i = i + 2) {
			// 如果是奇数
			if ((A[i] & 1) != 0) {
				// 只判断奇数位
				while ((A[j] & 1) != 0) {
					// 如果是奇数
					j = j + 2;
				}
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
		return A;
	}

}
