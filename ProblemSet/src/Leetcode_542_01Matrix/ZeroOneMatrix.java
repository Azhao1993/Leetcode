package Leetcode_542_01Matrix;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import UsualMethod.ArrayUtil;

/*
	给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
	
	两个相邻元素间的距离为 1 。
	
	示例 1: 
		输入:	
			0 0 0
			0 1 0
			0 0 0
		输出:		
			0 0 0
			0 1 0
			0 0 0
		
	示例 2: 
		输入:		
			0 0 0
			0 1 0
			1 1 1
		输出:		
			0 0 0
			0 1 0
			1 2 1
		
	注意:		
		给定矩阵的元素个数不超过 10000。
		给定矩阵中至少有一个元素是 0。
		矩阵中的元素只在四个方向上相邻: 上、下、左、右。
 */
public class ZeroOneMatrix {
	public static void main(String[] args) {
		ZeroOneMatrix zom = new ZeroOneMatrix();
		int[][] matrix = { { 0, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 } };
		zom.updateMatrix(matrix);
		ArrayUtil.ArrayOutput(matrix);

	}

	// 542. 01 矩阵
	public int[][] updateMatrix(int[][] matrix) {
		// 行
		int m = matrix.length;
		// 列
		int n = matrix[0].length;
		// 队列+BFS
		Queue<int[]> queue = new LinkedList<int[]>();
		// 遍历
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// 0入队，1置为最大值
				if (matrix[i][j] == 0) {
					queue.offer(new int[] { i, j });
				} else {
					matrix[i][j] = Integer.MAX_VALUE;
				}
			}
		}
		// 向上，向下，向左，向右
		int[][] dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

		while (!queue.isEmpty()) {
			int[] cur = queue.poll();
			for (int[] d : dirs) {
				int r = cur[0] + d[0];
				int c = cur[1] + d[1];
				// 不存在向上、下、左、右的邻居节点[r][c]或邻居节点为已赋值
				if (r < 0 || r >= m || c < 0 || c >= n || matrix[r][c] <= matrix[cur[0]][cur[1]] + 1) {
					continue;
				}
				// 存在邻居节点[r][c]且邻居节点为1
				queue.add(new int[] { r, c });
				matrix[r][c] = matrix[cur[0]][cur[1]] + 1;
			}
		}

		return matrix;
	}

}
