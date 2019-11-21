package Leetcode_268_MissingNumber;

/*
	给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
	
	示例 1:	
		输入: [3,0,1]
		输出: 2
	
	示例 2:	
		输入: [9,6,4,2,3,5,7,0,1]
		输出: 8
	说明:
		你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 */
public class MissingNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 268. 缺失数字
	public int missingNumber(int[] nums) {
		int length = nums.length;
		// 定义数组的总和
		int numssum = 0;
		// 定义全序列的总和
		int sum = 0;
		for (int i = 1; i < length + 1; i++) {
			sum += i;
			numssum += nums[i - 1];
		}
		return (sum - numssum);
	}

}
