package Leetcode_014_LongestCommonPrefix;
/*
	编写一个函数来查找字符串数组中的最长公共前缀。
	
	如果不存在公共前缀，返回空字符串 ""。
	
	示例 1:		
		输入: ["flower","flow","flight"]
		输出: "fl"
	示例 2:	
		输入: ["dog","racecar","car"]
		输出: ""
	解释: 输入不存在公共前缀。
	说明:	
		所有输入只包含小写字母 a-z 。
*/
public class LongestCommonPrefix {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String[] strs= {"babb","caa"};
		LongestCommonPrefix lcp = new LongestCommonPrefix();
		System.out.println(lcp.longestCommonPrefix(strs));
	}
	//14. 最长公共前缀
    public String longestCommonPrefix(String[] strs) {
    	if(strs.length==0) {
    		return "";
    	}else if(strs.length==1) {
    		return strs[0];
    	}
    	//找出最短的单词
        int minlength = strs[0].length();//最短单词的长度
        int minindex = 0;//最短单词的位置
        for(int i =1;i<strs.length;i++) {
        	if(minlength>strs[i].length()) {
        		minlength = strs[i].length();
        		minindex = i;
        	}
        }
        
        //从最短单词开始比较 	
        StringBuilder minbuffer = new StringBuilder(strs[minindex]);
        //遍历所有单词
        for(int i = 0;i<strs.length;i++) {           
            int length = minbuffer.length();
            //被删完，就返回
            if(length==0) {
            	return minbuffer.toString();
            }
            //判断strs[i]是否以minbuffer开头
        	if(strs[i].startsWith(minbuffer.toString())) {
        		//继续
        		continue;
        	}else {
        		//否则，删除minbuffer的最后一个字符
        		minbuffer.deleteCharAt(minbuffer.length()-1);
        		i=-1;
        		continue;
        	}
        	
        }
        
        return minbuffer.toString();
        
        
    }

}
