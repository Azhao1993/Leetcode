package Leetcode_394_DecodeString;

import java.util.Stack;

/*
	给定一个经过编码的字符串，返回它解码后的字符串。	
	编码规则为:
	 k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。	
	你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。	
	此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
	
	示例:	
		s = "3[a]2[bc]", 返回 "aaabcbc". 
		s = "3[a2[c]]", 返回 "accaccacc".
		s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
 */
public class DecodeString {
	// 394. 字符串解码
	public String decodeString(String s) {
		String res = "";
		// 记录'['之前的数字
		Stack<Integer> countStack = new Stack<Integer>();
		// 记录'['之前的运算结果
		Stack<String> resStack = new Stack<String>();
		int idx = 0;// 字符的位置
		int curNum = 0;// 当前数字
		while (idx < s.length()) {
			char ch = s.charAt(idx);
			if (Character.isDigit(ch)) {
				while (Character.isDigit(s.charAt(idx)))
					curNum = 10 * curNum + (s.charAt(idx++) - '0');
			} else if (ch == '[') {
				// 遇到[，说明出现新的串，将原来的字符串压入栈
				resStack.push(res);
				res = "";// 置空
				// 将新的串的重复次数压入栈
				countStack.push(curNum);
				curNum = 0;// 置零
				idx++;
			} else if (ch == ']') {
				// 遇到]，当前串res结束
				// temp为之前的串
				StringBuilder temp = new StringBuilder(resStack.pop());
				// 拼接当前的串
				int repeatTimes = countStack.pop();
				for (int i = 0; i < repeatTimes; i++) {
					temp.append(res);
				}
				res = temp.toString();
				idx++;
			} else {
				// 出现字母，拼接到当前的串
				res += s.charAt(idx++);
			}
		}
		return res;
	}

}
