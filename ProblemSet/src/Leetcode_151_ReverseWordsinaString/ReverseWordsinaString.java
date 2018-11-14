package Leetcode_151_ReverseWordsinaString;

/*
	给定一个字符串，逐个翻转字符串中的每个单词。
	
	示例:  	
		输入: "the sky is blue",
		输出: "blue is sky the".
	说明:	
		无空格字符构成一个单词。
		输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
		如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
	进阶: 
		请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
 */
public class ReverseWordsinaString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ReverseWordsinaString rws = new ReverseWordsinaString();
		String s = " ";		
		System.out.println(rws.reverseWords(s));
	}

	// 151. 翻转字符串里的单词
	public String reverseWords(String s) {
		if((s==null)||(s.length()==0)) {
			return s;
		}
        StringBuilder sb = new StringBuilder(s);        
        StringBuilder result = new StringBuilder();
        //删除首尾的空格
        while((sb.length()>0)&&(sb.charAt(0)==' ')) {
        	sb.deleteCharAt(0);
        }
        while((sb.length()>0)&&(sb.charAt(sb.length()-1)==' ')){
        	sb.deleteCharAt(sb.length()-1);
        }
        if((sb.length()==0)&&(sb.indexOf(" ")==-1)){
    		return "";
    	}
        while(sb.length()>0) {
        	//获取空格的位置
        	int index = sb.lastIndexOf(" ");
        	//存在空格且不在最后
        	if((index!=-1)&&(index!=sb.length()-1)) {
        		result.append(sb.substring(index+1, sb.length()));
        		sb.delete(index, sb.length());
        		if(sb.length()!=0) {
        			result.append(" ");
        		}        		
        		
        	}else if(index==sb.length()-1) {
        		sb.deleteCharAt(index);
        	}else {
        		result.append(sb.toString());
        		break;
        	}
        }
        
        return result.toString();
        
    }

}
