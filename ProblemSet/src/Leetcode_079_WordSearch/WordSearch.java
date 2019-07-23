package Leetcode_079_WordSearch;

/*
	给定一个二维网格和一个单词，找出该单词是否存在于网格中。
	
	单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
	
	示例:
		board =
			[
			  ['A','B','C','E'],
			  ['S','F','C','S'],
			  ['A','D','E','E']
			]
		给定 word = "ABCCED", 返回 true.
		给定 word = "SEE", 返回 true.
		给定 word = "ABCB", 返回 false.
 */
//79. 单词搜索
public class WordSearch {

	int[][] d = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
	boolean[][] used;
	int m;
	int n;
	char[][] board;
	char[] word;

	public boolean exist2(char[][] board, String word) {
		if (board == null || board.length == 0) {
			return false;
		}
		m = board.length;
		n = board[0].length;
		used = new boolean[m][n];
		this.board = board;
		this.word = word.toCharArray();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (search(i, j, 0)) {
					return true;
				}
			}
		}
		return false;

	}

	private boolean search(int startx, int starty, int index) {
		if (index == word.length - 1) {
			return board[startx][starty] == word[index];
		}
		if (board[startx][starty] == word[index]) {
			used[startx][starty] = true;
			for (int i = 0; i < 4; i++) {
				int newx = startx + d[i][0];
				int newy = starty + d[i][1];
				if (inArea(newx, newy) && !used[newx][newy]) {
					if (search(newx, newy, index + 1)) {
						return true;
					}
				}
			}
			used[startx][starty] = false;
		}
		return false;

	}

	private boolean inArea(int x, int y) {
		return x >= 0 && x < m && y >= 0 && y < n;
	}
}
