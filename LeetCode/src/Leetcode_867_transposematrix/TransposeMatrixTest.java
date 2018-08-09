package Leetcode_867_transposematrix;

public class TransposeMatrixTest {

	public static void main(String[] args) {
		int[][] A = {{1,2,3},{4,5,6}};
		
		TransposeMatrix tm = new TransposeMatrix();
		int[][] C= tm.transpose(A);
		//二维数组的输出
		for (int i = 0; i < C.length; i++) {
			for (int j = 0; j < C[0].length; j++) {
				if (j == C[0].length - 1) {
					System.out.println(C[i][j]);
				} else {
					System.out.print(C[i][j] + ",");
				}
			}
		}
	}

}
