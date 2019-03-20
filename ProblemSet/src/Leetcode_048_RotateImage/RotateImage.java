package Leetcode_048_RotateImage;

/*
	给定一个 n × n 的二维矩阵表示一个图像。
	将图像顺时针旋转 90 度。
	说明：
		你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
	
	示例 1:
		给定 matrix = 
		[
		  [1,2,3],
		  [4,5,6],
		  [7,8,9]
		],
		
		原地旋转输入矩阵，使其变为:
		[
		  [7,4,1],
		  [8,5,2],
		  [9,6,3]
		]
		
	示例 2:
		给定 matrix =
		[
		  [ 5, 1, 9,11],
		  [ 2, 4, 8,10],
		  [13, 3, 6, 7],
		  [15,14,12,16]
		], 
		
		原地旋转输入矩阵，使其变为:
		[
		  [15,13, 2, 5],
		  [14, 3, 4, 1],
		  [12, 6, 8, 9],
		  [16, 7,10,11]
		]
*/
public class RotateImage {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 48. 旋转图像
	public void rotate(int[][] matrix) {
		int n = matrix.length;
		if (n == 1) {
			return;
		}
		// 转置
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
		// 交换列
		for (int j = 0; j < n / 2; j++) {
			for (int i = 0; i < n; i++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][n - 1 - j];
				matrix[i][n - 1 - j] = temp;
			}
		}
	}

	// 旋转边框
	public static void rotateMatrix(int[][] matrix) {
		if (matrix == null || matrix.length <= 1) {
			return;
		}
		// n*n的方阵
		int n = matrix.length;
		// 奇数中间的一个点不用动
		// (i,i)表示边框的起点
		for (int i = 0; i < n / 2; i++) {
			rotateEdge(matrix, i);
		}
	}

	private static void rotateEdge(int[][] matrix, int i) {
		int n = matrix.length;
		// （i,i）——>(i,n-2-i)需要移动的边框的移动轨迹
		for (int j = 0; j < n - 1 - 2 * i; j++) {
			int tmp = matrix[i][i + j];
			matrix[i][i + j] = matrix[n - 1 - i - j][i];
			matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 - i - j];
			matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i];
			matrix[i + j][n - 1 - i] = tmp;
		}
	}

}
