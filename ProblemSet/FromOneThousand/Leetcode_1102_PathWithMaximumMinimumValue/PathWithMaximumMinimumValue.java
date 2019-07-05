package Leetcode_1102_PathWithMaximumMinimumValue;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class PathWithMaximumMinimumValue {

	public static void main(String[] args) {
		int[][] A = { { 2, 0, 5, 2, 0 }, { 2, 4, 4, 4, 3 }, { 1, 5, 0, 0, 0 }, { 5, 4, 4, 3, 1 }, { 1, 3, 1, 5, 3 } };

		new PathWithMaximumMinimumValue().maximumMinimumPath(A);
	}

	// 1102.得分最高的路径
	public int maximumMinimumPath(int[][] A) {
		if (A == null || A.length == 0) {
			return 0;
		}
		int m = A.length;
		int n = A[0].length;
		if (m == 1 && n == 1) {
			return A[0][0];
		}

		int res = Math.min(A[0][0], A[m - 1][n - 1]);
		boolean[][] used = new boolean[m][n];

		// 存放坐标，二维转一维 x*n+y
		Queue<Integer> que = new LinkedList<>();
		// 备用的点
		PriorityQueue<int[]> backup = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return A[o2[0]][o2[1]] - A[o1[0]][o1[1]];
			}
		});
		que.add(0);
		used[0][0] = true;
		int[][] dxy = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
		while (!que.isEmpty()) {
			int cur = que.poll();
			for (int i = 0; i < 4; i++) {
				int x = cur / n + dxy[i][0];
				int y = cur % n + dxy[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n || used[x][y]) {
					continue;
				}

				if (x == m - 1 && y == n - 1) {
					return res;
				}

				if (A[x][y] >= res) {
					que.add(x * n + y);
					used[x][y] = true;
				} else {
					backup.add(new int[] { x, y });
				}
			}
			if (que.size() == 0) {
				int[] newBegin = backup.poll();
				res = A[newBegin[0]][newBegin[1]];
				que.add(newBegin[0] * n + newBegin[1]);
				used[newBegin[0]][newBegin[1]] = true;
			}
		}
		return res;
	}
}
