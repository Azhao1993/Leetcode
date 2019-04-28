package Leetcode_1034_ColoringABorder;
/*
	给出一个二维整数网格 grid，网格中的每个值表示该位置处的网格块的颜色。
	只有当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一连通分量。
	连通分量的边界是指连通分量中的所有与不在分量中的正方形相邻（四个方向上）的所有正方形，或者在网格的边界上（第一行/列或最后一行/列）的所有正方形。
	给出位于 (r0, c0) 的网格块和颜色 color，使用指定颜色 color 为所给网格块的连通分量的边界进行着色，并返回最终的网格 grid 。 
	
	示例 1：
		输入：grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
		输出：[[3, 3], [3, 2]]
	示例 2：
		输入：grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
		输出：[[1, 3, 3], [2, 3, 3]]
	示例 3：
		输入：grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
		输出：[[2, 2, 2], [2, 1, 2], [2, 2, 2]]
	提示：
		1 <= grid.length <= 50
		1 <= grid[0].length <= 50
		1 <= grid[i][j] <= 1000
		0 <= r0 < grid.length
		0 <= c0 < grid[0].length
		1 <= color <= 1000
 */

//1034.边框着色
public class ColoringABorder {
	public static void main(String[] args) {
		int[][] grid = { { 1, 1 }, { 1, 2 } };
		int r0 = 0;
		int c0 = 0;
		int color = 3;
		new ColoringABorder().colorBorder(grid, r0, c0, color);
	}

	public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
		int n = grid.length;
		int m = grid[0].length;
		boolean[][] change = new boolean[n][m];
		boolean[][] used = new boolean[n][m];
		int oldcolor = grid[r0][c0];
		dfs(r0, c0, grid, oldcolor, change, used);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (change[i][j]) {
					if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
						grid[i][j] = color;
						continue;
					}
					boolean flag = change[i - 1][j] & change[i + 1][j] & change[i][j - 1] & change[i][j + 1];
					if (!flag) {
						grid[i][j] = color;
					}

				}
			}
		}
		return grid;
	}

	private void dfs(int i, int j, int[][] grid, int oldcolor, boolean[][] change, boolean[][] used) {
		
		if (!used[i][j] && grid[i][j] == oldcolor) {
			change[i][j] = true;
			used[i][j] = true;
		}else {
			used[i][j] = true;
			return;
		}

		// 向上
		if (i - 1 >= 0) {
			dfs(i - 1, j, grid, oldcolor, change, used);
		}
		// 向下
		if (i + 1 <= grid.length - 1) {
			dfs(i + 1, j, grid, oldcolor, change, used);
		}
		// 向左
		if (j - 1 >= 0) {
			dfs(i, j - 1, grid, oldcolor, change, used);
		}
		// 向右
		if (j + 1 <= grid[0].length - 1) {
			dfs(i, j + 1, grid, oldcolor, change, used);
		}

	}
}
