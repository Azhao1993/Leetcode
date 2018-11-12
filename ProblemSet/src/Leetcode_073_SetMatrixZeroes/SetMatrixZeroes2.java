package Leetcode_073_SetMatrixZeroes;

import UsualMethod.matrixOutput;

public class SetMatrixZeroes2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SetMatrixZeroes2 smz2 = new SetMatrixZeroes2();
		matrixOutput mo = new matrixOutput();
		int[][] matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
		System.out.println("����ǰ��");
		mo.ArrayOutput(matrix);
		smz2.setZeroes(matrix);
		System.out.println("�����");
		mo.ArrayOutput(matrix);
	}	
	//73. ��������
	//O(M)+O(N)
	public void setZeroes(int[][] matrix) {
		//��ȡ��
		int m = matrix.length;
		//��ȡ��
		int n = matrix[0].length;
		//������־������
		boolean[] rowflag =new boolean[m];
		//������־lie����
		boolean[] colflag =new boolean[n];
		//��������
		for(int i = 0;i<m;i++) {
			for(int j = 0;j<n;j++) {
				if(matrix[i][j]==0) {
					rowflag[i] = true;
					colflag[j] = true;
				}
			}
		}
		//�����б�־λ
		for(int i = 0;i<m;i++) {
			if(rowflag[i]) {
				//����������
				for(int j = 0;j<n;j++) {
					matrix[i][j]=0;
				}
			}
		}
		//�����б�־λ
		for(int j = 0;j<n;j++) {
			if(colflag[j]) {
				//����������
				for(int i = 0;i<m;i++) {
					matrix[i][j]=0;
				}
			}
		}
	}

}