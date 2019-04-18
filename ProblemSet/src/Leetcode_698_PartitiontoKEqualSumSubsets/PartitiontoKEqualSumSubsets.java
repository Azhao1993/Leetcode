package Leetcode_698_PartitiontoKEqualSumSubsets;

/*
	给定一个整数数组  nums 和一个正整数 k，
	找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
	
	示例 1：	
		输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
		输出： True
		说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。	
	注意:	
		1 <= k <= len(nums) <= 16
		0 < nums[i] < 10000
 */

//698. 划分为k个相等的子集
public class PartitiontoKEqualSumSubsets {
	public static void main(String[] args) {
		PartitiontoKEqualSumSubsets pkess = new PartitiontoKEqualSumSubsets();
		int[] nums = { 4, 3, 2, 3, 5, 2, 1 };
		int k = 4;
		System.out.println(pkess.canPartitionKSubsets(nums, k));
	}

	public boolean canPartitionKSubsets(int[] nums, int k) {
		int sum = 0;
		int maxNum = 0;
		for (int i = 0; i < nums.length; i++) {
			sum += nums[i];
			maxNum = Math.max(maxNum, nums[i]);
		}
		if (sum % k != 0 || maxNum > sum / k)
			return false;
		return canKSubsetsSum(nums, k, sum / k, 0, new boolean[nums.length], 0);
	}

	// nums,k,子集目标和，当前和，签到数组，innerStart防止重复
	private boolean canKSubsetsSum(int[] nums, int k, int targetSum, int curSum, boolean[] visited, int innerStart) {
		// k=0 时说明所有的组分好
		if (k == 0) {
			return true;
		} else if (curSum > targetSum) {
			// 不成立
			return false;
		} else if (curSum == targetSum) {
			// 分组成立
			// 从第一个没有被使用过的数开始找
			return canKSubsetsSum(nums, k - 1, targetSum, 0, visited, 0);
		}
		for (int i = innerStart; i < nums.length; i++) {
			if (!visited[i]) {
				visited[i] = true;
				if (canKSubsetsSum(nums, k, targetSum, curSum + nums[i], visited, i + 1)) {
					return true;
				}
				// 回溯，并向后
				visited[i] = false;
			}
		}
		return false;
	}

	// 超时
	public boolean canPartitionKSubsets1(int[] nums, int k) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		if (sum % k != 0) {
			return false;
		}
		int max = sum / k;
		for (int num : nums) {
			if (num > max) {
				return false;
			}
		}
		// DFS
		int[] bucks = new int[k];
		// boolean[] used = new boolean[nums.length];
		boolean flag = dfs(bucks, nums, max, 0);
		return flag;
	}

	private boolean dfs(int[] bucks, int[] nums, int max, int index) {
		if (index == nums.length) {
			return true;
		}
		int num = nums[index];
		boolean flag = false;
		for (int i = 0; i < bucks.length; i++) {
			if (bucks[i] + num <= max) {
				bucks[i] += num;
				flag = dfs(bucks, nums, max, index + 1);
				if (flag) {
					return true;
				} else {
					bucks[i] -= num;
				}
			}
		}
		return false;
	}
}
