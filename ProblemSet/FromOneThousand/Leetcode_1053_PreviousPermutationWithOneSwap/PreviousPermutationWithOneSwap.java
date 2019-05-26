package Leetcode_1053_PreviousPermutationWithOneSwap;

import java.util.Arrays;
import java.util.Stack;
/*
	给你一个正整数的数组 A（其中的元素不一定完全不同），
	请你返回可在 一次交换（交换两数字 A[i] 和 A[j] 的位置）后得到的、按字典序排列小于 A 的最大可能排列。
	
	如果无法这么操作，就请返回原数组。
	
	示例 1：	
		输入：[3,2,1]
		输出：[3,1,2]
		解释：
			交换 2 和 1	
	示例 2：	
		输入：[1,1,5]
		输出：[1,1,5]
		解释： 
			这已经是最小排列	
	示例 3：	
		输入：[1,9,4,6,7]
		输出：[1,7,4,6,9]
		解释：
			交换 9 和 7	
	示例 4：	
		输入：[3,1,1,3]
		输出：[1,1,3,3]
	
	提示：	
		1 <= A.length <= 10000
		1 <= A[i] <= 10000
 */

//1053. 交换一次的先前排列
public class PreviousPermutationWithOneSwap {

	public static void main(String[] args) {
		
	}

	public int[] prevPermOpt12(int[] A) {
		if (A.length == 1) {
			return A;
		}		
		for (int i = A.length - 2; i >= 0 ; i--) {
			for(int j = A.length-1;j>i;j--) {
				if (A[i] > A[j]) {
					int temp = A[i];
					A[i] = A[j];
					A[j] = temp;
					return A;
				} 
			}
			
		}
		return A;
	}

	public int[] prevPermOpt1(int[] A) {
		int[] arr = Arrays.copyOf(A, A.length);
		Stack<int[]> sta = new Stack<int[]>();
		for (int i = A.length - 1; i >= 0; i--) {
			if (sta.isEmpty() || A[i] <= sta.peek()[0]) {
				sta.push(new int[] { A[i], i });
			} else {
				int[] tem = new int[2];
				while (!sta.isEmpty() && A[i] > sta.peek()[0]) {
					tem = sta.pop();
				}
				int temp = arr[i];
				arr[i] = arr[tem[1]];
				arr[tem[1]]=temp;
				return arr;
			}
		}
		return arr;
	}

}
