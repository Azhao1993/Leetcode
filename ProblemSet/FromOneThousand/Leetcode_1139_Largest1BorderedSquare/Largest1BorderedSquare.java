package Leetcode_1139_Largest1BorderedSquare;

/*
	给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，
	并返回该子网格中的元素数量。如果不存在，则返回 0。 
	
	示例 1：
		输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
		输出：9
	示例 2：
		输入：grid = [[1,1,0,0]]
		输出：1
	
	提示：
		1 <= grid.length <= 100
		1 <= grid[0].length <= 100
		grid[i][j] 为 0 或 1
 */

//1139.最大的以 1 为边界的正方形
public class Largest1BorderedSquare {
	public static void main(String[] args) {
		int[][] grid = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
		new Largest1BorderedSquare().largest1BorderedSquare(grid);
	}

	public int largest1BorderedSquare(int[][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		int[][] sumOfRow = new int[m][n];
		int[][] sumOfCol = new int[m][n];

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {

				if (i == 0) {
					sumOfCol[i][j] = grid[i][j];
				} else {
					sumOfCol[i][j] = grid[i][j] + sumOfCol[i - 1][j];
				}

				if (j == 0) {
					sumOfRow[i][j] = grid[i][j];
				} else {
					sumOfRow[i][j] = grid[i][j] + sumOfRow[i][j - 1];
				}
			}
		}
		int max = Math.min(m, n);
		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = max; l > res; l--) {
					int x = i + l - 1;
					int y = j + l - 1;

					if (x < m && y < n) {
						if (sumOfRow[i][y] - sumOfRow[i][j] + grid[i][j] == l
								&& sumOfCol[x][y] - sumOfCol[i][y] + grid[i][y] == l
								&& sumOfRow[x][y] - sumOfRow[x][j] + grid[x][j] == l
								&& sumOfCol[x][j] - sumOfCol[i][j] + grid[i][j] == l) {
							res = l;
						}
					}
				}
			}
		}
		return res * res;

	}
}
