package Leetcode_036_ValidSudoku;

import java.util.ArrayList;
import java.util.List;

/*
	判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
	
	数字 1-9 在每一行只能出现一次。
	数字 1-9 在每一列只能出现一次。
	数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
	
	图片：https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png
	上图是一个部分填充的有效的数独。
	
	数独部分空格内已填入了数字，空白格用 '.' 表示。
	
	示例 1:	
		输入:
			[
			  ["5","3",".",".","7",".",".",".","."],
			  ["6",".",".","1","9","5",".",".","."],
			  [".","9","8",".",".",".",".","6","."],
			  ["8",".",".",".","6",".",".",".","3"],
			  ["4",".",".","8",".","3",".",".","1"],
			  ["7",".",".",".","2",".",".",".","6"],
			  [".","6",".",".",".",".","2","8","."],
			  [".",".",".","4","1","9",".",".","5"],
			  [".",".",".",".","8",".",".","7","9"]
			]
		输出: true
		
	示例 2:	
		输入:
			[
			  ["8","3",".",".","7",".",".",".","."],
			  ["6",".",".","1","9","5",".",".","."],
			  [".","9","8",".",".",".",".","6","."],
			  ["8",".",".",".","6",".",".",".","3"],
			  ["4",".",".","8",".","3",".",".","1"],
			  ["7",".",".",".","2",".",".",".","6"],
			  [".","6",".",".",".",".","2","8","."],
			  [".",".",".","4","1","9",".",".","5"],
			  [".",".",".",".","8",".",".","7","9"]
			]
		输出: false
	解释:
		除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
		但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
	说明:	
		一个有效的数独（部分已被填充）不一定是可解的。
		只需要根据以上规则，验证已经填入的数字是否有效即可。
		给定数独序列只包含数字 1-9 和字符 '.' 。
		给定数独永远是 9x9 形式的。
 */
public class ValidSudoku {
	// 36. 有效的数独
	public boolean isValidSudoku(char[][] board) {
		// 行
		List<Character> rowlist;
		for (int i = 0; i < 9; i++) {
			rowlist = new ArrayList<Character>();
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					if (rowlist.contains(board[i][j])) {
						return false;
					} else {
						rowlist.add(board[i][j]);
					}
				}
			}
		}
		// 列
		List<Character> collist;
		for (int i = 0; i < 9; i++) {
			collist = new ArrayList<Character>();
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.') {
					if (collist.contains(board[j][i])) {
						return false;
					} else {
						collist.add(board[j][i]);
					}
				}
			}
		}
		// 九宫格：
		List<Character> jiugonggelist;
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {
				jiugonggelist = new ArrayList<Character>();
				for (int i = 3 * x + 0; i < 3 * x + 3; i++) {
					for (int j = 3 * y + 0; j < 3 * y + 3; j++) {
						if (board[i][j] != '.') {
							if (jiugonggelist.contains(board[i][j])) {
								return false;
							} else {
								jiugonggelist.add(board[i][j]);
							}
						}
					}
				}
			}
		}
		return true;

	}

	// 14ms
	public boolean isValidSudoku0(char[][] board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;
				for (int k = 8; k > j; k--)
					if (board[i][j] == board[i][k])
						return false;
				for (int k = 8; k > i; k--)
					if (board[i][j] == board[k][j])
						return false;
				for (int k = i + 1; k % 3 != 0; k++) {
					for (int h = j / 3 * 3; h <  j / 3 * 3 + 3; h++)
						if (board[i][j] == board[k][h])
							return false;
				}
			}
		}
		return true;
	}
}
