package Leetcode_383_RansomNote;
/*
	给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
	判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。
	如果可以构成，返回 true ；否则返回 false。
	
	(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
	
	注意：
	
	你可以假设两个字符串均只含有小写字母。
	
	canConstruct("a", "b") -> false
	canConstruct("aa", "ab") -> false
	canConstruct("aa", "aab") -> true
*/
public class RansomNote {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		RansomNote rn = new RansomNote();
		System.out.println(rn.canConstruct("aa", "ab"));
	}
	//383. 赎金信
	public boolean canConstruct(String ransomNote, String magazine) {
		//ransomNote的构成
		if(ransomNote.length()==1) {
			if(magazine.indexOf(ransomNote)==-1) {
				return false;
			}
		}
		//字符串数组
		StringBuffer ransomNotebuffer = new StringBuffer(ransomNote);		
		//逐个判断信的构成
		for(int i=0;i<ransomNotebuffer.length()-1;i++) {
			int count = 1;
			for(int j =i+1;j<ransomNotebuffer.length();j++) {
				if(ransomNotebuffer.charAt(i)==ransomNotebuffer.charAt(j)) {
					ransomNotebuffer.deleteCharAt(j);
					count++;
				}
			}
			if(!magazineCons(magazine,ransomNote.charAt(i),count)) {
				return false;
			}			
		}
		
		return true;
	}
	public boolean magazineCons(String magazine,char ch,int count) {
		int chcount = 0;
		for(int i=0;i<magazine.length();i++ ) {
			if(magazine.charAt(i)==ch) {
				chcount++;
				if(chcount==count) {
					return true;
				}
			}
		}
		return false;
		
	}
}
