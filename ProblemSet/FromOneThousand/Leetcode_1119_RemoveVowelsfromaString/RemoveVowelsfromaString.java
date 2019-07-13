package Leetcode_1119_RemoveVowelsfromaString;

import java.util.Arrays;
import java.util.HashSet;
/*
	给你一个字符串 S，请你删去其中的所有元音字母（ 'a'，'e'，'i'，'o'，'u'），并返回这个新字符串。 
	
	示例 1：	
		输入："leetcodeisacommunityforcoders"
		输出："ltcdscmmntyfrcdrs"
	示例 2：		
		输入："aeiou"
		输出：""
	 
	
	提示：	
	S 仅由小写英文字母组成。
	1 <= S.length <= 1000
 */
public class RemoveVowelsfromaString {
	
	//1119. 删去字符串中的元音
    public String removeVowels(String S) {
        HashSet<Character> set = new HashSet<>(Arrays.asList(new Character[] {'a','e','i','o','u'}));
        StringBuilder res = new StringBuilder();
        for(char ch :S.toCharArray()) {
        	if(!set.contains(ch)) {
        		res.append(ch);
        	}
        }
        return res.toString();
        
    }
}
