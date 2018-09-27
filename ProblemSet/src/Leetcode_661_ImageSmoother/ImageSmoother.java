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
//边界问题
//
public class ImageSmoother {

	public int[][] imageSmoother(int[][] M) {

		int row = M.length;// 获取M的行
		int col = M[0].length;// 获取M的列
		int[][] res = new int[row][col];//定义结果数组
		
		// 遍历数组
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int sum = 0;//求和
				int count = 0;//计数
				
				//求和计数的同时判断边界
				//x从0——row-1
				//判断i-1是否比0小，i+1是否比row-1大				
				for(int x=Math.max(0, i-1);x<=Math.min(row-1, i+1);x++) {
					//y从0——col-1
					//判断j-1是否比0小，j+1是否比col-1大			
					for(int y = Math.max(0, j-1);y<=Math.min(col-1, j+1);y++) {
						sum+=M[x][y];
						count++;
					}
				}
			
			res[i][j] = (int)Math.floor(sum/count);
			}
		}
		return res;
	}
}
