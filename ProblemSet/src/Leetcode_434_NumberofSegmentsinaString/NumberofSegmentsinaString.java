package Leetcode_434_NumberofSegmentsinaString;

/*
	统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
	
	请注意，你可以假定字符串里不包括任何不可打印的字符。
	
	示例:	
		输入: "Hello, my name is John"
		输出: 5
*/
public class NumberofSegmentsinaString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		NumberofSegmentsinaString nss = new NumberofSegmentsinaString();
		System.out.println(nss.countSegments("Hello, my name is John"));
	}

	// 434. 字符串中的单词数
	public int countSegments(String s) {
		if(s.equals("")||s.equals(" ")) {
			return 0;
		}else if(s.length()==1){
			return 1;
		}
		int count = 0;		
		for (int i = 1; i < s.length(); i++) {
			if ((s.charAt(i - 1) != ' ') && (s.charAt(i) == ' ')) {
				count++;
			}
			
		}
		if(s.charAt(s.length() - 1) != ' ')  {
			count++;
		}
		return count;

	}

}
