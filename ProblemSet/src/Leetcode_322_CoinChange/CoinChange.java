package Leetcode_322_CoinChange;

import java.util.Arrays;

/*
	给定不同面额的硬币 coins 和一个总金额 amount。
	编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
	如果没有任何一种硬币组合能组成总金额，返回 -1。
	
	示例 1:	
		输入: coins = [1, 2, 5], amount = 11
		输出: 3 
		解释: 11 = 5 + 5 + 1
	示例 2:	
		输入: coins = [2], amount = 3
		输出: -1
	说明:
		你可以认为每种硬币的数量是无限的。
 */

//322.零钱兑换
public class CoinChange {
	public static void main(String[] args) {
		new CoinChange().coinChange1(new int[] { 474, 83, 404, 3 }, 264);
	}

	// 递归(超时)
	int[] coins;

	public int coinChange2(int[] coins, int amount) {
		Arrays.sort(coins);
		this.coins = coins;
		if (amount <= 0) {
			return 0;
		}
		if (coins[0] > amount) {
			return -1;
		}
		return coinChange(amount);
	}

	private int coinChange(int amount) {
		if (amount == 0) {
			return 0;
		}
		int res = -1;
		for (int i = 0; i < coins.length; i++) {
			int nextAmount = amount - coins[i];
			if (nextAmount >= 0) {
				int nextcount = coinChange(nextAmount);
				if (nextcount != -1) {
					if (res == -1) {
						res = nextcount + 1;
					} else {
						res = Math.min(res, nextcount + 1);
					}
				}
			}
		}
		return res;
	}

	// 记忆化搜索
	public int coinChange1(int[] coins, int amount) {
		Arrays.sort(coins);
		this.coins = coins;
		if (amount <= 0) {
			return 0;
		}
		if (coins[0] > amount) {
			return -1;
		}
		int[] memo = new int[amount + 1];
		Arrays.fill(memo, -2);
		return coinChange(amount, memo);

	}

	private int coinChange(int amount, int[] memo) {
		if (amount == 0) {
			return 0;
		}
		if (memo[amount] != -2) {
			return memo[amount];
		}
		int res = -1;
		for (int i = 0; i < coins.length; i++) {
			int nextAmount = amount - coins[i];
			if (nextAmount >= 0) {
				int nextcount = coinChange(nextAmount, memo);
				if (nextcount != -1) {
					if (res == -1) {
						res = nextcount + 1;
					} else {
						res = Math.min(res, nextcount + 1);
					}
				}
			}
		}
		memo[amount] = res;
		return res;
	}

	// 动态规划
	public int coinChange(int[] coins, int amount) {
		if (coins == null || coins.length == 0 || amount < 0) {
			return -1;
		}
		int dp[] = new int[amount + 1];
		Arrays.fill(dp, -1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			int res = -1;
			for (int j = 0; j < coins.length; j++) {
				int pre_amount = i - coins[j];
				if (pre_amount >= 0 && dp[pre_amount] != -1) {
					if (res == -1) {
						res = dp[pre_amount] + 1;
					} else {
						res = Math.min(res, dp[pre_amount] + 1);
					}
				}
			}
			dp[i] = res;
		}
		return dp[amount];
	}
}
