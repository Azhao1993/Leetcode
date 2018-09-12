package Leetcode_557_ReverseWordsinaString3;
/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:
	输入: "Let's take LeetCode contest"
	输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/
public class ReverseWordsinaString3 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		
	}
	public String reverseWords(String s) {
		//分割字符串成字符数组
		String[] strarr = s.split(" ");
		//结果字符串
		String result = "";
		//逐个单词反转
		for(int i = 0;i<strarr.length;i++) {
			char[] chs = strarr[i].toCharArray();
			for(int j = 0;j<chs.length/2;j++) {
				char temp = chs[j];
				chs[j] = chs[chs.length-1-j];
				chs[chs.length-1-j] = temp;
			}
			result += String.valueOf(chs);
			if(i!=strarr.length-1) {
				result += " ";
			}
		}
		return result;
	}
	/*
	//超出内存限制 
	 
	public String reverseWords(String s) {
		String result = "";
		//整体反转，分割，反转数组，输出
		s = reverseString(s);
		String[] strarr = s.split(" ");
		for(int i =0;i<strarr.length/2;i++) {
			String temp = strarr[i];
			strarr[i] = strarr[strarr.length-1-i];
			strarr[strarr.length-1-i] = temp;			
		}
		for(int i =0;i<strarr.length;i++) {
			result += strarr[i];
			if(i!=strarr.length-1) {
				result += " ";
			}
		}
		return result;
	}
	*/
	/*
	//超时	
	public String reverseWords(String s) {
		String result = "";
		while(s.indexOf(" ")!=-1) {
			//第一次空格出现的索引
			int index = s.indexOf(" ");
			//截取两个数组,前半段str,后半段
			String str = s.substring(0, index);
			s = s.substring(index);
			//反转str
			result += reverseString(str);
			result += " ";			
		}
		result += reverseString(s);
		return result;
        
    }
    
	//字符串翻转
	public String reverseString(String s) {
        char[] ch = s.toCharArray();
        for(int i = 0;i<ch.length/2;i++) {
        	char temp = ch[i];
        	ch[i] = ch[ch.length-1-i];
        	ch[ch.length-1-i] = temp;
        }
        return String.valueOf(ch);
    }
    */

}
