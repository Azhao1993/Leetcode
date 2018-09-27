package Leetcode_887_ProjectionAreaof3DShapes;

/*
	在 N * N 的网格中，我们放置了一些与 x，y，z 三轴对齐的 1 * 1 * 1 立方体。	
	每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。	
	现在，我们查看这些立方体在 xy、yz 和 zx 平面上的投影。	
	投影就像影子，将三维形体映射到一个二维平面上。	
	在这里，从顶部、前面和侧面看立方体时，我们会看到“影子”。	
	返回所有三个投影的总面积。
		
	示例 1：
		输入：[[2]]
		输出：5
	示例 2：
		输入：[[1,2],[3,4]]
		输出：17
		解释：
		这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。	
	示例 3：	
		输入：[[1,0],[0,2]]
		输出：8
	示例 4：	
		输入：[[1,1,1],[1,0,1],[1,1,1]]
		输出：14
	示例 5：	
		输入：[[2,2,2],[2,1,2],[2,2,2]]
		输出：21	
	提示：	
		1 <= grid.length = grid[0].length <= 50
		0 <= grid[i][j] <= 50
*/
public class ProjectionAreaof3DShapes {
	public int projectionArea(int[][] grid) {
		int areasum = 0;
		// 获取二维数组的行
		int col = grid.length;
		// 获取二维数组的列
		int row = grid[0].length;
		if((col==0) |(row==0)){
			return 0;
		}
		
		// xy面的值
		
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (grid[i][j] != 0) {
					areasum++;
				}
			}
		}
		System.out.println(areasum);
		// yz面的值

		for (int j = 0; j < row; j++) {
			int temp = grid[0][j];
			for (int i = 1; i < col; i++) {
				if (grid[i][j] > temp) {
					temp = grid[i][j];
				}
				
			}
			areasum += temp;
		}
		System.out.println(areasum);
		// xz面的值
		
		for (int i = 0; i < col; i++) {
			int temp = grid[i][0];
			for (int j = 1; j < row; j++) {
				if (grid[i][j] > temp) {
					temp = grid[i][j];
				}
				
			}
			areasum += temp;
		}
		System.out.println(areasum);
		return areasum;
	}
}
