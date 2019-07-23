package Leetcode_091_DecodeWays;

import java.util.Arrays;

/*
	一条包含字母 A-Z 的消息通过以下方式进行了编码：	
	'A' -> 1
	'B' -> 2
	...
	'Z' -> 26
	给定一个只包含数字的非空字符串，请计算解码方法的总数。
	
	示例 1:	
		输入: "12"
		输出: 2
		解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
	示例 2:	
		输入: "226"
		输出: 3
		解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/decode-ways
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//91. 解码方法
public class DecodeWays {
	public static void main(String[] args) {
		new DecodeWays().numDecodings("226");
	}

	// 递归超时
	public int numDecodings2(String s) {
		return numDecodings(s, 0);
	}

	// [index,size-1] 能不能解码成功
	private int numDecodings(String s, int index) {
		if (index == s.length()) {
			return 1;
		}
		int res = 0;
		for (int i = 1; i <= 2; i++) {
			if (index + i <= s.length()) {
				String str = s.substring(index, index + i);
				int temp = Integer.valueOf(str);
				if (!str.startsWith("0") && temp <= 26 && temp > 0) {
					res += numDecodings(s, index + i);
				}
			}
		}
		return res;
	}

	// 记忆化搜索
	int[] memo;

	public int numDecodings1(String s) {
		int length = s.length();
		memo = new int[length];
		Arrays.fill(memo, -1);
		return numDecodings1(s, 0);

	}

	// [index,size-1]
	private int numDecodings1(String s, int index) {
		if (index == s.length()) {
			return 1;
		}
		if (memo[index] != -1) {
			return memo[index];
		}
		memo[index] = 0;
		for (int i = 1; i <= 2; i++) {
			if (index + i <= s.length()) {
				String str = s.substring(index, index + i);
				int temp = Integer.valueOf(str);
				if (!str.startsWith("0") && temp <= 26 && temp > 0) {
					memo[index] += numDecodings1(s, index + i);
				}
			}
		}
		return memo[index];
	}

	// 动态规划
	public int numDecodings(String s) {
		int length = s.length();
		int[] memo = new int[length + 1];
		memo[length] = 1;
		if (s.charAt(length - 1) != '0') {
			memo[length - 1] = 1;
		}
		for (int i = length - 2; i >= 0; i--) {
			for (int j = 1; j <= 2; j++) {
				if (isValid(s, i, i + j)) {
					memo[i] += memo[i + j];
				}
			}
		}
		return memo[0];
	}

	private boolean isValid(String s, int i, int j) {
		String str = s.substring(i, j);
		int temp = Integer.valueOf(str);
		if (!str.startsWith("0") && temp <= 26 && temp > 0) {
			return true;
		}
		return false;
	}
}
