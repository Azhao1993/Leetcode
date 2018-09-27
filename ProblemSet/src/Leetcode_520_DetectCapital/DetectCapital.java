package Leetcode_520_DetectCapital;

/*
	给定一个单词，你需要判断单词的大写使用是否正确。
	
	我们定义，在以下情况时，单词的大写用法是正确的：
	
	全部字母都是大写，比如"USA"。
	单词中所有字母都不是大写，比如"leetcode"。
	如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
	否则，我们定义这个单词没有正确使用大写字母。
	
	示例 1:	
		输入: "USA"
		输出: True
	示例 2:	
		输入: "FlaG"
		输出: False
	注意: 输入是由大写和小写拉丁字母组成的非空单词。
*/
public class DetectCapital {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String s = "USA";
		DetectCapital dc = new DetectCapital();
		System.out.println(dc.detectCapitalUse(s));
	}

	
	// 520.检测大写字母
	public boolean detectCapitalUse(String word) {
		//字符串不存在或者为空字符串
		if ( word == null || word == "" )
	        return false;
	    //统计大写字母的哥说
	    int count = 0;
	    for (int i = 0; i < word.length(); i++) {
	        if (word.charAt(i) <= 'Z' && word.charAt(i) >= 'A')
	            count++;
	    }
	    //全是大写||count==1且在第一个||全是小写
	    if (count == word.length() || (count == 1 && word.charAt(0) >= 'A' && word.charAt(0) <= 'Z') || count == 0) {
	    	return true;
	    }    
	    
	    return false;
	}
//	public boolean detectCapitalUse(String word) {
//		// 将字符串存入字符数组
//		char[] w = word.toCharArray();
//		if(w.length==1) {
//			return (w[0] >= 'A') & (w[0] <= 'Z');
//		}
//		// 第一个字符是大写
//		if ((w[0] >= 'A') & (w[0] <= 'Z')) {
//			//后面全大写或者全小写
//			boolean flag = ((w[1] >= 'A') & (w[1] <= 'Z'));//第二个为ture/false后面都一样。
//			for(int i =2;i<w.length;i++) {
//				if(((w[i] >= 'A') & (w[i] <= 'Z'))!=flag) {
//					return false;
//				}
//			}
//		}else {
//			//第一个是小写
//			int i = 1;
//			while(i<w.length){
//				if((w[i] >= 'A') & (w[i] <= 'Z')) {
//					return false;
//				}
//				i++;
//			}
//		}
//		return true;

//	}

}
