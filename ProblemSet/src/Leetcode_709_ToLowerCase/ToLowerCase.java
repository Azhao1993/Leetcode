package Leetcode_709_ToLowerCase;

/*
 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
	示例 1：
		输入: "Hello"
		输出: "hello"
	示例 2：
		输入: "here"
		输出: "here"
	示例 3：
		输入: "LOVELY"
		输出: "lovely"
 
*/
public class ToLowerCase {

	public String toLowerCase(String str) {
		char[] ch = new char[str.length()];
		ch = str.toCharArray();
		for (int i = 0; i < str.length(); i++) {
			if (ch[i] >= 'A' & ch[i] <= 'Z') {
				ch[i] += 32;
			}			
		}
		return String.valueOf(ch);
	}

}
