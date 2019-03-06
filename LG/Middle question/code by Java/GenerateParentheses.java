package Leetcode_022_GenerateParentheses;

import java.util.ArrayList;
import java.util.List;

/*
	给出 n 代表生成括号的对数，请你写出一个函数，
	使其能够生成所有可能的并且有效的括号组合。
	
	例如，给出 n = 3，生成结果为：
		[
		  "((()))",
		  "(()())",
		  "(())()",
		  "()(())",
		  "()()()"
		]
 */

//22. 括号生成
public class GenerateParentheses {
	List<String> result = null;
	int n = 0;

	public List<String> generateParenthesis(int n) {
		result = new ArrayList<String>();
		this.n = n;
		char[] arr = new char[2 * n];
		// lc：左括号,rc：右括号,pos：添加指针
		generateParenRec(0, 0, 0, arr);
		return result;
	}

	public void generateParenRec(int lc, int rc, int pos, char[] arr) {
		// lc：左括号的个数;rc:右括号的个数;pos:当前括号的索引

		// 索引到最后一个
		if (pos == arr.length) {
			result.add(new String(arr));
			return;
		}
		// 左括号数不够
		if (lc < n) {
			arr[pos] = '(';
			generateParenRec(lc + 1, rc, pos + 1, arr);
		}
		// 左括号数多于右括号数
		if (lc > rc) {
			arr[pos] = ')';
			generateParenRec(lc, rc + 1, pos + 1, arr);
		}

	}
}
