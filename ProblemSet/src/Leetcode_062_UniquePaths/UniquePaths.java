package Leetcode_062_UniquePaths;

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
		System.out.println(up.uniquePaths(7, 3));
	}

	// 62. 不同的路径
	public int uniquePaths(int m, int n) {
		// 创建二维矩阵
		int[][] grid = new int[m][n];
		// 第一行只有一条路
		for (int j = 0; j < n; j++) {
			grid[0][j] = 1;
		}
		// 第一列只有一条路
		for (int i = 0; i < m; i++) {
			grid[i][0] = 1;
		}
		// dp[i][j] = dp[i-1][j]+dp[i][j-1]
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			}
		}
		return grid[m - 1][n - 1];
	}

}
