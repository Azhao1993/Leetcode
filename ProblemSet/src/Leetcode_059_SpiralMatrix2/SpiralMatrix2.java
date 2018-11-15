package Leetcode_059_SpiralMatrix2;

/*
	给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
	示例
		输入: 3
		输出:
		[
		 [ 1, 2, 3 ],
		 [ 8, 9, 4 ],
		 [ 7, 6, 5 ]
		]
 */
public class SpiralMatrix2 {
	
	//59.螺旋矩阵 II
	public int[][] generateMatrix(int n) {
		// 创建二维输出
		int[][] result = new int[n][n];
		// 边界值
		int rowbegin = 0;
		int rowend = n - 1;
		int colbegin = 0;
		int colend = n - 1;
		// 起始值
		int num = 1;
		while (num <= n * n) {
			// 行不变列增加(右)
			for (int j = colbegin; j <= colend; j++) {
				result[rowbegin][j] = num;
				num++;
			}
			//开始行增加
			rowbegin++;
			// 列不变行增加(下)
			for (int i = rowbegin; i <= rowend; i++) {
				result[i][colend] = num;
				num++;
			}
			//结束列减少
			colend--;
			// 行不变列减少(左)
			for (int j = colend; j >= colbegin; j--) {
				result[rowend][j] = num;
				num++;
			}
			//结束行减少
			rowend--;
			// 列不变行减少
			for (int i = rowend; i >= rowbegin; i--) {
				result[i][colbegin] = num;
				num++;
			}
			//开始行增加
			colbegin++;
		}

		return result;
	}

}
