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
		// 左边的乘积
		int[] front = new int[nums.length];
		front[0] = nums[0];
		for (int i = 1; i < nums.length; i++) {
			front[i] = front[i - 1] * nums[i];
		}
		// 右边的乘积
		int[] behind = new int[nums.length];
		behind[nums.length - 1] = nums[nums.length - 1];
		for (int i = nums.length - 2; i >= 0; i--) {
			behind[i] = behind[i + 1] * nums[i];
		}
		// 结果数组
		nums[0] = behind[1];
		nums[nums.length - 1] = front[nums.length - 2];
		for (int i = 1; i < nums.length - 1; i++) {
			nums[i] = front[i - 1] * behind[i + 1];
		}
		return nums;
	}

	// O(n) without extra space
	public int[] productExceptSelf0(int[] nums) {

		int n = nums.length;
		int[] res = new int[n];
		res[0] = 1;
		for (int i = 1; i < n; i++) {
			res[i] = res[i - 1] * nums[i - 1];
		}
		int right = 1;
		for (int i = n - 1; i >= 0; i--) {
			res[i] *= right;
			right *= nums[i];
		}
		return res;
	}
}
