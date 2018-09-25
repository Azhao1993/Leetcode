package Leetcode_840_MagicSquaresInGrid;

/*
3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，
其中每行，每列以及两条对角线上的各数之和都相等。	
给定一个由整数组成的 N × N 矩阵，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。

示例 1:	
	输入: [[4,3,8,4],
	      [9,5,1,9],
	      [2,7,6,2]]
	输出: 1
	解释: 
		下面的子矩阵是一个 3 x 3 的幻方：
		438
		951
		276
	
		而这一个不是：
		384
		519
		762
	
总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
*/
//3阶幻方行、列、对角线和都是15
//中间的数是5
//1-9
public class MagicSquaresInGrid {
	public int numMagicSquaresInside(int[][] grid) {
		// 计数器
		int count = 0;
		// 获取数组的行
		int row = grid.length;
		// 获取数组的列
		int col = grid[0].length;

		// 行和列小于3
		if (row < 3 | col < 3) {
			return 0;
		} else if ((row == 3) & (col == 3)) {
			// 行和列都为3
			if (MagicSquares(grid, 1, 1)) {
				return 1;
			} else {
				return 0;
			}
		} else if (row == 3) {
			// 行为3，只列增
			for (int j = 1; j < col - 1; j++) {
				if (MagicSquares(grid, 1, j)) {
					count++;
				}
			}
		} else if (col == 3) {
			// 列为3，只行增
			for (int i = 1; i < row - 1; i++) {
				if (MagicSquares(grid, i, 1)) {
					count++;
				}
			}
		} else {
			for (int i = 1; i < row - 1; i++) {
				for (int j = 1; j < col - 1; j++) {
					if (MagicSquares(grid, i, j)) {
						count++;
					}
				}
			}

		}

		return count;
	}

	public boolean MagicSquares(int[][] grid, int i, int j) {
		// 判断是否是3阶幻方
		// 首先ij是不是5
		if (grid[i][j] != 5) {
			return false;
		}
		// 判断是否是1——10；
		int[] nums = new int[9];
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				if ((grid[i - 1 + x][j - 1 + y] < 1) || (grid[i - 1 + x][j - 1 + y] > 9)) {
					return false;
				} else {
					nums[grid[i - 1 + x][j - 1 + y] - 1] = grid[i - 1 + x][j - 1 + y];
				}
			}
		}
		for(int x= 0;x<9;x++) {
			if(nums[x]!=x+1) {
				return false;
			}
		}
		// 判断每行每列的和是不是15
		int sum;
		// 判断行
		for (int x = 0; x < 3; x++) {
			sum = 0;
			for (int y = 0; y < 3; y++) {
				sum += grid[i - 1 + x][j - 1 + y];
			}
			if (sum != 15) {
				return false;
			}
		}
		// 判断列
		for (int y = 0; y < 3; y++) {
			sum = 0;
			for (int x = 0; x < 3; x++) {
				sum += grid[i - 1 + x][j - 1 + y];
			}
			if (sum != 15) {
				return false;
			}
		}
		// 判断主对角线
		sum = 0;
		for (int x = 0; x < 3; x++) {
			sum += grid[i - 1 + x][j - 1 + x];
		}
		if (sum != 15) {
			return false;
		}
		// 判断副对角线
		sum = 0;
		for (int x = 0; x < 3; x++) {
			sum += grid[i - 1 + x][j + 1 - x];
		}
		if (sum != 15) {
			return false;
		}
		//
		return true;
	}
}
