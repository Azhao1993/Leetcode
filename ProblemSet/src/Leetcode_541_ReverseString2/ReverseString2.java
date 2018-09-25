package Leetcode_541_ReverseString2;
/*
	给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。
	如果剩余少于 k 个字符，则将剩余的所有全部反转。
	如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
	
	示例:
		输入: s = "abcdefg", k = 2
		输出: "bacdfeg"
	要求:
		该字符串只包含小写的英文字母。
		给定字符串的长度和 k 在[1, 10000]范围内。
*/
public class ReverseString2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	public String reverseStr(String s, int k) {
		//创建字符串数组，长度为s.lengrh/2*k+1
		String result = "";
		int strcount = s.length()/(2*k)+1;
		String[] str = new String[strcount];
		
		
		for(int i = 0;i<strcount;i++) {
			if(i!=strcount-1) {
				str[i] = s.substring(2*i*k, 2*(i+1)*k);
				//System.out.println(str[i]);
				result+=reverseString(str[i],k);				
			}else {
				str[i] = s.substring(2*i*k);
				//System.out.println(str[i]);
				
				if(str[i].length()<=k) {
					result+=reverseString(str[i],str[i].length());					
				}else {
					result+=reverseString(str[i],k);
				}
				
			}			
		}
		
		return result;
	}

	// 翻转2k个字符中前k个
	public String reverseString(String s, int k) {
		char[] ch = s.toCharArray();
		for (int i = 0; i < k / 2; i++) {
			char temp = ch[i];
			ch[i] = ch[k - 1 - i];
			ch[k - 1 - i] = temp;
		}
		return String.valueOf(ch);
	}

}
