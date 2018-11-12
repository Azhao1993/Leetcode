package Leetcode_344_ReverseString;

/*
	编写一个函数，其作用是将输入的字符串反转过来。
	
	示例 1:
		输入: "hello"
		输出: "olleh"
	示例 2:
		输入: "A man, a plan, a canal: Panama"
		输出: "amanaP :lanac a ,nalp a ,nam A"
*/
public class ReverseString {
	// 344.翻转字符串
	public String reverseString(String s) {
		char[] ch = s.toCharArray();
		for (int i = 0; i < ch.length / 2; i++) {
			char temp = ch[i];
			ch[i] = ch[ch.length - 1 - i];
			ch[ch.length - 1 - i] = temp;
		}
		return String.valueOf(ch);
	}

	// 传智博客
	public static String myReverse(String s) {
		// 定义一个新字符串
		String result = "";
		// 把字符串转成字符数组
		char[] chs = s.toCharArray();
		// 倒着遍历字符串，得到每一个字符
		for (int x = chs.length - 1; x >= 0; x--) {
			// 用新字符串把每一个字符拼接起来
			result += chs[x];
		}
		return result;
	}

}
