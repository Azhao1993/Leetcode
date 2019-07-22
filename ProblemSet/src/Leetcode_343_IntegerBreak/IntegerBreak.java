package Leetcode_343_IntegerBreak;

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
	public int integerBreak(int n) {
		if (n <= 1) {
			return 0;
		}
		int[] dp = new int[n + 1];
		for (int i = 2; i <= n; i++) {
			int res = Integer.MIN_VALUE;
			for (int j = 1; j <= i / 2; j++) {
				int a = Math.max(dp[j], j);
				int b = Math.max(dp[i - j], i - j);
				res = Math.max(a * b, res);
			}
			dp[i] = res;
		}
		return dp[n];
	}
}
