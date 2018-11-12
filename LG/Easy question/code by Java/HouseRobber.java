package Leetcode_198_HouseRobber;

/*
	你是一个专业的小偷，计划偷窃沿街的房屋。
	每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
	
	给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
	
	示例 1:	
		输入: [1,2,3,1]
		输出: 4
		解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
		     偷窃到的最高金额 = 1 + 3 = 4 。
	     
	示例 2:	
		输入: [2,7,9,3,1]
		输出: 12
		解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
		     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 */
public class HouseRobber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 198. 打家劫舍
	public int rob(int[] nums) {
		// 获取房屋的数量
		int n = nums.length;

		// 0
		if (n == 0) {
			return 0;
		}

		// 定义新数组用来存储当前能偷到的最大值
		int[] f = new int[n];

		// 1
		if (n == 1) {
			return nums[0];
		}

		// 2->两个中最大的
		int a = Math.max(nums[0], nums[1]);
		if (n == 2) {
			return a;
		}

		// nums->f nums[0]、max[0][1]
		f[0] = nums[0];
		f[1] = a;

		for (int i = 2; i < f.length; i++) {
			// i-2的结果和第i家和i-1的结果的最大值
			f[i] = Math.max(f[i - 2] + nums[i], f[i - 1]);
		}
		return f[n - 1];
	}
}
