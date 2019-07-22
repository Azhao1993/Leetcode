package Leetcode_120_Triangle;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
	给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。	
	例如，给定三角形：	
		[
		     [2],
		    [3,4],
		   [6,5,7],
		  [4,1,8,3]
		]
	自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
	
	说明：	
		如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/triangle
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//120. 三角形最小路径和
public class Triangle {
	public static void main(String[] args) {
		List<List<Integer>> triangle = new ArrayList<>();
		triangle.add(Arrays.asList(new Integer[] { 2 }));
		triangle.add(Arrays.asList(new Integer[] { 3, 4 }));
		triangle.add(Arrays.asList(new Integer[] { 6, 5, 7 }));
		triangle.add(Arrays.asList(new Integer[] { 4, 1, 8, 3 }));

		new Triangle().minimumTotal(triangle);
	}

	// 递归(超时)
	public int minimumTotal2(List<List<Integer>> triangle) {
		if (triangle == null || triangle.size() == 0) {
			return 0;
		}

		int res = getMinimumTotal(triangle, 1, 0, triangle.get(0).get(0));
		return res;
	}

	private int getMinimumTotal(List<List<Integer>> triangle, int row, int col, int res) {
		if (row == triangle.size()) {
			return res;
		}

		int m = getMinimumTotal(triangle, row + 1, col, res + triangle.get(row).get(col));
		int n = getMinimumTotal(triangle, row + 1, col + 1, res + triangle.get(row).get(col + 1));
		return Math.min(m, n);
	}

	// 记忆化搜索
	public int minimumTotal1(List<List<Integer>> triangle) {
		if (triangle == null || triangle.size() == 0) {
			return 0;
		}
		int length = triangle.get(triangle.size() - 1).size();
		int[][] map = new int[length][length];
		for (int[] m : map) {
			Arrays.fill(m, Integer.MIN_VALUE);
		}

		getMinimumTotal(triangle, 0, 0, map);
		return map[0][0];
	}

	private int getMinimumTotal(List<List<Integer>> triangle, int i, int j, int[][] map) {
		if (i == triangle.size() - 1) {
			map[i][j] = triangle.get(i).get(j);
			return map[i][j];
		}

		int m = (map[i + 1][j] == Integer.MIN_VALUE) ? getMinimumTotal(triangle, i + 1, j, map) : map[i + 1][j];
		int n = (map[i + 1][j + 1] == Integer.MIN_VALUE) ? getMinimumTotal(triangle, i + 1, j + 1, map) : map[i + 1][j];

		map[i][j] = triangle.get(i).get(j) + Math.min(m, n);
		return map[i][j];

	}

	// 动态规划(O(N^2)的空间复杂度)
	public int minimumTotal0(List<List<Integer>> triangle) {
		if (triangle == null || triangle.size() == 0) {
			return 0;
		}
		int n = triangle.get(triangle.size() - 1).size();
		int[][] map = new int[n][n];
		for (int i = 0; i < n; i++) {
			map[n - 1][i] = triangle.get(n - 1).get(i);
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				map[i][j] = triangle.get(i).get(j) + Math.min(map[i + 1][j], map[i + 1][j + 1]);
			}
		}
		return map[0][0];
	}

	// 动态规划(O(N)的空间复杂度)
	public int minimumTotal(List<List<Integer>> triangle) {
		if (triangle == null || triangle.size() == 0) {
			return 0;
		}
		int n = triangle.get(triangle.size() - 1).size();
		int[] dp = new int[n];
		for (int i = 0; i < n; i++) {
			dp[i] = triangle.get(n - 1).get(i);
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
			}
		}
		return dp[0];
	}
}
