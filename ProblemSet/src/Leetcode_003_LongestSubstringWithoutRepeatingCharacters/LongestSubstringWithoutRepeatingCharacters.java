package Leetcode_003_LongestSubstringWithoutRepeatingCharacters;

import java.util.ArrayList;
import java.util.List;

/*
	给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
	
	示例 1:	
		输入: "abcabcbb"
		输出: 3 
		解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
	示例 2:	
		输入: "bbbbb"
		输出: 1
		解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
	示例 3:	
		输入: "pwwkew"
		输出: 3
		解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
		     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
public class LongestSubstringWithoutRepeatingCharacters {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "au";
		new LongestSubstringWithoutRepeatingCharacters().lengthOfLongestSubstring(s);
	}

	// 3. 无重复字符的最长子串
	public int lengthOfLongestSubstring(String s) {
		
	}
	//超出内存限制 
	public int lengthOfLongestSubstring1(String s) {
		if (s.length() <= 1) {
			return s.length();
		}
		int maxlength = Integer.MIN_VALUE;
		List<Character> list = new ArrayList<Character>();
		for (int i = 0; i < s.length(); i++) {
			if (list.contains(s.charAt(i))) {
				maxlength = Math.max(maxlength, list.size());
				break;
			} else {
				list.add(s.charAt(i));
			}
			if (i == s.length() - 1) {
				maxlength = Math.max(maxlength, list.size());
			}
		}
		return Math.max(maxlength, lengthOfLongestSubstring(s.substring(1, s.length())));
	}

}
