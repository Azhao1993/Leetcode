package Leetcode_205_IsomorphicStrings;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
	给定两个字符串 s 和 t，判断它们是否是同构的。	
	如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
	
	所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
	
	示例 1:	
		输入: s = "egg", t = "add"
		输出: true
	示例 2:	
		输入: s = "foo", t = "bar"
		输出: false
	示例 3:	
		输入: s = "paper", t = "title"
		输出: true
	说明:
		你可以假设 s 和 t 具有相同的长度。
 */
public class IsomorphicStrings {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "ab";
		String t = "aa";
		IsomorphicStrings is = new IsomorphicStrings();
		is.isIsomorphic(s, t);
	}

	// 205. 同构字符串
	public boolean isIsomorphic(String s, String t) {
		Map<Character, Character> map = new HashMap<Character, Character>();
		for (int i = 0; i < s.length(); i++) {
			char chars = s.charAt(i);
			char chart = t.charAt(i);
			// 是否包含key,key-value是否对应
			if (map.containsKey(chars)) {
				if (map.get(chars) != chart) {
					return false;
				}
				// 是否包含value
			} else if (map.containsValue(chart)) {
				// 包含value,但不包含key,返回fasle
				if (!map.containsKey(chars)) {
					return false;
				}
				// 不包含key也不包含value
			} else {
				map.put(chars, chart);
			}

		}
		return true;
	}

	// 1ms
	public boolean isIsomorphic1(String s, String t) {
		if (s == null || t == null || s.length() != t.length()) {
			return false;
		}
		char[] chas1 = s.toCharArray();
		char[] chas2 = t.toCharArray();
		int[] map = new int[512];
		for (int i = s.length() - 1; i >= 0; i--) { // 把一个映射的两个下标都填上同一个数，也防止了多射的问题
			if (map[chas1[i]] != map[chas2[i] + 256]) {
				return false;
			}
			map[chas1[i]] = map[chas2[i] + 256] = i;
		}
		return true;
	}
}
