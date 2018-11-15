package Leetcode_485_MaxConsecutiveOnes;

/*
	给定一个二进制数组， 计算其中最大连续1的个数。

	示例 1:		
		输入: [1,1,0,1,1,1]
		输出: 3
		解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
		
	注意：	
		输入的数组只包含 0 和1。
		输入数组的长度是正整数，且不超过 10,000。
*/
public class MaxConsecutiveOnes {
	//485. 最大连续1的个数
	public int findMaxConsecutiveOnes(int[] nums) {
		// 定义零开始的位置
		int zerobeginindex = -1;
		// 定义零结束的位置
		int zeroendindex = -1;
		// 定义1的长度
		int onelength = 0;
		int length = 0;

		// 遍历数组,找出零的位置
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == 0) {
				zerobeginindex = zeroendindex;
				zeroendindex = i;
				System.out.print("开始位置：" + zerobeginindex + ", ");
				System.out.print("结束位置：" + zeroendindex + ", ");
				length = (zeroendindex - zerobeginindex - 1);
				System.out.println("1的长度为：" + length);
				// 判断长度是否更长
				if (length > onelength) {
					onelength = length;
					System.out.println("1的长度为：" + length);
				}

			}
			// 判断最后一位非零情况
			if (i == nums.length - 1) {
				length = (nums.length - 1 - zeroendindex);
				// 判断长度是否更长
				if (length > onelength) {
					onelength = length;
					System.out.println("1的长度为：" + length);
				}
			}

		}
		return onelength;
	}
}
