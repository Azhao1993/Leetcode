package Leetcode_377_CombinationSumIV;

import java.util.Arrays;

/*
	给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
	
	示例:	
		nums = [1, 2, 3]
		target = 4
		
		所有可能的组合为：
		(1, 1, 1, 1)
		(1, 1, 2)
		(1, 2, 1)
		(1, 3)
		(2, 1, 1)
		(2, 2)
		(3, 1)
		
		请注意，顺序不同的序列被视作不同的组合。
		
		因此输出为 7。
	进阶：
		如果给定的数组中含有负数会怎么样？
		问题会产生什么变化？
		我们需要在题目中添加什么限制来允许负数的出现？
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/combination-sum-iv
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//377. 组合总和 Ⅳ
public class CombinationSumIV {
	public static void main(String[] args) {
		new CombinationSumIV().combinationSum42(new int[] { 1, 2, 3 }, 4);
	}

	// DFS(超时)
	public int combinationSum42(int[] nums, int target) {
		if (target == 0) {
			return 1;
		}
		int res = 0;
		for (int i = 0; i < nums.length; i++) {
			if (target - nums[i] >= 0) {
				res += combinationSum42(nums, target - nums[i]);
			}
		}
		return res;
	}

	// 记忆化搜索
	public int combinationSum41(int[] nums, int target) {
		int[] memo = new int[target + 1];
		Arrays.fill(memo, -1);
		if (target == 0) {
			return 1;
		}
		memo[0] = 1;
		return combinationSum41(nums, target, memo);
	}

	private int combinationSum41(int[] nums, int target, int[] memo) {
		if (memo[target] != -1) {
			return memo[target];
		}
		int res = 0;
		for (int i = 0; i < nums.length; i++) {
			if (target - nums[i] >= 0) {
				res += combinationSum41(nums, target - nums[i], memo);
			}
		}
		memo[target] = res;
		return res;
	}

	// 动态规划
	public int combinationSum4(int[] nums, int target) {

		if (nums == null || nums.length == 0) {
			return 0;
		}
		int[] dp = new int[target + 1];
		dp[0] = 1;
		for (int i = 1; i <= target; i++) {
			int res = 0;
			for (int j = 0; j < nums.length; j++) {
				if (i - nums[j] >= 0) {
					res += dp[i - nums[j]];
				}
			}
			dp[i] = res;
		}
		return dp[target];
	}
}
