package Leetcode_130_SurroundedRegions;

/*
	给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。	
	找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
	
	示例:	
		X X X X
		X O O X
		X X O X
		X O X X
	运行你的函数后，矩阵变为：	
		X X X X
		X X X X
		X X X X
		X O X X
	解释:	
		被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
		任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
		如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/surrounded-regions
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//130. 被围绕的区域
public class SurroundedRegions {
	public static void main(String[] args) {
		char[][] board = { { 'X', 'X', 'X', 'X' }, { 'X', 'O', 'O', 'X' }, { 'X', 'X', 'O', 'X' },
				{ 'X', 'O', 'X', 'X' } };
		new SurroundedRegions().solve(board);
	}

	char[][] board;
	int m;
	int n;

	public void solve(char[][] board) {
		if (board == null || board.length <= 2) {
			return;
		}
		this.m = board.length;
		this.n = board[0].length;
		this.board = board;
		// 第一列和最后一列
		for (int i = 0; i < m; i++) {
			check(i, 0);
			if (n > 1) {
				check(i, n - 1);
			}
		}
		// 第一行和最后一行
		for (int j = 1; j < n - 1; j++) {
			check(0, j);
			if (m > 1) {
				check(m - 1, j);
			}
		}
		// O->X
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
		// 1->O
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '1') {
					board[i][j] = 'O';
				}
			}
		}
	}

	private void check(int i, int j) {
		if (board[i][j] == 'O') {
			board[i][j] = '1';
			if (i > 1) {
				check(i - 1, j);
			}
			if (j > 1) {
				check(i, j - 1);
			}
			if (i + 1 < m) {
				check(i + 1, j);
			}
			if (j + 1 < n) {
				check(i, j + 1);
			}
		}
	}
}
