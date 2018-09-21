package Leetcode_289_GameofLife;

import java.util.Arrays;

import UsualMethod.matrixOutput;

/*
	���ݰٶȰٿƣ�������Ϸ�����Ϊ��������Ӣ����ѧ��Լ�����ζ١�������1970�귢����ϸ���Զ�����
	
	����һ������ m �� n �����ӵ���壬ÿһ�����Ӷ����Կ�����һ��ϸ����
	ÿ��ϸ������һ����ʼ״̬ live��1����Ϊ��ϸ���� �� dead��0����Ϊ��ϸ����
	ÿ��ϸ������˸�����λ�ã�ˮƽ����ֱ���Խ��ߣ���ϸ������ѭ�����������涨�ɣ�
	
	�����ϸ����Χ�˸�λ�õĻ�ϸ�����������������λ�û�ϸ��������
	�����ϸ����Χ�˸�λ����������������ϸ�������λ�û�ϸ����Ȼ��
	�����ϸ����Χ�˸�λ���г���������ϸ�������λ�û�ϸ��������
	�����ϸ����Χ������������ϸ�������λ����ϸ�����
	
	���ݵ�ǰ״̬��дһ�����������������ϸ������һ����һ�θ��º�ģ�״̬����һ��״̬��ͨ������������ͬʱӦ���ڵ�ǰ״̬�µ�ÿ��ϸ�����γɵģ�����ϸ���ĳ�����������ͬʱ�����ġ�
	
	ʾ��:
		����: 
			[
			  [0,1,0],
			  [0,0,1],
			  [1,1,1],
			  [0,0,0]
			]
		���: 
			[
			  [0,0,0],
			  [1,0,1],
			  [0,1,1],
			  [0,1,0]
			]
		
	����:
		�����ʹ��ԭ���㷨�����������ע�⣬��������и�����Ҫͬʱ�����£��㲻���ȸ���ĳЩ���ӣ�Ȼ��ʹ�����ǵĸ��º��ֵ�ٸ����������ӡ�
		�����У�����ʹ�ö�ά��������ʾ��塣ԭ���ϣ���������޵ģ�������ϸ����ռ�����߽�ʱ��������⡣�㽫��ν����Щ���⣿
*/
public class GameofLife {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GameofLife gl = new GameofLife();
		int[][] board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
		gl.gameOfLife(board);
		//��ά�������
		matrixOutput mo = new matrixOutput();
		mo.ArrayOutput(board);
	}

	// 289.������Ϸ
	public void gameOfLife(int[][] board) {
//		�����ϸ����Χ�˸�λ�õĻ�ϸ�����������������λ�û�ϸ��������livecount<2,1 ���� 2 
//		�����ϸ����Χ�˸�λ����������������ϸ�������λ�û�ϸ����Ȼ��livecount==2==3 1 ���� 1
//		�����ϸ����Χ�˸�λ���г���������ϸ�������λ�û�ϸ��������livecount >3 1 ���� 2
//		�����ϸ����Χ������������ϸ�������λ����ϸ�����livecount == 3; 0 ���� -1
		int row = board.length;
		int col = board[0].length;
		// int[][] state = new int[row][col];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				// ��ϸ��
				if (board[i][j] == 1) {
					int livecount = around(board, i, j)-1;					
					// ��ΧС��2,��
					if (livecount < 2) {
						// state[i][j] = -1;
						board[i][j] = 2;
					} else if (livecount > 3) {
						// state[i][j] = -1;
						board[i][j] = 2;
					}
				// ��ϸ��
				} else {
					int diecount = around(board, i, j);					
					// �պ�������ϸ��
					if (diecount == 3) {
						// state[i][j] = 1;
						board[i][j] = -1;
					}
				}

			}
		}
		//����
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

	// �ж���Χ���
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