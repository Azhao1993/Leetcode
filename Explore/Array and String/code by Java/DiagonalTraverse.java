package Leetcode_498_DiagonalTraverse;

/*
	给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素。	
	示例:	
		输入:
			[
			 [ 1, 2, 3 ],
			 [ 4, 5, 6 ],
			 [ 7, 8, 9 ]
			]	
		输出:  
			[1,2,4,7,5,3,6,8,9]

 */
public class DiagonalTraverse {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DiagonalTraverse dt = new DiagonalTraverse();
		int[][] matrix = {{3},{2}};
		dt.findDiagonalOrder(matrix);
	}

	// 498. 对角线遍历
	public int[] findDiagonalOrder(int[][] matrix) {
		//null
		if (matrix == null || matrix.length == 0 || matrix[0] == null) {
            return new int[]{};
        }
		//1行
        if (matrix.length == 1) {
            return matrix[0];
        }
        //1列
        if (matrix[0].length == 1) {
            int[] result = new int[matrix.length];           
            for ( int i = 0;i<result.length;i++) {
                result[i] = matrix[i][0];
            }
            return result;
        }
        
		// 行
		int m = matrix.length;
		// 列
		int n = matrix[0].length;
		int[] result = new int[m * n];

		int i = 0;
        int j = 0;
        
        int flag = 0;// 0-右上    1-左下
        int index = 0;//result的索引

        while (i != matrix.length && j != matrix[0].length) {
        	//不遇到边界
        	result[index] = matrix[i][j];
            // 右上遍历
            if (flag == 0) {
                // 首行向右转移（非末列）
                if (i == 0 && j != matrix[0].length - 1) {
                    j++;
                    flag = 1;
                } else if (j == matrix[0].length - 1) {
                    // 末列向下转移
                    i++;
                    flag = 1;
                } else {
                    //正常右上
                    i--;
                    j++;
                }
            } else {
                // 首列向下转移（非末行）
                if (j == 0 && i != matrix.length - 1) {
                    i++;
                    flag = 0;
                } else if (i == matrix.length - 1) {
                	//未列
                    j++;
                    flag = 0;
                } else {
                	//正常左下
                    i++;
                    j--;
                }
            }
            index++;
        }
        return result;
	}

}
