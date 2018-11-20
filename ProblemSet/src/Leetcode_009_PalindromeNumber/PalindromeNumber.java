package Leetcode_009_PalindromeNumber;

/*
	判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
	
	示例 1:	
		输入: 121
		输出: true
	
	示例 2:	
		输入: -121
		输出: false
		解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
	
	示例 3:	
		输入: 10
		输出: false
		解释: 从右向左读, 为 01 。因此它不是一个回文数。
 */
public class PalindromeNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PalindromeNumber pn = new PalindromeNumber();
		pn.isPalindrome(-121);
	}

	// 9.回文数
	public boolean isPalindrome(int x) {
		String s = x + "";
		StringBuilder sb = new StringBuilder(s);

		int res = sb.toString().compareTo(sb.reverse().toString());
		if (res == 0) {
			return true;
		} else {
			return false;
		}
	}

	// 86ms
	public boolean isPalindrome2(int x) {
		// 负数和10的倍数一定不是回文串
		if (x < 0 || (x != 0 && x % 10 == 0)) {
			return false;
		}
		int s = 0;
		while (s <= x) {
			s = s * 10 + x % 10;
			// 偶数长度会相等、奇数常务为后者
			if (s == x || s == x / 10) {
				return true;
			}
			x /= 10;
		}
		return false;
	}

}
