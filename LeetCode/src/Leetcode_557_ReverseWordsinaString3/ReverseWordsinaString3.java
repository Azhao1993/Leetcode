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
		ReverseWordsinaString3 rws = new ReverseWordsinaString3();
		String s = "Let's take LeetCode contest";
		
		System.out.println("Let's take LeetCode contest");
		System.out.println(rws.reverseWords(s));
		
	}

	// 557.翻转单词
	public String reverseWords(String s) {
		StringBuilder builder = new StringBuilder(s);
		StringBuilder result = new StringBuilder();
		StringBuilder temp = new StringBuilder();
		//找出第一个空格	
		int index;
		while((index =builder.indexOf(" "))!=-1) {
			//System.out.println(index);
			//截取第一个单词,添加到temp字符串缓冲区，翻转添加到result中
			result.append(temp.append(builder.subSequence(0, index)).reverse()).append(" ");
			//清空temp;
			temp.delete(0, temp.length());
			//删除第一个单词
			builder.delete(0, index+1);			
		}
		//最后一个单词
		result.append(builder.reverse());
		return result.toString();
		
	}
	

}
