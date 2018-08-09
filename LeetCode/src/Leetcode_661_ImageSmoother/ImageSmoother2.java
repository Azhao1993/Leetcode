package Leetcode_661_ImageSmoother;

/*
 
	包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。

	示例 1:	
		输入:
			[[1,1,1],
			 [1,0,1],
			 [1,1,1]]
		输出:
			[[0, 0, 0],
			 [0, 0, 0],
			 [0, 0, 0]]
		解释:
			对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
			对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
			对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
*/
//错误代码
public class ImageSmoother2 {
	
	public int[][] imageSmoother(int[][] M) {
		// 取M的行
		int row = M.length;
		int col = M[0].length;
		// 定义扩充数组
		int[][] result = new int[row + 2][col + 2];

		// 遍历数组将M扩充至result数组
		for (int i = 1; i < row + 1; i++) {
			for (int j = 1; j < col + 1; j++) {
				result[i][j] = M[i - 1][j - 1];
			}
		}

		
		// 将和值填至M数组,并求出均值
		for (int i = 1; i < row + 1; i++) {
			for (int j = 1; j < col + 1; j++) {
				M[i - 1][j - 1] = result[i - 1][j - 1] + result[i - 1][j] + result[i - 1][j + 1] + result[i][j - 1]
						+ result[i][j] + result[i][j + 1] + result[i + 1][j - 1] + result[i + 1][j]
						+ result[i + 1][j + 1];
				
				// 判断是否是特殊点
				if (((i == 1) & (j == 1)) || ((i == 1) & (j == col)) || ((i == row) & (j == 1))
						|| ((i == row) & (j == col))) {
					M[i-1][j-1]=(int)Math.floor(M[i-1][j-1] / 4);
				
				} else if (((i == 1) & (j != 1) & (j != col)) ||((j == 1) & (i != row) & (i != 1))
						|| ((i == row) & (j != col) & (j != 1)) || ((j == col) & (i != 1) & (i != row))) {
					 M[i-1][j-1]=(int)Math.floor(M[i-1][j-1] / 6);
					
				} else {
					 M[i-1][j-1]=(int)Math.floor(M[i-1][j-1] / 9);
					
				}

				

			}
		}
		
		return M;
	}
}
