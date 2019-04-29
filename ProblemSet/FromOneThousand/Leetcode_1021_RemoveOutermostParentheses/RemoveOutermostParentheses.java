package Leetcode_1021_RemoveOutermostParentheses;

import java.util.LinkedList;
import java.util.Queue;

/*
	有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，
	其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。
	例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
	
	如果有效字符串 S 非空，且不存在将其拆分为 S = A+B 的方法，
	我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。
	
	给出一个非空有效字符串 S，考虑将其进行原语化分解，
	使得：S = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。
	
	对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。	 
	
	示例 1：	
		输入："(()())(())"
		输出："()()()"
		解释：
		输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
		删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
	示例 2：	
		输入："(()())(())(()(()))"
		输出："()()()()(())"
		解释：
		输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
		删除每隔部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
	示例 3：	
		输入："()()"
		输出：""
		解释：
		输入字符串为 "()()"，原语化分解得到 "()" + "()"，
		删除每个部分中的最外层括号后得到 "" + "" = ""。
 */
// 1021. 删除最外层的括号
public class RemoveOutermostParentheses {
	public static void main(String[] args) {
		String S = "()()";
		String res = "";
		System.out.println(new RemoveOutermostParentheses().removeOuterParentheses(S).equals(res));
	}

	public String removeOuterParentheses(String S) {
		Queue<Character> queue = new LinkedList<Character>();
		int count = 0;
		StringBuilder res = new StringBuilder();
		for (int i = 0; i < S.length(); i++) {
			if (count == 0 && !queue.isEmpty()) {
				clearMyQueue(queue, res);
			}
			if (S.charAt(i) == '(') {
				count++;
			} else {
				count--;
			}
			queue.add(S.charAt(i));
		}
		if (!queue.isEmpty()) {
			clearMyQueue(queue, res);
		}
		return res.toString();

	}

	// queue.clear
	public void clearMyQueue(Queue<Character> queue, StringBuilder res) {
		queue.poll();
		while (queue.size() > 1) {
			res.append(queue.poll());
		}
		queue.poll();
	}

	// 2ms
	public String removeOuterParentheses0(String S) {
		int length = S.length();
		char[] primitive = new char[length];
		// 标记"("的个数
		int flag = 0;
		// 记录数组的有效长度
		int count = 0;
		char[] ch = S.toCharArray();
		for (int i = 0; i < length; i++) {
			if (flag == 0) {
				++flag;
			} else {
				if (ch[i] == '(') {
					primitive[count] = '(';
					++count;
					++flag;
				} else {
					--flag;
					if (flag > 0) {
						primitive[count] = ')';
						++count;
					}
				}
			}
		}
		String Str = String.valueOf(primitive);
		Str = Str.substring(0, count);
		return Str;
	}
}
