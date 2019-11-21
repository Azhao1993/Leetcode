package Leetcode_150_EvaluateReversePolishNotation;

import java.sql.Array;
import java.util.Arrays;
import java.util.Stack;

/*
	根据逆波兰表示法，求表达式的值。
	
	有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
	
	说明：	
		整数除法只保留整数部分。
		给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
	
	示例 1:	
		输入: ["2", "1", "+", "3", "*"]
		输出: 9
		解释: ((2 + 1) * 3) = 9
		
	示例 2：	
		输入: ["4", "13", "5", "/", "+"]
		输出: 6
		解释: (4 + (13 / 5)) = 6
		
	示例 3：	
		输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
		输出: 22
		解释: 
		  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
		= ((10 * (6 / (12 * -11))) + 17) + 5
		= ((10 * (6 / -132)) + 17) + 5
		= ((10 * 0) + 17) + 5
		= (0 + 17) + 5
		= 17 + 5
		= 22
 */
public class EvaluateReversePolishNotation {
	public static void main(String[] args) {
		String[] tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
		System.out.println(new EvaluateReversePolishNotation().evalRPN(tokens));
	}

	// 150. 逆波兰表达式求值
	public int evalRPN(String[] tokens) {
		Stack<Integer> s = new Stack<Integer>();
		for (String str : tokens) {
			if (str.equals("+")) {
				int temp1 = s.peek();
				s.pop();
				int temp2 = s.peek();
				s.pop();
				s.push(temp1 + temp2);
			} else if (str.equals("-")) {
				int temp1 = s.peek();
				s.pop();
				int temp2 = s.peek();
				s.pop();
				s.push(temp2 - temp1);
			} else if (str.equals("*")) {
				int temp1 = s.peek();
				s.pop();
				int temp2 = s.peek();
				s.pop();
				s.push(temp1 * temp2);
			} else if (str.equals("/")) {
				int temp1 = s.peek();
				s.pop();
				int temp2 = s.peek();
				s.pop();
				s.push(temp2 / temp1);
			} else {
				s.push(Integer.parseInt(str));
			}
		}
		return s.peek();
	}

	// 2ms
	private int N = -1;

	public int evalRPN0(String[] tokens) {

		if (N == -1)
			N = tokens.length - 1;
		String s = tokens[N--];
		char c = s.charAt(0);
		if (s.length() == 1 && "+-*/".indexOf(c) != -1) {
			int a = evalRPN(tokens);
			int b = evalRPN(tokens);
			switch (c) {
			case '+':
				return a + b;
			case '-':
				return b - a;
			case '*':
				return a * b;
			case '/':
				return b / a;
			default:
				break;
			}
		}
		return Integer.parseInt(s);
	}
}
