package Leetcode_680_ValidPalindrome2;
/*
	给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
	
	示例 1:		
		输入: "aba"
		输出: True
	示例 2:	
		输入: "abca"
		输出: True
	解释: 你可以删除c字符。
	注意:	
		字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
*/
public class ValidPalindrome2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ValidPalindrome2 vp2 = new ValidPalindrome2();
		String s = "abc";
		System.out.println(vp2.validPalindrome(s));
		
	}
	//680. 验证回文字符串 Ⅱ
    public boolean validPalindrome(String s) {
    	//创建字符串缓存区
    	StringBuilder builder = new StringBuilder(s);
    	if(s.equals(builder.reverse().toString())) {
    		return true;
    	}
    	int begindex = 0;
    	while(builder.length()!=0) {    		
        	int endindex = builder.length()-1;
        	if(builder.charAt(endindex)==builder.charAt(begindex)) {
        		builder.deleteCharAt(0);
        		builder.deleteCharAt(builder.length()-1);
        	}else {
        		char temp = builder.charAt(0);
        		String s1 = builder.deleteCharAt(0).toString();
        		if(s1.equals(builder.reverse().toString())) {
        			return true;
        		}else {        			
        			String s2 =builder.append(temp).deleteCharAt(0).toString();
        			return s2.equals(builder.reverse().toString());
        		}       		
        		
        	}    		
    	}
    	return true;
    	
    }
    
}


