package Leetcode_037_SudokuSolver;

/*
	编写一个程序，通过已填充的空格来解决数独问题。
	
	一个数独的解法需遵循如下规则：	
		数字 1-9 在每一行只能出现一次。
		数字 1-9 在每一列只能出现一次。
		数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
	空白格用 '*' 表示。
		[
		[5,3,*,*,7,*,*,*,*],
		[6,*,*,1,9,5,*,*,*],
		[*,9,8,*,*,*,*,6,*],
		[8,*,*,*,6,*,*,*,3],
		[4,*,*,8,*,3,*,*,1],
		[7,*,*,*,2,*,*,*,6],
		[*,6,*,*,*,*,2,8,*],
		[*,*,*,4,1,9,*,*,5],
		[*,*,*,*,8,*,*,7,9]]
	
	一个数独。	
		[
		[5,3,4,6,7,8,9,1,2],
		[6,7,2,1,9,5,3,4,8],
		[1,9,8,3,4,2,5,6,7],
		[8,5,9,7,6,1,4,2,3],
		[4,2,6,8,5,3,7,9,1],
		[7,1,3,9,2,4,8,5,6],
		[9,6,1,5,3,7,2,8,4],
		[2,8,7,4,1,9,6,3,5],
		[3,4,5,2,8,6,1,7,9]]
	答案被标成红色。
	
	Note:	
		给定的数独序列只包含数字 1-9 和字符 '.' 。
		你可以假设给定的数独只有唯一解。
		给定数独永远是 9x9 形式的。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/sudoku-solver
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//37. 解数独
public class SudokuSolver {
	public static void main(String[] args) {
		char[][] board = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
				{ '6', '.', '.', '1', '9', '5', '.', '.', '.' }, { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
				{ '8', '.', '.', '.', '6', '.', '.', '.', '3' }, { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
				{ '7', '.', '.', '.', '2', '.', '.', '.', '6' }, { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
				{ '.', '.', '.', '4', '1', '9', '.', '.', '5' }, { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
		new SudokuSolver().solveSudoku(board);
	}

	// 9行
	boolean[][] row = new boolean[9][9];
	// 9列
	boolean[][] col = new boolean[9][9];
	// 9个方格
	boolean[][] s = new boolean[9][9];

	public void solveSudoku(char[][] board) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int t = board[i][j] - '1';
					row[i][t] = true;
					col[j][t] = true;
					s[i / 3 * 3 + j / 3][t] = true;
				}
			}
		}
		trySolve(0, 0, board);

	}

	private boolean trySolve(int x, int y, char[][] board) {
		if (x == -1) {
			return true;
		}

		int newx = x;
		int newy = y + 1;

		if (newy == 9) {
			newy = 0;
			newx++;
		}

		if (newx == 9) {
			newx = -1;
			newy = -1;
		}

		if (board[x][y] != '.') {
			return trySolve(newx, newy, board);
		}
		int box = x / 3 * 3 + y / 3;
		for (int m = 0; m < 9; m++) {
			if (!row[x][m] && !col[y][m] && !s[box][m]) {
				board[x][y] = (char) ('1' + m);
				row[x][m] = true;
				col[y][m] = true;
				s[box][m] = true;
				if (trySolve(newx, newy, board)) {
					return true;
				}

				row[x][m] = false;
				col[y][m] = false;
				s[box][m] = false;

			}
		}
		board[x][y] = '.';
		return false;
	}

}
