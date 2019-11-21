package Leetcode_200_NumberofIslands;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

/*
	给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
	
	示例 1:	
		输入:
			11110
			11010
			11000
			00000	
		输出: 1
	
	示例 2:	
		输入:
			11000
			11000
			00100
			00011	
		输出: 3

 */
public class NumberofIslands {
	public static void main(String[] args) {
		char[][] grid = { { '1', '1', '1' }, { '0', '1', '0' }, { '1', '1', '1' } };
		NumberofIslands ni = new NumberofIslands();
		ni.numIslands(grid);

	}

	// 200. 岛屿的个数
	// 记录仪
	boolean[][] bool;

	public int numIslands(char[][] grid) {
		int result = 0;
		if ((grid.length == 0) || (grid == null)) {
			return 0;
		}
		// 行
		int col = grid.length;
		// 列
		int row = grid[0].length;
		bool = new boolean[col][row];
		// 遍历
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if ((grid[i][j] == '0') || (bool[i][j])) {
					continue;
				} else {
					bfs(i, j, grid);
					result++;
				}
			}
		}
		return result;
	}

	private void bfs(int i, int j, char[][] grid) {
		Queue<int[]> queue = new LinkedList<int[]>();
		int[] cur = { i, j };
		queue.offer(cur);
		bool[i][j] = true;
		while (!queue.isEmpty()) {
			int size = queue.size();
			for (int a = 0; a < size; a++) {
				int[] temp = queue.peek();
				int x = temp[0];
				int y = temp[1];
				// 向上
				if ((x - 1 >= 0) && (!bool[x - 1][y]) && (grid[x - 1][y]) == '1') {
					int[] temp2 = { x - 1, y };
					queue.offer(temp2);
					bool[x - 1][y] = true;
				}
				// 向左
				if ((y - 1 >= 0) && (!bool[x][y - 1]) && (grid[x][y - 1]) == '1') {
					int[] temp2 = { x, y - 1 };
					queue.offer(temp2);
					bool[x][y - 1] = true;
				}
				// 向右
				if ((y + 1 < grid[0].length) && (!bool[x][y + 1]) && (grid[x][y + 1]) == '1') {
					int[] temp2 = { x, y + 1 };
					queue.offer(temp2);
					bool[x][y + 1] = true;
				}
				// 向下
				if ((x + 1 < grid.length) && (!bool[x + 1][y]) && (grid[x + 1][y]) == '1') {
					int[] temp2 = { x + 1, y };
					queue.offer(temp2);
					bool[x + 1][y] = true;
				}
				queue.poll();
			}
		}
	}

	// 3ms
	char[][] map;
	int dep, wid;

	public void dsf(int depth, int width) {
		if (depth < 0 || width < 0 || depth >= dep || width >= wid || map[depth][width] != '1')
			return;
		map[depth][width] = '0';
		dsf(depth + 1, width);
		dsf(depth - 1, width);
		dsf(depth, width + 1);
		dsf(depth, width - 1);
	}

	public int numIslands0(char[][] grid) {
		int count = 0;
		map = grid;
		dep = grid.length;
		if (dep == 0)
			return 0;
		wid = grid[0].length;
		for (int i = 0; i < dep; i++) {
			for (int j = 0; j < wid; j++) {
				if (map[i][j] != '1')
					continue;
				count++;
				dsf(i, j);
			}
		}
		return count;
	}

}
