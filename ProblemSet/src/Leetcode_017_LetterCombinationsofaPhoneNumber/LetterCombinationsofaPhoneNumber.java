package Leetcode_017_LetterCombinationsofaPhoneNumber;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
	给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
	给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
	
	示例:
		输入："23"
		输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
//17. 电话号码的字母组合
public class LetterCombinationsofaPhoneNumber {
	private char[][] map = { { '0' }, { '1' }, { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' },
			{ 'j', 'k', 'l' }, { 'm', 'n', 'o' }, { 'p', 'q', 'r', 's' }, { 't', 'u', 'v' }, { 'w', 'x', 'y', 'z' } };
	List<String> res = new ArrayList<String>();
	public List<String> letterCombinations(String digits) {
		if(digits==null||digits.length()==0) {
			return res;
		}
		helper(digits.toCharArray(),0,"");
		return res;
	}

	private void helper(char[] digits, int index, String str) {
		if(index==digits.length) {
			res.add(str);
			return;
		}
		int digit = digits[index]-'0';
		for(int i = 0;i<map[digit].length;i++) {
			helper(digits,index+1,str+map[digit][i]);
		}
		
	}

	public List<String> letterCombinations1(String digits) {
		LinkedList<String> ans = new LinkedList<String>();// 队列
		if (digits.isEmpty()) {
			return ans;
		}
		String[] mapping = new String[] { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		ans.add("");
		for (int i = 0; i < digits.length(); i++) {
			// 数字x
			int x = Character.getNumericValue(digits.charAt(i));
			// 判断是否添加完毕，字符串的长度与数字的位置相等
			while (ans.peek().length() == i) {
				String t = ans.remove();
				for (char s : mapping[x].toCharArray())
					ans.add(t + s);
			}
		}
		return ans;

	}
}
