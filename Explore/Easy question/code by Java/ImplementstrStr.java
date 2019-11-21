package Leetcode_028_ImplementstrStr;

/*
	实现 strStr() 函数。
	给定一个 haystack 字符串和一个 needle 字符串，
	在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
	如果不存在，则返回  -1。
	
	示例 1:
		输入: haystack = "hello", needle = "ll"
		输出: 2
	示例 2:
		输入: haystack = "aaaaa", needle = "bba"
		输出: -1
	
	说明:	
	当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。	
	对于本题而言，当 needle 是空字符串时我们应当返回 0 。
	这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/
public class ImplementstrStr {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		ImplementstrStr issS = new ImplementstrStr();
		System.out.println(issS.strStr("mississippi", "pi"));		
		
	}
	//28.实现strStr() 
	// 实现String.indexof(String str)的功能
	public int strStr(String haystack, String needle) {
		// needle为空时返回0
		if (needle.equals("")) {
			return 0;
		}
		// haystack的长度
		int hlength = haystack.length();
		// needle的长度
		int nlength = needle.length();
		if(nlength==hlength) {
			if(haystack.equals(needle)) {
				return 0;
			}
		}else if(nlength>hlength) {
			return -1;
		}
		StringBuffer haystackbuffer = new StringBuffer(haystack);
		
		for(int i =0;i<hlength-nlength+1;i++) {
			if(haystackbuffer.substring(i, i+nlength).equals(needle)) {
				return i;
			}
		}
		return -1;
	}

}
