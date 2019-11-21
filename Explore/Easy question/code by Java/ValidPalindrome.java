package Leetcode_125_ValidPalindrome;

/*
	给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。	
	说明：本题中，我们将空字符串定义为有效的回文串。
	
	示例 1:	
		输入: "A man, a plan, a canal: Panama"
		输出: true
	示例 2:
		输入: "race a car"
		输出: false
*/
public class ValidPalindrome {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ValidPalindrome vp = new ValidPalindrome();
		System.out.println("0P");
		System.out.println(vp.isPalindrome("0P"));
	}

	// 125. 验证回文串
	public boolean isPalindrome(String s) {
		// 空字符串返回true
		if (s.equals(" ")) {
			return true;
		}

		//
		for (int i = 0, j = s.length() - 1; (i <= j); i++, j--) {
			// 判断i是否是字母和数字
			while (!isnumorletter(s.charAt(i))) {
				i++;
				if (i == s.length()) {
					return false;
				}
			}
			while (!isnumorletter(s.charAt(j))) {
				j--;
			}
			// 判断i和j是否相等，不区分大小写
			if ((s.charAt(i) >= '0') & (s.charAt(i) <= '9')) {
				if (s.charAt(i) != s.charAt(j)) {
					return false;
				}
			} else if ((s.charAt(i) == s.charAt(j)) || (s.charAt(i) - 32 == s.charAt(j))
					|| (s.charAt(i) + 32 == s.charAt(j))) {
				continue;
			} else {
				return false;
			}
		}
		return true;
	}

	public boolean isnumorletter(char ch) {
		// 是否是数字
		if ((ch >= '0') & (ch <= '9')) {
			return true;
		} else if ((ch >= 'A') & (ch <= 'Z')) {
			// 大写字母
			return true;
		} else if ((ch >= 'a') & (ch <= 'z')) {
			// 小写字母
			return true;
		} else {
			return false;
		}

	}

}
