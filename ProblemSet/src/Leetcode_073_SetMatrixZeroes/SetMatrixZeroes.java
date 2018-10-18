package Leetcode_073_SetMatrixZeroes;

import UsualMethod.matrixOutput;

/*
	给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
	
	示例 1:
		输入: 
			[
			  [1,1,1],
			  [1,0,1],
			  [1,1,1]
			]
		输出: 
			[
			  [1,0,1],
			  [0,0,0],
			  [1,0,1]
			]
	示例 2:
		输入: 
			[
			  [0,1,2,0],
			  [3,4,5,2],
			  [1,3,1,5]
			]
		输出: 
			[
			  [0,0,0,0],
			  [0,4,5,0],
			  [0,3,1,0]
			]
	进阶:
		一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
		一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
		你能想出一个常数空间的解决方案吗？
*/
public class SetMatrixZeroes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SetMatrixZeroes smz = new SetMatrixZeroes();
		matrixOutput mo = new matrixOutput();
		int[][] matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
		System.out.println("置零前：");
		mo.ArrayOutput(matrix);
		smz.setZeroes(matrix);
		System.out.println("置零后：");
		mo.ArrayOutput(matrix);
	}
	//73. 矩阵置零
	//左乘变行，右乘变列
    public void setZeroes(int[][] matrix) {
        //O(mn)
    	boolean[][] flag = new boolean[matrix.length][matrix[0].length];
    	//找到0
    	for(int i = 0;i<matrix.length;i++) {
    		for(int j = 0;j<matrix[0].length;j++) {
    			if(matrix[i][j]==0) {
    				flag[i][j] = true;
    			}
    		}
    	}
    	//置零
    	for(int i = 0;i<matrix.length;i++) {
    		for(int j = 0;j<matrix[0].length;j++) {
    			if(flag[i][j]) {
    				setZeroes(matrix,i,j);
    			}
    		}
    	}
    }
    
    public void setZeroes(int[][] matrix,int i,int  j) {
    	//所在行置零
    	for(int m = 0;m<matrix[0].length;m++) {
    		matrix[i][m]=0;
    	}
    	//所在列置零
    	for(int n = 0;n<matrix.length;n++) {
    		matrix[n][j]=0;
    	}
    }

}
