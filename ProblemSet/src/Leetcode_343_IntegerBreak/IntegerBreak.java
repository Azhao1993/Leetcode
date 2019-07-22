package Leetcode_343_IntegerBreak;

import java.util.Arrays;

/*
	给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
	
	示例 1:	
		输入: 2
		输出: 1
		解释: 2 = 1 + 1, 1 × 1 = 1。
	
	示例 2:	
		输入: 10
		输出: 36
		解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
		说明: 你可以假设 n 不小于 2 且不大于 58。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/integer-break
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//343. 整数拆分
public class IntegerBreak {
	public static void main(String[] args) {
		new IntegerBreak().integerBreak1(10);
	}

	// 递归(超时)
	public int integerBreak2(int n) {
		return breakInteger(n);
	}

	private int breakInteger(int n) {
		if (n == 1) {
			return 1;
		}
		int res = -1;
		for (int i = 1; i <= n - 1; i++) {
			res = Math.max(res, Math.max(i * (n - i), i * breakInteger(n - i)));
		}

		return res;
	}

	// 记忆化搜索
	public int integerBreak1(int n) {
		int[] memo = new int[n + 1];
		Arrays.fill(memo, -1);
		return breakInteger(n, memo);
	}

	private int breakInteger(int n, int[] memo) {
		if (n == 1) {
			return 1;
		}

		if (memo[n] != -1) {
			return memo[n];
		}

		int res = -1;
		for (int i = 1; i <= n - 1; i++) {
			res = Math.max(res, Math.max(i * (n - i), i * breakInteger(n - i, memo)));
		}
		memo[n] = res;
		return res;

	}

	// 动态规划
	public int integerBreak(int n) {
		int[] dp = new int[n + 1];
		Arrays.fill(dp, -1);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i / 2; j++) {
				dp[i] = Math.max(dp[i], Math.max(j * (i - j), j * dp[i - j]));
			}
		}
		return dp[n];
	}
}
