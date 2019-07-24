package Leetcode_474_OnesandZeroes;

import java.util.Arrays;
import java.util.Comparator;

/*
	在计算机界中，我们总是追求用有限的资源获取最大的收益。	
	现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。	
	你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
	
	注意:	
		给定 0 和 1 的数量都不会超过 100。
		给定字符串数组的长度不会超过 600。
	示例 1:	
		输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
		输出: 4	
		解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
	示例 2:	
		输入: Array = {"10", "0", "1"}, m = 1, n = 1
		输出: 2	
		解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/ones-and-zeroes
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//474. 一和零
public class OnesandZeroes {

	// DFS
	public int findMaxForm2(String[] strs, int m, int n) {
		if (strs == null || strs.length == 0 || m == 0 && n == 0) {
			return 0;
		}
		Arrays.sort(strs, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return o1.length() - o2.length();
			}
		});

		return findMaxForm(0, m, n, strs);

	}

	// 剩下m个0,n个1 能在[start,length)最多凑出多少个
	private int findMaxForm(int start, int m, int n, String[] strs) {
		if (m == 0 && n == 0) {
			return 0;
		}
		int res = 0;
		for (int i = start; i < strs.length; i++) {
			int[] oandz = getCount(i, strs);
			int restm = m - oandz[0];
			int restn = n - oandz[1];
			if (restm >= 0 && restn >= 0) {
				res = Math.max(findMaxForm(i + 1, restm, restn, strs) + 1, res);
			}
		}
		return res;

	}

	private int[] getCount(int i, String[] strs) {
		int[] res = new int[2];
		for (char c : strs[i].toCharArray()) {
			if (c == '0') {
				res[0]++;
			} else {
				res[1]++;
			}
		}
		return res;
	}

	public static void main(String[] args) {
		String[] strs = { "10", "0001", "111001", "1", "0" };
		System.out.println(new OnesandZeroes().findMaxForm1(strs, 5, 4));
	}

	// 记忆化搜索
	public int findMaxForm1(String[] strs, int m, int n) {
		if (strs == null || strs.length == 0 || m == 0 && n == 0) {
			return 0;
		}
		Arrays.sort(strs, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return o1.length() - o2.length();
			}
		});
		int[][] memo = new int[m + 1][n + 1];
		for (int[] me : memo) {
			Arrays.fill(me, -1);
		}
		memo[0][0] = 0;
		return findMaxForm(0, m, n, strs, memo);

	}

	// 剩下m个0,n个1 [start,length）能最多凑出多少个
	private int findMaxForm(int start, int m, int n, String[] strs, int[][] memo) {
		if (m == 0 && n == 0) {
			return 0;
		}
		if (memo[m][n] != -1) {
			return memo[m][n];
		}
		int res = 0;
		for (int i = start; i < strs.length; i++) {
			int[] oandz = getCount(i, strs);
			int restm = m - oandz[0];
			int restn = n - oandz[1];
			if (restm >= 0 && restn >= 0) {
				res = Math.max(findMaxForm(i + 1, restm, restn, strs, memo) + 1, res);
			}
		}
		memo[m][n] = res;
		return res;
	}

	// 动态规划
	public int findMaxForm(String[] strs, int m, int n) {
		if (strs == null || strs.length == 0 || m <= 0 && n <= 0) {
			return 0;
		}

		int[][] dp = new int[m + 1][n + 1];
		// dp[i][j] 剩 下的i个0，j个1 能最多在[s,length)中凑出多个字符串
		for (int k = strs.length - 1; k >= 0; k--) {
			int[] zando = getCount(k, strs);
			for (int i = 0; i <= m - zando[0]; i++) {
				for (int j = 0; j <= n - zando[1]; j++) {
					dp[i][j] = Math.max(dp[i][j], dp[i + zando[0]][j + zando[1]] + 1);
				}
			}
		}
		return dp[0][0];
	}
}
