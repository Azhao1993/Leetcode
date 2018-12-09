package Leetcode_290_WordPattern;

import java.util.HashMap;
import java.util.Map;

/*
	给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。	
	这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。
	
	示例1:	
		输入: pattern = "abba", str = "dog cat cat dog"
		输出: true
		
	示例 2:	
		输入:pattern = "abba", str = "dog cat cat fish"
		输出: false
		
	示例 3:	
		输入: pattern = "aaaa", str = "dog cat cat dog"
		输出: false
		
	示例 4:		
		输入: pattern = "abba", str = "dog dog dog dog"
		输出: false
		
	说明:
		你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 */
public class WordPattern {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String pattern = "ab";
		String str = "cat dog";
		System.out.println(new WordPattern().wordPattern(pattern, str));
	}

	// 290. 单词模式
	public boolean wordPattern(String pattern, String str) {
		String[] strArr = str.split(" ");
		if (pattern.length() != strArr.length) {
			return false;
		}
		Map<Character, String> map = new HashMap<Character, String>();
		Map<String, Character> map2 = new HashMap<String, Character>();
		for (int i = 0; i < strArr.length; i++) {
			if (map.containsKey(pattern.charAt(i))) {
				if (!map2.containsKey(strArr[i])) {
					return false;
				}
				if (!map.get(pattern.charAt(i)).equals(strArr[i]) && (map2.get(strArr[i]) != pattern.charAt(i))) {
					return false;
				}
			} else {
				if (map2.containsKey(strArr[i])) {
					return false;
				}
				map.put(pattern.charAt(i), strArr[i]);
				map2.put(strArr[i], pattern.charAt(i));
			}
		}
		return true;
	}

	// 0ms
	public boolean wordPattern0(String pattern, String str) {
		char[] pc = pattern.toCharArray();
		String[] words = str.split(" ");
		// 长度不等
		if (pc.length != words.length) {
			return false;
		}
		// 以ascii码作为下标存储String。也可以String[] mark = new String[26];只要下面mark[pc[i]-97]即可
		String[] mark = new String[123];
		for (int i = 0; i < pc.length; i++) {
			if (mark[pc[i]] == null) {
				mark[pc[i]] = words[i];
			}
			// 已有值，但与之前存储的不同，所以格式错误
			else if (!mark[pc[i]].equals(words[i])) {
				return false;
			}
		}

		// 方法2：遍历两次
		for (int i = 97; i < 122; i++) {
			for (int j = i + 1; j < 123; j++) {
				if (mark[i] != null && mark[i].equals(mark[j])) {
					return false;
				}
			}
		}

		return true;
	}
}
