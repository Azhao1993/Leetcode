package Leetcode_139_WordBreak;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
	给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，
	判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
		
	说明：	
		拆分时可以重复使用字典中的单词。
		你可以假设字典中没有重复的单词。
	
	示例 1：	
		输入: s = "leetcode", wordDict = ["leet", "code"]
		输出: true
		解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
	
	示例 2：	
		输入: s = "applepenapple", wordDict = ["apple", "pen"]
		输出: true
		解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
		     注意你可以重复使用字典中的单词。
	
	示例 3：	
		输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
		输出: false
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/word-break
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//139. 单词拆分
public class WordBreak {
	public static void main(String[] args) {
		String s = "leetcode";
		List<String> wordDict = Arrays.asList(new String[] { "leet", "code" });
		new WordBreak().wordBreak(s, wordDict);
	}

	// 暴力递归
	public boolean wordBreak3(String s, List<String> wordDict) {
		return word_Break(s, new HashSet(wordDict), 0);
	}

	public boolean word_Break(String s, Set<String> wordDict, int start) {
		if (start == s.length()) {
			return true;
		}
		// [0,start]能不能用wordDict组成
		for (int end = start + 1; end <= s.length(); end++) {
			if (wordDict.contains(s.substring(start, end)) && word_Break(s, wordDict, end)) {
				return true;
			}
		}
		return false;
	}

	// 记忆化回溯
	public boolean wordBreak2(String s, List<String> wordDict) {
		int[] memo = new int[s.length()];
		Arrays.fill(memo, -1);// new Boolean[s.length()
		return word_Break(s, new HashSet(wordDict), 0, memo);
	}

	// [0,start]能不能用wordDict组成
	public boolean word_Break(String s, Set<String> wordDict, int start, int[] memo) {
		if (start == s.length()) {
			return true;
		}
		if (memo[start] != -1) {// memo[start] != null
			return memo[start] == 1;
		}

		for (int end = start + 1; end <= s.length(); end++) {
			if (wordDict.contains(s.substring(start, end)) && word_Break(s, wordDict, end, memo)) {
				memo[start] = 1;// memo[start] = true
				return true;
			}
		}
		memo[start] = 0;// memo[start] = false
		return false;
	}

	// 动态规划
	public boolean wordBreak(String s, List<String> wordDict) {
		HashSet<String> set = new HashSet<String>(wordDict);
		boolean[] dp = new boolean[s.length() + 1];
		dp[0] = true;
		// dp[i] [0,i)能不能用set组成
		for (int i = 1; i <= s.length(); i++) {
			boolean flag = false;
			for (int j = i - 1; j >= 0; j--) {
				if (flag) {
					break;
				}
				if (set.contains(s.substring(j, i))) {
					flag |= dp[j];
				}
			}
			dp[i] = flag;
		}
		return dp[s.length()];
	}

	// dfs(超时)
	public boolean wordBreak0(String s, List<String> wordDict) {
		if (s == null || s.length() == 0) {
			return false;
		}

		for (int i = 0; i < wordDict.size(); i++) {
			if (wordBreak(i, "", s, wordDict)) {
				return true;
			}
		}
		return false;
	}

	// [0,index]能否凑出s
	private boolean wordBreak(int index, String cur, String s, List<String> list) {
		if (cur.length() == s.length() && cur.equals(s)) {
			return true;
		}

		if (cur.length() < s.length() && !s.startsWith(cur) || cur.length() > s.length()) {
			return false;
		}
		if (index == list.size()) {
			return false;
		}
		boolean flag = false;
		for (int i = 0; i <= index; i++) {
			if (!flag) {
				flag |= wordBreak(index, cur + list.get(i), s, list);
			} else {
				return true;
			}
		}
		return flag;
	}

}
