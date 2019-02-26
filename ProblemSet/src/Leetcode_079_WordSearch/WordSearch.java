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
	public static void main(String[] args) {
		char[][] board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
		new WordSearch().exist(board, "SEE");
	}

	public boolean exist(char[][] board, String word) {
		if (word == null || word.length() == 0) {
			return true;
		}
		int col = board.length;
		int row = board[0].length;
		if (board == null || col == 0 || row == 0) {
			return false;
		}
		boolean[][] used = new boolean[col][row];
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] == word.charAt(0)) {
					used[i][j] = true;
					if (exist(board, word, used, 1, i, j)) {
						return true;
					} else {
						used[i][j] = false;
					}
				}
			}
		}
		return false;
	}

	private boolean exist(char[][] board, String word, boolean[][] used, int start, int i2, int j2) {
		if (start == word.length()) {
			return true;
		}
		int[][] step = { { i2 - 1, j2 }, { i2 + 1, j2 }, { i2, j2 - 1 }, { i2, j2 + 1 } };
		for (int[] arr : step) {
			int col = arr[0];
			if (!(col >= 0 && col < board.length)) {
				continue;
			}
			int row = arr[1];
			if (!(row >= 0 && row < board[0].length)) {
				continue;
			}
			if (used[col][row]) {
				continue;
			}
			if (board[col][row] == word.charAt(start)) {
				used[col][row] = true;
				if (exist(board, word, used, start + 1, col, row)) {
					return true;
				}
				used[col][row] = false;
			}
		}

		return false;
	}
}
