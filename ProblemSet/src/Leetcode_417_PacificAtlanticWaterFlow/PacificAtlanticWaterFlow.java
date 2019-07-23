package Leetcode_417_PacificAtlanticWaterFlow;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
	给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。
	“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
	规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
	请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
	
	提示：
		输出坐标的顺序不重要
		m 和 n 都小于150
	
	示例：
		给定下面的 5x5 矩阵:		
			  太平洋	  ~   ~   ~   ~   ~ 
			       ~  1   2   2   3  (5) *
			       ~  3   2   3  (4) (4) *
			       ~  2   4  (5)  3   1  *
			       ~ (6) (7)  1   4   5  *
			       ~ (5)  1   1   2   4  *
			          *   *   *   *   * 大西洋		
		返回:
			[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//417. 太平洋大西洋水流问题
public class PacificAtlanticWaterFlow {
	int[][] dir = new int[][] { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
	int n;
	int m;
	int[][] matrix;
	List<List<Integer>> res = new LinkedList<>();

	public List<List<Integer>> pacificAtlantic(int[][] matrix) {
		if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
			return res;
		}
		this.matrix = matrix;
		this.m = matrix.length;
		this.n = matrix[0].length;

		boolean[][] pacific = new boolean[m][n];
		boolean[][] atlantic = new boolean[m][n];

		Queue<int[]> pQueue = new LinkedList<>();
		Queue<int[]> aQueue = new LinkedList<>();
		for (int i = 0; i < m; i++) {
			pQueue.offer(new int[] { i, 0 });
			aQueue.offer(new int[] { i, n - 1 });
			pacific[i][0] = true;
			atlantic[i][n - 1] = true;
		}
		for (int i = 0; i < n; i++) {
			pQueue.offer(new int[] { 0, i });
			aQueue.offer(new int[] { m - 1, i });
			pacific[0][i] = true;
			atlantic[m - 1][i] = true;
		}
		bfs(pQueue, pacific);
		bfs(aQueue, atlantic);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (pacific[i][j] && atlantic[i][j])
					res.add(Arrays.asList(new Integer[] { i, j }));
			}
		}
		return res;
	}

	public void bfs(Queue<int[]> queue, boolean[][] visited) {
		while (!queue.isEmpty()) {
			int[] cur = queue.poll();
			for (int[] d : dir) {
				int x = cur[0] + d[0];
				int y = cur[1] + d[1];
				if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || matrix[x][y] < matrix[cur[0]][cur[1]]) {
					continue;
				}
				visited[x][y] = true;
				queue.offer(new int[] { x, y });
			}
		}
	}

	public List<List<Integer>> pacificAtlantic2(int[][] matrix) {
		List<List<Integer>> res = new LinkedList<>();
		if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
			return res;
		}
		this.m = matrix.length;
		this.n = matrix[0].length;
		this.matrix = matrix;
		boolean[][] pacific = new boolean[m][n];
		boolean[][] atlantic = new boolean[m][n];
		for (int i = 0; i < m; i++) {
			dfs(pacific, Integer.MIN_VALUE, i, 0);
			dfs(atlantic, Integer.MIN_VALUE, i, n - 1);
		}
		for (int i = 0; i < n; i++) {
			dfs(pacific, Integer.MIN_VALUE, 0, i);
			dfs(atlantic, Integer.MIN_VALUE, m - 1, i);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (pacific[i][j] && atlantic[i][j]) {
					res.add(Arrays.asList(new Integer[] { i, j }));
				}
			}
		}
		return res;
	}

	public void dfs(boolean[][] visited, int height, int x, int y) {
		if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || matrix[x][y] < height) {
			return;
		}
		visited[x][y] = true;
		for (int[] d : dir) {
			dfs(visited, matrix[x][y], x + d[0], y + d[1]);
		}
	}
}
