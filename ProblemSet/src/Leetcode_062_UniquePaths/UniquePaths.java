package Leetcode_062_UniquePaths;

import java.util.Arrays;

/*
	一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
	机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
	问总共有多少条不同的路径？
	
	例如，上图是一个7 x 3 的网格。有多少可能的路径？
	
	说明：m 和 n 的值均不超过 100。
	
	示例 1:
		输入: m = 3, n = 2
		输出: 3
	解释:
		从左上角开始，总共有 3 条路径可以到达右下角。
		1. 向右 -> 向右 -> 向下
		2. 向右 -> 向下 -> 向右
		3. 向下 -> 向右 -> 向右
	
	示例 2:
		输入: m = 7, n = 3
		输出: 28
*/
public class UniquePaths {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		UniquePaths up = new UniquePaths();
		System.out.println(up.uniquePaths(3, 2));
	}

	// 62. 不同的路径
	// 递归(超时)
	int m;
	int n;
	int[][] d = { { 0, 1 }, { 1, 0 } };

	private boolean isValid(int x, int y) {
		return x >= 0 && x <= m && y >= 0 && y <= n;
	}

	public int uniquePaths2(int m, int n) {
		this.m = m;
		this.n = n;
		return getPath(1, 1);

	}

	// (i,j)->(m,n)有多少种路径
	private int getPath(int x, int y) {
		if (x == m && y == n) {
			return 1;
		}

		int res = 0;
		for (int i = 0; i < 2; i++) {
			int nextx = x + d[i][0];
			int nexty = y + d[i][1];
			if (isValid(nextx, nexty)) {
				res += getPath(nextx, nexty);
			}
		}
		return res;
	}

	// 记忆化搜索
	public int uniquePaths1(int m, int n) {
		this.m = m;
		this.n = n;
		int[][] memo = new int[m + 1][n + 1];
		for (int[] me : memo) {
			Arrays.fill(me, -1);
		}
		return getPath(1, 1, memo);

	}

	// (i,j)->(m,n)有多少种路径
	private int getPath(int x, int y, int[][] memo) {
		if (x == m && y == n) {
			return 1;
		}

		if (memo[x][y] != -1) {
			return memo[x][y];
		}

		int res = 0;
		for (int i = 0; i < 2; i++) {
			int nextx = x + d[i][0];
			int nexty = y + d[i][1];
			if (isValid(nextx, nexty)) {
				res += getPath(nextx, nexty, memo);
			}
		}
		memo[x][y] = res;
		return res;
	}

	// 动态规划
	public int uniquePaths(int m, int n) {
		int[][] dp = new int[m + 1][n + 1];
		// 最后一行
		for (int j = n; j >= 1; j--) {
			dp[m][j] = 1;
		}
		// 最后一列
		for (int i = m; i >= 1; i--) {
			dp[i][n] = 1;
		}

		// dp(i,j) = dp(i+1,j)+dp(i,j+1)
		for (int i = m - 1; i >= 1; i--) {
			for (int j = n - 1; j >= 1; j--) {
				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
			}
		}
		return dp[1][1];
	}

	// 0ms:一维dp矩阵
	public int uniquePaths0(int m, int n) {
		int[] res = new int[n];
		res[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n; j++) {
				res[j] = res[j] + res[j - 1];
			}
		}
		return res[n - 1];
	}

}
