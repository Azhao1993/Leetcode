package Leetcode_043_MultiplyStrings;

/*
	给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
	
	示例 1:	
		输入: num1 = "2", num2 = "3"
		输出: "6"
	示例 2:	
		输入: num1 = "123", num2 = "456"
		输出: "56088"
	说明：	
		num1 和 num2 的长度小于110。
		num1 和 num2 只包含数字 0-9。
		num1 和 num2 均不以零开头，除非是数字 0 本身。
		不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 */

//43.字符串相乘
public class MultiplyStrings {
	public static void main(String[] args) {
		String num1 = "1234";
		String num2 = "0";
		MultiplyStrings ms = new MultiplyStrings();
		ms.multiply(num1, num2);
	}

	public String multiply(String num1, String num2) {
		char[] n1 = num1.toCharArray();
		char[] n2 = num2.toCharArray();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n1.length; i++) {
			int flag = 0;
			for (int j = 0; j < n2.length; j++) {
				int result = (n1[n1.length - 1 - i] - '0') * (n2[n2.length - 1 - j] - '0') + flag;// 18

				if (i + j >= sb.length()) {
					sb.append(result % 10);
					flag = result / 10;
				} else {
					result += (sb.charAt(i + j) - '0');
					sb.replace(i + j, i + j + 1, String.valueOf(result % 10));
					flag = result / 10;
				}
			}
			if (flag != 0) {
				sb.append(flag);
			}
		}

		while (sb.toString().endsWith("0") && sb.length() > 1) {
			sb.deleteCharAt(sb.length() - 1);
		}
		return sb.reverse().toString();

	}

	// 11ms
	public String multiply0(String num1, String num2) {
		if (num1.isEmpty() || num2.isEmpty() || (num1.length() == 1 && num1.charAt(0) == '0')
				|| (num2.length() == 1 && num2.charAt(0) == '0'))
			return "0";
		int len1 = num1.length();
		int len2 = num2.length();
		int[] ans = new int[len1 + len2 + 1];
		for (int i = 0; i < len1; i++) {
			int a = num1.charAt(i) - '0';
			for (int j = 0; j < len2; j++) {
				int b = num2.charAt(j) - '0';
				ans[len1 + len2 - i - j - 2] += a * b;
			}
		}
		StringBuffer res = new StringBuffer();
		for (int i = 0; i < len1 + len2; i++) {
			res.append(ans[i] % 10);
			ans[i + 1] += ans[i] / 10;
		}
		String result = res.reverse().toString();
		if (result.startsWith("0"))
			result = result.substring(1, len1 + len2);
		return result;
	}
}
