package Leetcode_303_RangeSumQueryImmutable;

import UsualMethod.matrixOutput;

/*
	给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
	
	示例：
		给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()		
		sumRange(0, 2) -> 1
		sumRange(2, 5) -> -1
		sumRange(0, 5) -> -3
	说明:
		你可以假设数组不可变。
		会多次调用 sumRange 方法。
*/
public class NumArray {
	/**
	 * Your NumArray object will be instantiated and called as such:
	 *  NumArray obj =new NumArray(nums); 
	 *  int param_1 = obj.sumRange(i,j);
	 */
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] nums = { -2, 0, 3, -5, 2, -1 };
		NumArray obj = new NumArray(nums);
		int param_1 = obj.sumRange(0, 2);
		int param_2 = obj.sumRange(2, 5);
		int param_3 = obj.sumRange(0, 5);
		System.out.println("1:" + param_1);
		System.out.println("-1:" + param_2);
		System.out.println("-3:" + param_3);
	}

	// 303. 区域和检索 - 数组不可变
	// 定义成员变量
	private int[] arr;

	// 构造方法
	public NumArray(int[] nums) {
		arr = new int[nums.length];
		arr[0]=nums[0];
		for(int i=1;i<nums.length;i++ ) {
			arr[i]=arr[i-1]+nums[i];
		}
		//输出一维数组
		new matrixOutput().ArrayOutput(arr);
	}

	public int sumRange(int i, int j) {
		if(i==0) {
			return arr[j];
		}else {
			return arr[j]-arr[i-1];
		}
		
		
	}

}
