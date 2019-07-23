package Leetcode_051_NQueens;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/*
	n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
	https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png
	上图为 8 皇后问题的一种解法。
	给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
	每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
	
	示例:
		输入: 4
		输出: [
			 [".Q..",  // 解法 1
			  "...Q",
			  "Q...",
			  "..Q."],
			
			 ["..Q.",  // 解法 2
			  "Q...",
			  "...Q",
			  ".Q.."]
			]
		解释: 4 皇后问题存在两个不同的解法。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/n-queens
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//51.N皇后
public class NQueens {
	List<List<String>> res = new ArrayList<>();
	int n;
	boolean[] col;// 列
	boolean[] dia1;// 主对角线
	boolean[] dia2;// 副对角线

	public List<List<String>> solveNQueens(int n) {
		this.n = n;
		col = new boolean[n];
		dia1 = new boolean[2 * n - 1];
		dia2 = new boolean[2 * n - 1];
		putQueue(0, new LinkedList<Integer>());
		return res;
	}

	private void putQueue(int index, LinkedList<Integer> list) {
		// 防止第index行的皇后
		if (index == n) {
			res.add(generateBoard(list));
			return;
		}
		// 第index 行的i列
		for (int i = 0; i < n; i++) {
			if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
				col[i] = true;
				dia1[index + i] = true;
				dia2[index - i + n - 1] = true;
				list.add(i);
				putQueue(index + 1, list);
				col[i] = false;
				dia1[index + i] = false;
				dia2[index - i + n - 1] = false;
				list.removeLast();
			}
		}

	}

	private List<String> generateBoard(LinkedList<Integer> list) {
		char[] arr = new char[n];
		Arrays.fill(arr, '.');
		List<String> res = new ArrayList<>();
		for (int i = 0; i < list.size(); i++) {
			arr[list.get(i)] = 'Q';
			res.add(String.valueOf(arr));
			arr[list.get(i)] = '.';
		}
		return res;
	}

}
