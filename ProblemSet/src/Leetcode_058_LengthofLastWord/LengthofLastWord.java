package Leetcode_058_LengthofLastWord;
/*
	给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
	
	如果不存在最后一个单词，请返回 0 。
	
	说明：一个单词是指由字母组成，但不包含任何空格的字符串。
	
	示例:	
		输入: "Hello World"
		输出: 5
*/
public class LengthofLastWord {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = " ";
		System.out.println(new LengthofLastWord().lengthOfLastWord(s));
		//" "5 length=11 11-1-5=5
	}
	//58. 最后一个单词的长度
    public int lengthOfLastWord(String s) { 
    	if(s.length()==0) {    		
     		return 0;
     	}
    	//创建字符串空间
    	StringBuilder  builder =  new StringBuilder(s);
    	//最后一个单词的长度
    	int length = 0;
    	//最后一个" "的索引
    	int lastspace = builder.lastIndexOf(" ");
    	//如果最后一个是" "则删除
    	while(lastspace==builder.length()-1) {
    		builder.deleteCharAt(builder.length()-1);
    		if(builder.length()==0) {    		
         		return 0;
    		}
    		lastspace = builder.lastIndexOf(" ");
    	}
    	//存在最后一个单词
     	length = builder.length()-1-lastspace;
     	  
        return length;
    }

}
