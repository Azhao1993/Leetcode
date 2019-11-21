package Leetcode_005_LongestPalindromicSubstring;

/*
	给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
	
	示例 1：	
		输入: "babad"
		输出: "bab"
		注意: "aba" 也是一个有效答案。
	示例 2：	
		输入: "cbbd"
		输出: "bb"
 */

//5.最长回文子串
public class LongestPalindromicSubstring {
	public static void main(String[] args) {
		String s = "babad";
		LongestPalindromicSubstring lps = new LongestPalindromicSubstring();
		System.out.println(lps.longestPalindrome0(s));

	}

	public String longestPalindrome(String s) {
		if (s == null || s.length() == 0) {
			return "";
		}
		if (s.length() == 1) {
			return s;
		}
		String result = "";
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 1; j <= s.length(); j++) {
				String temp = s.substring(i, j);
				if (isPalindromic(temp) && temp.length() > result.length()) {
					result = temp;
				}
			}
		}
		return result;
	}

	private boolean isPalindromic(String temp) {
		for (int i = 0; i < temp.length() / 2; i++) {
			if (temp.charAt(i) != temp.charAt(temp.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}

	//6ms
	public String longestPalindrome0(String s) {
		int length = s.length();

		int[] range = new int[2];
		for (int i = 0; i < length; i++) {
			i = helper(s, range, i);
		}

		return s.substring(range[0], range[1]);
	}

	public int helper(String s, int[] range, int i) {
		int lo = i;
		int hi = i;
		//有连续相同的字符
		while (hi < s.length() - 1 && s.charAt(hi) == s.charAt(hi + 1)) {
			hi++;
		}
		int ret = hi;
		
		//i-1,i+1,找回文
		while (lo > 0 && hi < s.length() - 1 && s.charAt(lo - 1) == s.charAt(hi + 1)) {
			lo--;
			hi++;
		}
		//判断长度，记录回文范围
		if (hi - lo + 1 > range[1] - range[0]) {
			range[0] = lo;
			range[1] = hi + 1;
		}

		return ret;
	}
}
