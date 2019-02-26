package Leetcode_784_LetterCasePermutation;

import java.util.ArrayList;
import java.util.List;

/*
	给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
	
	示例:
		输入: S = "a1b2"
		输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
		
		输入: S = "3z4"
		输出: ["3z4", "3Z4"]
		
		输入: S = "12345"
		输出: ["12345"]
		
	注意：		
		S 的长度不超过12。
		S 仅由数字和字母组成。
 */
public class LetterCasePermutation {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String S = "a1b2";
		LetterCasePermutation lcp = new LetterCasePermutation();
		lcp.letterCasePermutation(S);
	}

	// 784. 字母大小写全排列
	public List<String> letterCasePermutation(String S) {
		List<String> result = new ArrayList<String>();
		StringBuilder temStr = new StringBuilder(S);
		letterCasePermutation(temStr, S, S.length() - 1, result);

		return result;
	}

	public void letterCasePermutation(StringBuilder temStr, String S, int end, List<String> result) {
		result.add(temStr.toString());
		for (int i = end; i >= 0; i--) {
			char temp = S.charAt(i);
			if (temp >= 'a' && temp <= 'z') {
				temStr.replace(i, i + 1, String.valueOf((char) (temp - 32)));
				letterCasePermutation(temStr, S, i - 1, result);
				temStr.replace(i, i + 1, String.valueOf(temp));
			} else if (temp >= 'A' && temp <= 'Z') {
				temStr.replace(i, i + 1, String.valueOf((char) (temp + 32)));
				letterCasePermutation(temStr, S, i - 1, result);
				temStr.replace(i, i + 1, String.valueOf(temp));

			}
		}
	}

	// 4ms
	public List<String> letterCasePermutation0(String S) {
		List<String> list = new ArrayList<>();
		if (S == null)
			return list;
		dfs(S.toCharArray(), 0, list);
		return list;
	}

	void dfs(char[] chars, int index, List<String> list) {
		if (index == chars.length) {
			list.add(new String(chars));
			return;
		}
		char c = chars[index];
		dfs(chars, index + 1, list);
		if (chars[index] >= 'a') {
			chars[index] = (char) (chars[index] - 32);
			dfs(chars, index + 1, list);
		} else if (chars[index] >= 'A') {
			chars[index] = (char) (chars[index] + 32);
			dfs(chars, index + 1, list);
		}

		chars[index] = c;

	}
}
