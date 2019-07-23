package Leetcode_052_NQueensII;

/*
	n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。	
	https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png
	上图为 8 皇后问题的一种解法。	
	给定一个整数 n，返回 n 皇后不同的解决方案的数量。
	
	示例:	
		输入: 4
		输出: 2
		解释: 4 皇后问题存在如下两个不同的解法。
			[
			 [".Q..",  // 解法 1
			  "...Q",
			  "Q...",
			  "..Q."],
			
			 ["..Q.",  // 解法 2
			  "Q...",
			  "...Q",
			  ".Q.."]
			]
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/n-queens-ii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//52. N皇后 II
public class NQueensII {

	int res = 0;
	int n;
	boolean[] col;// 列
	boolean[] dia1;// 主对角线
	boolean[] dia2;// 副对角线

	public int totalNQueens(int n) {
		this.n = n;
		col = new boolean[n];
		dia1 = new boolean[2 * n - 1];
		dia2 = new boolean[2 * n - 1];
		putQueue(0);
		return res;
	}

	private void putQueue(int index) {
		// 防止第index行的皇后
		if (index == n) {
			res++;
			return;
		}
		// 第index 行的i列
		for (int i = 0; i < n; i++) {
			if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
				col[i] = true;
				dia1[index + i] = true;
				dia2[index - i + n - 1] = true;
				putQueue(index + 1);
				col[i] = false;
				dia1[index + i] = false;
				dia2[index - i + n - 1] = false;
			}
		}
	}
}
