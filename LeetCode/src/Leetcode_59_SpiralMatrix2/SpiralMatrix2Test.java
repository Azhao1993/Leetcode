package Leetcode_59_SpiralMatrix2;

public class SpiralMatrix2Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SpiralMatrix2 sm = new SpiralMatrix2();
		int n = 4;
		int[][] result = sm.generateMatrix(n);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == n - 1) {
					System.out.println(result[i][j]);
				} else {
					System.out.print(result[i][j] + ",");
				}
			}
		}
	}

}
