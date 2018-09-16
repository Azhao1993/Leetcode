package Leetcode_859_BuddyStrings;
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
		 if(A.length()!=B.length()){
			return false; 
		 }
		
		 StringBuilder abulider = new StringBuilder(A);
		 StringBuilder bbulider = new StringBuilder(B);
		 if(abulider.length()==2) {
			 abulider.reverse();
			 if(abulider.reverse().indexOf(B)!=-1) {
				 return true;
			 }else {
				 return false;
			 }
		 }
		 //删除相同位置的字符
		 for(int i = 0;i<abulider.length();) {
			 if(abulider.charAt(i)==bbulider.charAt(i)) {
				 abulider.deleteCharAt(i);
				 bbulider.deleteCharAt(i);				 
			 }else {
				 i++;
			 }
		 }
		 //判断长度是否为2
		 if(abulider.length()!=2) {
			 return false;
		 }
		 if(abulider.reverse().indexOf(B)==-1) {
			 return false;
		 }
		 return true;
	 }

}
