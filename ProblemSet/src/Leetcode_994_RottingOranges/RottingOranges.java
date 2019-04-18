package Leetcode_994_RottingOranges;

import java.util.LinkedList;
import java.util.Queue;

/*
	在给定的网格中，每个单元格可以有以下三个值之一：	
		值 0 代表空单元格；
		值 1 代表新鲜橘子；
		值 2 代表腐烂的橘子。
		每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
	
	返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。 
	
	示例 1：	
		输入：[ 	[2,1,1],
				[1,1,0],
				[0,1,1]]
		输出：4
	示例 2：	
		输入：[	[2,1,1],
				[0,1,1],
				[1,0,1]]
		输出：-1
		解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
	示例 3：	
		输入：[[0,2]]
		输出：0
		解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。	 
	
	提示：	
		1 <= grid.length <= 10
		1 <= grid[0].length <= 10
		grid[i][j] 仅为 0、1 或 2
 */

//994. 腐烂的橘子
public class RottingOranges {
	public static void main(String[] args) {
		int[][] grid = { { 2, 1, 1 }, { 1, 1, 0 }, { 0, 1, 1 } };
		RottingOranges ro = new RottingOranges();
		System.out.println(ro.orangesRotting(grid));

	}

	public int orangesRotting(int[][] grid) {
		if (grid == null || grid.length == 0)
			return 0;
		Queue<int[]> queue = new LinkedList<int[]>();
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if (grid[i][j] == 2) {
					queue.offer(new int[] { i, j });
				}
			}
		}
		int res = 0;
		// 上下左右
		int[][] round = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		res = orangesRotting(grid, queue, round, res);
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if (grid[i][j] == 1) {
					return -1;
				}
			}
		}

		return res;
	}

	private int orangesRotting(int[][] grid, Queue<int[]> queue, int[][] round, int res) {
		int size = queue.size();
		if (size == 0) {
			return res;
		}
		// res+=1;
		boolean flag = false;
		for (int i = 0; i < size; i++) {
			int[] cur = queue.poll();
			for (int j = 0; j < round.length; j++) {
				int x = cur[0] + round[j][0];
				int y = cur[1] + round[j][1];
				if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length && grid[x][y] == 1) {
					grid[x][y] = 2;
					queue.offer(new int[] { x, y });
					flag = true;
				}
			}
		}
		if (flag) {
			res += 1;
		}
		res = orangesRotting(grid, queue, round, res);
		return res;
	}

	// 迭代
	public int orangesRotting0(int[][] grid) {
		if (grid == null || grid.length == 0)
			return 0;
		int rows = grid.length;
		int cols = grid[0].length;
		Queue<int[]> queue = new LinkedList<>();
		int count_fresh = 0;
		// Put the position of all rotten oranges in queue
		// count the number of fresh oranges
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == 2) {
					queue.offer(new int[] { i, j });
				} else if (grid[i][j] == 1) {
					count_fresh++;
				}
			}
		}
		// if count of fresh oranges is zero --> return 0
		if (count_fresh == 0)
			return 0;
		int count = 0;
		int[][] dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		// bfs starting from initially rotten oranges
		while (!queue.isEmpty()) {
			++count;
			int size = queue.size();
			for (int i = 0; i < size; i++) {
				int[] point = queue.poll();
				for (int dir[] : dirs) {
					int x = point[0] + dir[0];
					int y = point[1] + dir[1];
					// if x or y is out of bound
					// or the orange at (x , y) is already rotten
					// or the cell at (x , y) is empty
					// we do nothing
					if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] == 0 || grid[x][y] == 2)
						continue;
					// mark the orange at (x , y) as rotten
					grid[x][y] = 2;
					// put the new rotten orange at (x , y) in queue
					queue.offer(new int[] { x, y });
					// decrease the count of fresh oranges by 1
					count_fresh--;
				}
			}
		}
		return count_fresh == 0 ? count - 1 : -1;
	}
}
