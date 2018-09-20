package Leetcode_238_ProductofArrayExceptSelf;

/*	
	给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
	
	示例:	
		输入: [1,2,3,4]
		输出: [24,12,8,6]
	说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
	
	进阶：
		你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/
public class ProductofArrayExceptSelf {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 238. 除自身以外数组的乘积
	public int[] productExceptSelf(int[] nums) {
		
		int[] result = new int[nums.length];
		// 前部分和后部分
		for (int i = 0; i < nums.length; i++) {
			result[i] = 1;
			// i的前半部分
			for (int m = 0; m < i; m++) {
				result[i] *= nums[m];
			}
			// i的后半部分
			for (int m = i+1; m < nums.length; m++) {
				result[i] *= nums[m];
			}
		}
		return result;
	}
}
