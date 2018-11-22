package Leetcode_345_ReverseVowelsofaString;

/*
	编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
	
	示例 1:	
		输入: "hello"
		输出: "holle"
	
	示例 2:	
		输入: "leetcode"
		输出: "leotcede"
	说明:
		元音字母不包含字母"y"。

 */
public class ReverseVowelsofaString {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		ReverseVowelsofaString rvs = new ReverseVowelsofaString();
		System.out.println(" apG0i4maAs::sA0m4i0Gp0");
		System.out.println(" ipG0A4mAas::si0m4a0Gp0");
		System.out.println(rvs.reverseVowels(" apG0i4maAs::sA0m4i0Gp0"));

	}

	// 345. 反转字符串中的元音字母
	public String reverseVowels(String s) {
		char[] charr = s.toCharArray();
		int i = 0;
		int j = charr.length - 1;
		while (j > i) {
			while ((i < charr.length) && (!isYuan(charr[i]))) {
				i++;
			}
			while ((j >= 0) && (!isYuan(charr[j]))) {
				j--;
			}
			if (i <= j) {
				char temp = charr[i];
				charr[i] = charr[j];
				charr[j] = temp;
			}

			i++;
			j--;
		}
		return new String(charr);
	}

	// 元音字母
	public boolean isYuan(char ch) {
		if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'A') || (ch == 'E')
				|| (ch == 'I') || (ch == 'O') || (ch == 'U')) {
			return true;
		} else {
			return false;
		}
	}

}
