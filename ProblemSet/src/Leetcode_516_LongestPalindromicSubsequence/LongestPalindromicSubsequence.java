package Leetcode_516_LongestPalindromicSubsequence;

/*
	给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
	
	示例 1:
		输入:	
			"bbbab"
		输出:	
			4
		一个可能的最长回文子序列为 "bbbb"。
	
	示例 2:
		输入:	
			"cbbd"
		输出:	
			2
		一个可能的最长回文子序列为 "bb"。
 */

//516.最长的回文子序列
public class LongestPalindromicSubsequence {
	public static void main(String[] args) {
		String s = "bbbab";
		LongestPalindromicSubsequence lps = new LongestPalindromicSubsequence();
		lps.longestPalindromeSubseq0(s);
	}

	public int longestPalindromeSubseq(String s) {
		int n = s.length();
		int[][] dp = new int[n][n];
		for (int l = 1; l <= n; l++) {
			for (int i = 0; i <= n - l; i++) {
				int j = i + l - 1;
				if (i == j) {
					dp[i][j] = 1;
					continue;
				}
				if (s.charAt(i) == s.charAt(j)) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				} else {
					dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}

	// dp降维
	public int longestPalindromeSubseq0(String s) {
		int n = s.length();
		int[] dp0 = new int[n];// 长度为l的解，
		int[] dp1 = new int[n];// 长度为l-1的解
		int[] dp2 = new int[n];// 长度为l-2的解

		for (int l = 1; l <= n; l++) {
			for (int i = 0; i <= n - l; i++) {
				int j = i + l - 1;
				if (i == j) {
					dp0[i] = 1;// dp0[i],起始位置为i，长度为l的解
					continue;
				}
				if (s.charAt(i) == s.charAt(j)) {
					dp0[i] = dp2[i + 1] + 2;
				} else {
					dp0[i] = Math.max(dp1[i + 1], dp1[j - 1]);
				}
			}
			swap(dp2, dp1);
			swap(dp1, dp0);
		}
		return dp1[0];
	}

	private void swap(int[] dp0, int[] dp1) {
		for (int i = 0; i < dp0.length; i++) {
			int temp = dp0[i];
			dp0[i] = dp1[i];
			dp1[i] = temp;
		}
	}
}
