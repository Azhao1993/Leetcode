package Leetcode_1071_GreatestCommonDivisorofStrings;

/*
	对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
	返回字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。 
	
	示例 1：
		输入：str1 = "ABCABC", str2 = "ABC"
		输出："ABC"
	示例 2：
		输入：str1 = "ABABAB", str2 = "ABAB"
		输出："AB"
	示例 3：
		输入：str1 = "LEET", str2 = "CODE"
		输出：""
	提示：
		1 <= str1.length <= 1000
		1 <= str2.length <= 1000
		str1[i] 和 str2[i] 为大写英文字母 

 */

//1071.字符串的最大公因子
public class GreatestCommonDivisorofStrings {
	public static void main(String[] args) {
		String str1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		String str2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		String out = new GreatestCommonDivisorofStrings().gcdOfStrings(str1, str2);
		System.out.println(out);
		System.out.println("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
		System.out.println(out.length());

	}

	public String gcdOfStrings0(String str1, String str2) {
		int length1 = str1.length();
		int length2 = str2.length();
		int length3 = gcd(length1, length2);
		String str3 = str1.substring(0, length3);
		if (isMatch(str1, str3) && (isMatch(str2, str3))) {
			return str3;
		} else {
			return "";
		}
	}

	/**
	 * 求最大公约数，辗转相除法
	 * 
	 * @param a
	 * @param b
	 * @return
	 */
	private int gcd(int a, int b) {
		int rem = 0;
		while (b != 0) {
			rem = a % b;
			a = b;
			b = rem;
		}
		return a;
	}

	private boolean isMatch(String s1, String s2) {
		for (int i = 0; i < s1.length(); i++) {
			if (s1.charAt(i) != s2.charAt(i % s2.length())) {
				return false;
			}
		}
		return true;
	}

//----------------------------改进答案---------------------------------------	

	public String gcdOfStrings(String str1, String str2) {
		int length1 = str1.length();
		int length2 = str2.length();
		int minlength = Math.min(length1, length2);
		for (int i = 0; i < minlength; i++) {
			if (str1.charAt(i) != str2.charAt(i)) {
				return "";
			}
		}
		while (minlength > 0) {
			String t = str2.substring(0, minlength);
			if (length1 % minlength == 0 && length2 % minlength == 0 && isMatch(str1, t) && isMatch(str2, t)) {
				return t;
			}
			minlength--;
		}
		return "";

	}

//-----------------------------原始答案--------------------------------------	
	public String gcdOfStrings2(String str1, String str2) {
		int length1 = str1.length();
		int length2 = str2.length();
		int minlength = Math.min(length1, length2);
		for (int i = 0; i < minlength; i++) {
			if (str1.charAt(i) != str2.charAt(i)) {
				return "";
			}
		}
		while (minlength > 0) {
			String t = str2.substring(0, minlength);
			if (length1 % minlength == 0 && length2 % minlength == 0 && sloution(length1 / minlength, str1, t)
					&& sloution(length2 / minlength, str2, t)) {
				return t;
			}
			minlength--;
		}
		return "";

	}

	private boolean sloution(int time, String str1, String str2) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < time; i++) {
			sb.append(str2);
		}
		return sb.toString().equals(str1);
	}

}
