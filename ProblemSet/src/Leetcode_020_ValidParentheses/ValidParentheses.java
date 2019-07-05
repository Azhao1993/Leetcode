package Leetcode_020_ValidParentheses;

import java.util.HashMap;
import java.util.Stack;

/*
	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
	
	有效字符串需满足：	
		左括号必须用相同类型的右括号闭合。//和为0
		左括号必须以正确的顺序闭合。
		注意空字符串可被认为是有效字符串。
	
	示例 1:	
		输入: "()"
		输出: true
	示例 2:	
		输入: "()[]{}"
		输出: true
	示例 3:	
		输入: "(]"
		输出: false
	示例 4:	
		输入: "([)]"
		输出: false
	示例 5:	
		输入: "{[]}"
		输出: true
*/
public class ValidParentheses {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		ValidParentheses vp = new ValidParentheses();
		System.out.println(vp.isValid("()"));
	}

	// 20.有效的括号
	public boolean isValid(String s) {

		Stack<Character> stack = new Stack<Character>();
		for (char temp : s.toCharArray()) {
			if ((temp == '(') || (temp == '[') || (temp == '{')) {
				stack.push(temp);
			} else {
				if (stack.isEmpty()) {
					return false;
				}
				char c = stack.pop();
				char match;
				if ((temp == ')')) {
					match = '(';
				} else if (temp == ']') {
					match = '[';
				} else {
					match = '}';
				}

				if (c != match) {
					return false;
				}
			}

		}

		return stack.isEmpty();

	}

	// 4ms
	public boolean isValid0(String s) {
		char[] stack = new char[s.length() / 2 + 1];
		int k = 0;
		for (int i = 0; i < s.length(); i++) {
			char x = s.charAt(i);
			switch (x) {
			case '(':
			case '[':
			case '{':
				stack[k++] = x;
				break;
			case ')':
				if (k <= 0 || stack[--k] != '(') {
					return false;
				}
				break;
			case ']':
				if (k <= 0 || stack[--k] != '[') {
					return false;
				}
				break;
			case '}':
				if (k <= 0 || stack[--k] != '{') {
					return false;
				}
				break;
			}
		}
		return k == 0;
	}

}
