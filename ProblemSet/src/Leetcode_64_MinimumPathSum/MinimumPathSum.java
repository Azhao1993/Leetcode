package Leetcode_64_MinimumPathSum;
/*
	给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。	
	说明：每次只能向下或者向右移动一步。
	
	示例:	
		输入:
			[
			  [1,3,1],
			  [1,5,1],
			  [4,2,1]
			]
		输出: 7
	解释: 因为路径 1→3→1→1→1 的总和最小。
*/
public class MinimumPathSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MinimumPathSum mps = new MinimumPathSum();
		int[][] grid = {{1,3,1},{1,5,1},{4,2,1}};
		System.out.println(mps.minPathSum(grid));
		
	}
	//64. 最小路径和
    public int minPathSum(int[][] grid) {  
    	//空矩阵
    	//grid==null,空矩阵,grid.length==0
    	//grid[0]==null,grid[0].length==0
    	
    	if(grid==null||grid[0]==null||grid.length==0||grid[0].length==0) {
    		return 0;
    	}
        //定义一个最小值
    	int minpath=0;
    	//行和列
    	int m = grid.length;
    	int n = grid[0].length;    
    	//1*1的矩阵
    	if((m==1)&(n==1)) {
    		return grid[m-1][n-1];
    	}
    	//更新第一行
    	for(int j = 1;j<n;j++) {
    		grid[0][j] = grid[0][j]+grid[0][j-1];
    	}
    	//更新第一列
    	for(int i = 1;i<m;i++) {
    		grid[i][0] = grid[i][0]+grid[i-1][0];
    	}
    	//更新其他行列
    	for(int i =1 ;i<m;i++) {
    		for(int j = 1;j<n;j++) {
    			grid[i][j]=grid[i][j]+Math.min(grid[i-1][j], grid[i][j-1]);
    		}
    	}
    	return grid[m-1][n-1];
    }

}
