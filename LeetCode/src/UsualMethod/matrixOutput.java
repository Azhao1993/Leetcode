package UsualMethod;
//数组输出
public class matrixOutput {
	//二维数组输出
	public void ArrayOutput(int[][] grid) {
		// 获取grid的行和列
		int row = grid.length;
		int col = grid[0].length;
		// 输出数组
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (j != col - 1) {
					System.out.print(grid[i][j] + ",");
				}else {
					System.out.println(grid[i][j]);
				}

			}
		}
	}
}
