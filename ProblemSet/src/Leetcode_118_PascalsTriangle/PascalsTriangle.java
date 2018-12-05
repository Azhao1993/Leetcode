package Leetcode_118_PascalsTriangle;

import java.util.ArrayList;
import java.util.List;

/*
	给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。	
	
	动图图片：https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif	
	在杨辉三角中，每个数是它左上方和右上方的数的和。	
	
		示例:		
			输入: 5
			输出:
			[
			     [1],
			    [1,1],
			   [1,2,1],
			  [1,3,3,1],
			 [1,4,6,4,1]
			]
 */
public class PascalsTriangle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PascalsTriangle pst = new PascalsTriangle();
		pst.generate(5);
	}

	// 118. 杨辉三角
	public List<List<Integer>> generate(int numRows) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		if (numRows <= 0) {
			return result;
		}
		List<Integer> list = new ArrayList<Integer>();
		list.add(1);
		result.add(list);
		if (numRows == 1) {
			return result;
		}
		for (int i = 1; i < numRows; i++) {
			// 创建行
			List<Integer> nofirstlist = new ArrayList<Integer>();
			nofirstlist.add(1);
			for (int j = 1; j < i; j++) {
				nofirstlist.add(result.get(i - 1).get(j - 1) + result.get(i - 1).get(j));
			}
			nofirstlist.add(1);
			result.add(nofirstlist);
		}
		return result;
	}

	// 0ms
	public List<List<Integer>> generate2(int numRows) {
		int[][] yanghuiArr = new int[numRows][numRows];
		for (int i = 0; i < numRows; i++) {
			yanghuiArr[i][0] = 1;
			yanghuiArr[i][i] = 1;
		}
		for (int i = 2; i < numRows; i++) {
			for (int j = 1; j <= i; j++) {
				yanghuiArr[i][j] = yanghuiArr[i - 1][j - 1] + yanghuiArr[i - 1][j];
			}
		}
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		for (int i = 0; i < numRows; i++) {
			List<Integer> list = new ArrayList(i + 1);
			for (int j = 0; j <= i; j++) {
				list.add(yanghuiArr[i][j]);
			}
			result.add(list);
		}
		return result;
	}

}
