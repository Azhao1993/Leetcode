package Leetcode_73_SetMatrixZeroes;

import UsualMethod.matrixOutput;

public class SetMatrixZeroes2 {

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
	//O(M)+O(N)
	public void setZeroes(int[][] matrix) {
		//获取行
		int m = matrix.length;
		//获取列
		int n = matrix[0].length;
		//创建标志行数组
		boolean[] rowflag =new boolean[m];
		//创建标志lie数组
		boolean[] colflag =new boolean[n];
		//遍历数组
		for(int i = 0;i<m;i++) {
			for(int j = 0;j<n;j++) {
				if(matrix[i][j]==0) {
					rowflag[i] = true;
					colflag[j] = true;
				}
			}
		}
		//遍历行标志位
		for(int i = 0;i<m;i++) {
			if(rowflag[i]) {
				//所在行置零
				for(int j = 0;j<n;j++) {
					matrix[i][j]=0;
				}
			}
		}
		//遍历列标志位
		for(int j = 0;j<n;j++) {
			if(colflag[j]) {
				//所在行置零
				for(int i = 0;i<m;i++) {
					matrix[i][j]=0;
				}
			}
		}
	}

}
