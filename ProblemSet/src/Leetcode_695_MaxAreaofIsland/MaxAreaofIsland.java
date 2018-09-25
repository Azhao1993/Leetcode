package Leetcode_695_MaxAreaofIsland;
/*
	给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。
	你可以假设二维矩阵的四个边缘都被水包围着。
	
	找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
	
	示例 1:	
		[[0,0,1,0,0,0,0,1,0,0,0,0,0],
		 [0,0,0,0,0,0,0,1,1,1,0,0,0],
		 [0,1,1,0,1,0,0,0,0,0,0,0,0],
		 [0,1,0,0,1,1,0,0,1,0,1,0,0],
		 [0,1,0,0,1,1,0,0,1,1,1,0,0],
		 [0,0,0,0,0,0,0,0,0,0,1,0,0],
		 [0,0,0,0,0,0,0,1,1,1,0,0,0],
		 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
		 
		对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
	
	示例 2:	
		[[0,0,0,0,0,0,0,0]]
		对于上面这个给定的矩阵, 返回 0。
	
	注意: 给定的矩阵grid 的长度和宽度都不超过 50。
*/
public class MaxAreaofIsland {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MaxAreaofIsland mai = new MaxAreaofIsland();
		int[][] grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
		System.out.println(mai.maxAreaOfIsland(grid));
	}
	//695. 岛屿的最大面积
    public int maxAreaOfIsland(int[][] grid) {
        int max = deepSearch(grid,0,0);
        for(int i =0;i<grid.length;i++) {
        	for(int j = 0;j<grid[0].length;j++) {
        		if(grid[i][j]==1) {
        			max = Math.max(max, deepSearch(grid,i,j));
        		}        		
        	}
        }
        return max;
    }
    //深度搜索
    public int deepSearch(int[][] grid,int i,int j) {
    	//
    	if((i>=0)&&(i<grid.length)&&(j>=0)&&(j<grid[0].length)&&(grid[i][j]==1)) {
    		//标记
    		grid[i][j]=0;
    		//左右上下
    		return 1+deepSearch(grid,i,j-1)+deepSearch(grid,i,j+1)+deepSearch(grid,i-1,j)+deepSearch(grid,i+1,j);
    	}else {
    		return 0;
    	}
    }

}
