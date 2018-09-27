package Leetcode_859_BuddyStrings;

import java.util.HashSet;
import java.util.Set;

/*
给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。
示例 1：
	输入： A = "ab", B = "ba"
	输出： true
示例 2：
	输入： A = "ab", B = "ab"
	输出： false
示例 3:
	输入： A = "aa", B = "aa"
	输出： true
示例 4：
	输入： A = "aaaaaaabc", B = "aaaaaaacb"
	输出： true
示例 5：
	输入： A = "", B = "aa"
	输出： false
提示：
	0 <= A.length <= 20000
	0 <= B.length <= 20000
	A 和 B 仅由小写字母构成。
*/
public class BuddyStrings {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BuddyStrings bs = new BuddyStrings();
		System.out.println(bs.buddyStrings("aaaaaaabc","aaaaaaacb"));
		
	}
	//859. 亲密字符串
	 public boolean buddyStrings(String A, String B) {
		 //其中一个为空
		 if((A.length()==0)||(B.length()==0)) {
			 return false;
		 }
		 //A,B长度不相等
		 if(A.length()!=B.length()) {
			 return false;
		 }
		 //A,B内容相同
		 if(A.equals(B)) {
			 //判断字符是否重复
			 Set<Character> set = new HashSet<Character>();
			 for(int i = 0;i<A.length();i++) {
				 set.add(A.charAt(i));
			 }
			 //set的大小和A的长度相同，说明无重复
			 if(set.size()==A.length()) {
				 return false;
			 }
			 return true;
		 }
		 //内容不同
		 //计数器
		 int count = 0;
		 Set<Character> seta = new HashSet<Character>();
		 Set<Character> setb = new HashSet<Character>();
		 for(int i = 0;i<A.length();i++) {
			 if(A.charAt(i)!=B.charAt(i)) {
				 count++;
				 seta.add(A.charAt(i));
				 setb.add(B.charAt(i));
			 }
			 if(count>2) {
				 return false;
			 }
		 }
		 //判断seta和setb是否相同
		 if((count==2)&(seta.equals(setb))) {
			 return true;
		 }
		 return false;
	 }

}
