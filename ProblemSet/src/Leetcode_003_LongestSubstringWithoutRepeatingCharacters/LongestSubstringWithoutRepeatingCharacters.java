package Leetcode_003_LongestSubstringWithoutRepeatingCharacters;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

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
/*
	[pre,i]表示一个无重复子串，用hash表记录子串中每个字符的出现次数。 
	 初始pre = 0，i = 0，i从左往右扫描字符串，maxLength保存当前最大长度。
	 每扫描一个字符，根据对应的值来判断这个字符是否已经出现。
	 如果A[i]已存在,将pre与当前字符A[i]位置的下一个位置进行比较，选择最大者作为最新pre所指位置，然后再更新maxLength；   
	
	如果不存在，则继续扫描，(i - pre + 1)与最大长度进行比较，更新maxLength。   
	
	 将A[i]以及对应的位置i保存，更新字符最近出现的位置。

 */
public class LongestSubstringWithoutRepeatingCharacters {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "abcabcbb";
		new LongestSubstringWithoutRepeatingCharacters().lengthOfLongestSubstring(s);
	}

	// 3. 无重复字符的最长子串

	public int lengthOfLongestSubstring(String s) {
		if (s.length() <= 1) {
			return s.length();
		}
		char[] sarr = s.toCharArray();
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		int pre = 0;
		int maxLength = 0;
		for (int i = 0; i < sarr.length; i++) {
			if (map.containsKey(sarr[i])) {
				pre = Math.max(pre, (map.get(sarr[i]) + 1));
			}
			maxLength = Math.max(maxLength, i - pre + 1);
			map.put(sarr[i], i);

		}
		return maxLength;

	}

	// 19ms
	public int lengthOfLongestSubstring0(String s) {
		int ans = 0;
		int[] vis = new int[257];
		int len = s.length();
		int left = -1;
		Arrays.fill(vis, -1);
		for (int i = 0; i < len; i++) {
			if (vis[s.charAt(i)] > left) {
				left = vis[s.charAt(i)];
			}
			ans = Math.max(ans, i - left);
			vis[s.charAt(i)] = i;
		}

		return ans;
	}

	// 超出内存限制
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
