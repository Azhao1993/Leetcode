package Leetcode_054_SpiralMatrix;

import java.util.ArrayList;
import java.util.List;

/*
	给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
	
	示例 1:	
		输入:
			[
			 [ 1, 2, 3 ],
			 [ 4, 5, 6 ],
			 [ 7, 8, 9 ]
			]
		输出: [1,2,3,6,9,8,7,4,5]
	
	示例 2:	
		输入:
			[
			  [1, 2, 3, 4],
			  [5, 6, 7, 8],
			  [9,10,11,12]
			]
		输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 */
public class SpiralMatrix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	//54. 螺旋矩阵
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<Integer>();
        if((matrix.length==0)||(matrix==null)) {
        	return list;
        }
        //行
        int row = matrix.length;
        //列
        int col = matrix[0].length;
        //行
        int rowbegin = 0;
        int rowend = row-1;
        //列
        int colbegin = 0;
        int colend = col-1;
        while(list.size()<row*col) {
        	//向右
        	for(int i = colbegin;i<=colend&&list.size()<row*col;i++) {
        		list.add(matrix[rowbegin][i]);
        	}
        	rowbegin++;
        	//向下
        	for(int i = rowbegin;i<=rowend&&list.size()<row*col;i++) {
        		list.add(matrix[i][colend]);
        	}
        	colend--;
        	//向左
        	for(int i = colend;i>=colbegin&&list.size()<row*col;i--) {
        		list.add(matrix[rowend][i]);
        	}
        	rowend--;
        	//向上
        	for(int i = rowend;i>=rowbegin&&list.size()<row*col;i--) {
        		list.add(matrix[i][colbegin]);
        	}
        	colbegin++;
        }
        return list;
    }

}
