package Leetcode_389_FindtheDifference;

/*
	给定两个字符串 s 和 t，它们只包含小写字母。	
	字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。	
	请找出在 t 中被添加的字母。
	
	 
	
	示例:	
		输入：
			s = "abcd"
			t = "abcde"		
		输出：
			e		
		解释：
			'e' 是那个被添加的字母。
 */
public class FindtheDifference {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FindtheDifference fd = new FindtheDifference();

		System.out.println(fd.findTheDifference("abcd", "abcde"));

	}

	// 389. 找不同
	public char findTheDifference(String s, String t) {
		char temp = 0x00;
		for (int i = 1; i < s.length(); i++) {
			temp = (char) (temp ^ s.charAt(i));
		}
		for (int i = 0; i < t.length(); i++) {
			temp = (char) (temp ^ t.charAt(i));
		}
		return temp;
	}

}
