package Leetcode_661_ImageSmoother;

public class ImageSmootherTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//创建对象
		ImageSmoother is  = new ImageSmoother();
		int[][] M = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
		//[[2,3,4],[5,6,7],[8,9,10],[11,12,13],[14,15,16]]
		//[[4,4,5],[5,6,6],[8,9,9],[11,12,12],[13,13,14]]
		//输出二维数组
		System.out.println("输入数组：");
		for (int i = 0; i < M.length; i++) {
			for (int j = 0; j < M[0].length; j++) {
				if (j == M[0].length - 1) {
					System.out.println(M[i][j]);
				} else {
					System.out.print(M[i][j] + ",");
				}
			}
		}
		System.out.println();
		int[][] res = is.imageSmoother(M);
		for (int i = 0; i < res.length; i++) {
			for (int j = 0; j < res[0].length; j++) {				
				
				if (j == res[0].length - 1) {
					System.out.println(res[i][j]);
				} else {
					System.out.print(res[i][j] + ",");
				}
			}
		}
		
		
		/*
		double[][] N = {{0.75,0.83333333,0.75},{0.83333333,0.88888889,0.83333333},{0.75,0.83333333,0.75}};
		//输出二维数组
				for (int i = 0; i < M.length; i++) {
					for (int j = 0; j < M[0].length; j++) {
						N[i][j] =Math.floor( N[i][j]);
						M[i][j] = (int)N[i][j];
						
						if (j == M[0].length - 1) {
							System.out.println(M[i][j]);
						} else {
							System.out.print(M[i][j] + ",");
						}
					}
				}
		*/
	}

}
