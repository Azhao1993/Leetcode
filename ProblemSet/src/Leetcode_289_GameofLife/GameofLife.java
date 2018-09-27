package Leetcode_289_GameofLife;

import java.util.Arrays;

import UsualMethod.matrixOutput;

/*
	根据百度百科，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。
	
	给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
	每个细胞具有一个初始状态 live（1）即为活细胞， 或 dead（0）即为死细胞。
	每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
	
	如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
	如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
	如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
	如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
	
	根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
	
	示例:
		输入: 
			[
			  [0,1,0],
			  [0,0,1],
			  [1,1,1],
			  [0,0,0]
			]
		输出: 
			[
			  [0,0,0],
			  [1,0,1],
			  [0,1,1],
			  [0,1,0]
			]
		
	进阶:
		你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
		本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
*/
public class GameofLife {
	// 289.生命游戏
	public void gameOfLife(int[][] board) {
//		如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；livecount<2,1 —— 2 
//		如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；livecount==2==3 1 —— 1
//		如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；livecount >3 1 —— 2
//		如果死细胞周围正好有三个活细胞，则该位置死细胞复活；livecount == 3; 0 —— -1
		int row = board.length;
		int col = board[0].length;
		// int[][] state = new int[row][col];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				// 活细胞
				if (board[i][j] == 1) {
					int livecount = around(board, i, j)-1;					
					// 周围小于2,死
					if (livecount < 2) {
						// state[i][j] = -1;
						board[i][j] = 2;
					} else if (livecount > 3) {
						// state[i][j] = -1;
						board[i][j] = 2;
					}
				// 死细胞
				} else {
					int diecount = around(board, i, j);					
					// 刚好三个活细胞
					if (diecount == 3) {
						// state[i][j] = 1;
						board[i][j] = -1;
					}
				}

			}
		}
		//遍历
		for(int i = 0;i<row;i++) {
			for(int j = 0;j<col;j++) {
				if(board[i][j]==2) {
					board[i][j] =0;
				}
				if(board[i][j]==-1) {
					board[i][j] =1;
				}
			}
		}
	}

	// 判断周围情况
	public int around(int[][] board, int i, int j) {
		int count = 0;
		for(int m = Math.max(i-1, 0);m<=Math.min(i+1, board.length-1);m++) {
			for(int n = Math.max(j-1, 0);n<=Math.min(j+1, board[0].length-1);n++) {
				if(board[m][n] >=1) {
					count++;					
				}				
			}
		}
		return count;
	}

}
