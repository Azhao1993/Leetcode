package Leetcode_073_SetMatrixZeroes;

import UsualMethod.matrixOutput;

public class SetMatrixZeroes3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SetMatrixZeroes3 smz3 = new SetMatrixZeroes3();
		matrixOutput mo = new matrixOutput();
		int[][] matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
		System.out.println("置零前：");
		mo.ArrayOutput(matrix);
		smz3.setZeroes(matrix);
		System.out.println("置零后：");
		mo.ArrayOutput(matrix);
	}
	//73. 矩阵置零
	//常数空间
	public void setZeroes(int[][] matrix) {
		//获取行和列
		int row = matrix.length;
		int col = matrix[0].length;
		//判断第一行是否有零		
		boolean rowflag = false;
		for(int j = 0;j<col;j++) {
			if(matrix[0][j]==0) {
				rowflag = true;
				break;
			}
		}
		//遍历第一列是否有零
		boolean colflag = false;
		for(int i = 0;i<row;i++) {
			if(matrix[i][0]==0) {
				colflag = true;
				break;
			}
		}
		//从i=1,j=1找0，如果有就对应的首行和首列置为0
		for(int i = 1;i<row;i++) {
			for(int j = 1;j<col;j++) {
				if(matrix[i][j]==0) {
					matrix[i][0]=0;
					matrix[0][j]=0;
				}
			}
		}
		//将对应的行和列置零
		//首行遍历，列置零
		for(int j=1;j<col;j++) {
			if(matrix[0][j]==0) {
				for(int i=0;i<row;i++) {
					matrix[i][j]=0;
				}
			}
		}
		//首列遍历，行置零
		for(int i=1;i<row;i++) {
			if(matrix[i][0]==0) {
				for(int j=0;j<col;j++) {
					matrix[i][j]=0;
				}
			}
		}
		//判断首行
		if(rowflag) {
			for(int j =0;j<col;j++) {
				matrix[0][j]=0;
			}
		}
		//判断首列
		if(colflag) {
			for(int i =0;i<row;i++) {
				matrix[i][0]=0;
			}
		}
		
	}

}
