package Leetcode_1048_LongestStringChain;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	给出一个单词列表，其中每个单词都由小写英文字母组成。
	
	如果我们可以在 word1 的任何地方添加一个字母使其变成 word2，
	那么我们认为 word1 是 word2 的前身。例如，"abc" 是 "abac" 的前身。
	
	词链是单词 [word_1, word_2, ..., word_k] 组成的序列，
	k >= 1，其中 word_1 是 word_2 的前身，word_2 是 word_3 的前身，依此类推。
	
	从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。 
	
	示例：	
		输入：["a","b","ba","bca","bda","bdca"]
		输出：4
		解释：最长单词链之一为 "a","ba","bda","bdca"。
	
	提示：	
		1 <= words.length <= 1000
		1 <= words[i].length <= 16
		words[i] 仅由小写英文字母组成。
 */

//1048. Longest String Chain
public class LongestStringChain {
	public static void main(String[] args) {
		System.out.println(new LongestStringChain().isPre("a", "ba"));
	}
    public int longestStrChain(String[] words) {
        Arrays.sort(words,new Comparator<String>() {
        	@Override
        	public int compare(String o1, String o2) {
        		// TODO 自动生成的方法存根
        		return o1.length()-o2.length();
        	}
        });
        Map<String,List<String>> map = new HashMap<>();
        for(int i = 0;i<words.length;i++) {
        	String str = words[i];
        	if(!map.containsKey(str)) {
        		List<String> list = new ArrayList<>();
        		map.put(str, list);        		
        	}
        	for(int j = i+1;j<words.length;j++) {
        		if(isPre(str,words[j])) {
        			map.get(str).add(words[j]);        			
        		}
        	}
        }
        int res = Integer.MIN_VALUE;
        
        return -1;
        
    }
    //判断是否是前身

	private boolean isPre(String str, String str2) {
		int i = 0;
		int j = 0;
		while(i<str.length()) {
			if(j==str2.length()) {
				return false;
			}
			char ch1 = str.charAt(i);
			char ch2 = str2.charAt(j);
			if(ch1==ch2) {
				i++;
				j++;
			}else {
				j++;
			}			
		}
		return true;
		
	}
    
}

