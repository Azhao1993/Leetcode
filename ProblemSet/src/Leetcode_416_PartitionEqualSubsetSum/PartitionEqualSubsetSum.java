package Leetcode_416_PartitionEqualSubsetSum;

import java.util.Arrays;

/*
	给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
	
	注意:
		每个数组中的元素不会超过 100
		数组的大小不会超过 200
	示例 1:
		输入: [1, 5, 11, 5]
		输出: true
		解释: 数组可以分割成 [1, 5, 5] 和 [11].
	
	示例 2:
		输入: [1, 2, 3, 5]
		输出: false
		解释: 数组不能分割成两个元素和相等的子集.
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//416. 分割等和子集
public class PartitionEqualSubsetSum {
	public static void main(String[] args) {
		int[] nums = { 2, 2, 3, 5 };
		new PartitionEqualSubsetSum().canPartition1(nums);
	}

	// dfs 超时
	public boolean canPartition2(int[] nums) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		if (sum % 2 != 0) {
			return false;
		}
		return canPartition(nums, sum / 2, 0);
	}

	private boolean canPartition(int[] nums, int sum, int index) {
		if (sum == 0) {
			return true;
		}
		if (sum < 0) {
			return false;
		}
		for (int i = index; i < nums.length; i++) {
			if (canPartition(nums, sum - nums[i], i + 1)) {
				return true;
			}
		}
		return false;
	}

	// 记忆化搜索
	public boolean canPartition1(int[] nums) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		if (sum % 2 != 0) {
			return false;
		}
		int[][] memo = new int[nums.length][sum / 2 + 1];
		for (int[] me : memo) {
			Arrays.fill(me, -1);
		}
		return canPartition(nums, sum / 2, 0, memo);
	}

	private boolean canPartition(int[] nums, int sum, int index, int[][] memo) {
		if (sum == 0) {
			return true;
		}
		if (sum < 0 || index == nums.length) {
			return false;
		}
		if (memo[index][sum] != -1) {
			return memo[index][sum] == 1;
		}

		for (int i = index; i < nums.length; i++) {
			if (canPartition(nums, sum - nums[i], i + 1, memo)) {
				memo[index][sum] = 1;
				return true;
			}
		}
		memo[index][sum] = 0;
		return false;
	}

	// 动态规划
	public boolean canPartition0(int[] nums) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		if (sum % 2 != 0) {
			return false;
		}
		// dp[i][j] [i,length-1]是否能凑出j
		boolean[][] dp = new boolean[nums.length][sum / 2 + 1];
		for (int i = nums.length - 1; i >= 0; i--) {
			if (nums[i] <= sum / 2) {
				dp[i][nums[i]] = true;
			}
		}

		for (int i = nums.length - 2; i >= 0; i--) {
			for (int j = 0; j <= sum / 2; j++) {
				boolean flag = dp[i + 1][j];
				if (!flag && j + nums[i] <= sum / 2) {
					flag |= dp[i + 1][j + nums[i]];
				}
				dp[i][j] = flag;
			}
		}
		return dp[0][sum / 2];
	}

	// 动态规划
	public boolean canPartition(int[] nums) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		if (sum % 2 != 0) {
			return false;
		}
		// dp[i][j] [0,i]是否能凑出j
		boolean[][] dp = new boolean[nums.length][sum / 2 + 1];
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] <= sum / 2) {
				dp[i][nums[i]] = true;
			}
		}
		for (int i = 1; i < nums.length; i++) {
			for (int j = 0; j <= sum / 2; j++) {
				boolean flag = dp[i - 1][j];
				if (!flag && j - nums[i] >= 0) {
					flag |= dp[i - 1][j - nums[i]];
				}
				dp[i][j] = flag;
			}
		}
		return dp[nums.length - 1][sum / 2];
	}

}
