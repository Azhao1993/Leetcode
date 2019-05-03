package Leetcode_856_ScoreofParentheses;

import java.util.Stack;

/*
	给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：	
		() 得 1 分。
		AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
		(A) 得 2 * A 分，其中 A 是平衡括号字符串。
	 
	
	示例 1：	
		输入： "()"
		输出： 1
	示例 2：	
		输入： "(())"
		输出： 2
	示例 3：	
		输入： "()()"
		输出： 2
	示例 4：	
		输入： "(()(()))"
		输出： 6 
	
	提示：	
		S 是平衡括号字符串，且只含有 ( 和 ) 。
		2 <= S.length <= 50
 */

//856. 括号的分数
public class ScoreofParentheses {

	public int scoreOfParentheses(String S) {
		Stack<Integer> stack = new Stack<Integer>();
		// Stack<Character> num = new Stack<>();
		int res = 0;
		for (char ch : S.toCharArray()) {
			if (ch == '(') {
				stack.push(res);
				res = 0;
			} else {
				res = stack.pop() + Math.max(res * 2, 1);
			}
		}
		return res;
	}

	// 1ms
	public int scoreOfParentheses0(String S) {
		int point = 0;
		int mul = 0;
		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == '(') {
				mul++;
			} else {
				mul--;
			}
			if (S.charAt(i) == ')' && S.charAt(i - 1) == '(') {
				point += 1 << mul; // 1乘几个2
			}
		}
		return point;
	}

}
