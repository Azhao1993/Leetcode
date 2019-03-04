package Leetcode_322_CoinChange;

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
	public int coinChange(int[] coins, int amount) {
		if (amount < 1)
			return 0;
		int[] dp = new int[amount + 1];// dp[sum]表示用coins组成sum元需要的最少的硬币
		int sum = 0;

		while (++sum <= amount) {
			int min = -1;// 最小的硬币数
			for (int coin : coins) {
				// coin当前硬币面值，寻找一种需要的最少的面值
				if (sum >= coin && dp[sum - coin] != -1) {
					int temp = dp[sum - coin] + 1;// 用组成sum-coin元需要的最少的硬币+1枚
					min = min < 0 ? temp : (temp < min ? temp : min);
				}
			}
			dp[sum] = min;
		}
		return dp[amount];
	}

}
