package Leetcode_020_ValidParentheses;

import java.util.HashMap;

/*
	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
	
	有效字符串需满足：	
		左括号必须用相同类型的右括号闭合。//和为0
		左括号必须以正确的顺序闭合。
		注意空字符串可被认为是有效字符串。
	
	示例 1:	
		输入: "()"
		输出: true
	示例 2:	
		输入: "()[]{}"
		输出: true
	示例 3:	
		输入: "(]"
		输出: false
	示例 4:	
		输入: "([)]"
		输出: false
	示例 5:	
		输入: "{[]}"
		输出: true
*/
public class ValidParentheses {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		ValidParentheses vp = new ValidParentheses();
		System.out.println(vp.isValid(""));
	}
	//20. 有效的括号
    public boolean isValid(String s) {
    	//空字符串
    	if(s.equals("")) {
    		return true;
    	}
    	//奇数长度
    	if(s.length()%2==1) {
    		return false;
    	}
        //HashMap
    	HashMap<Character,Integer> map =new HashMap();
    	map.put('(', -1);
    	map.put(')', 1);
    	map.put('[', -2);
    	map.put(']', 2);
    	map.put('{', -3);
    	map.put('}', 3);
    	//字符串缓冲区
    	StringBuilder builder = new StringBuilder(s);
    	if(map.get(builder.charAt(0))>0) {
    		return false;
    	}
    	//删除相邻的括号
    	int[] flag= {0,1};
    	while(flag[0]!=flag[1]) {
    		flag[0] = builder.length();
    		for(int i =1;i<builder.length();i++) {
        		if(map.get(builder.charAt(i))+map.get(builder.charAt(i-1))==0){
        			builder.delete(i-1, i+1);
        		}
        	}
    		flag[1] = builder.length();
    	}
    	if(builder.length()!=0) {
    		return false;
    	}
    	return true;
    	
    }

}
