package Leetcode_205_IsomorphicStrings;

import java.util.Arrays;
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

	public boolean isIsomorphic2(String s, String t) {
		char[] sc = s.toCharArray();
		char[] tc = t.toCharArray();
		HashMap<Character, Character> map = new HashMap<>();// 映射关系
		HashSet<Character> set = new HashSet<>();// 保证同一个字符不被映射两次
		for (int i = 0; i < sc.length; i++) {
			if (!map.containsKey(sc[i])) {
				if (set.contains(tc[i])) {
					return false;
				}
				map.put(sc[i], tc[i]);
				set.add(tc[i]);
			} else if (map.get(sc[i]) != tc[i]) {
				return false;
			}
		}
		return true;
	}

	// 字符串的构成包含数字和字母
	// 两个字符不能映射到同一个字符但s->t t->x可以
	// 字符可以映射到本身
	public boolean isIsomorphic3(String s, String t) {
		char[] sc = s.toCharArray();
		char[] tc = t.toCharArray();
		int[] ascii = new int[512];
		for (int i = sc.length - 1; i >= 0; i--) {
			// 把一个映射的两个下标都填上同一个数，防止多次映射
			if (ascii[sc[i]] != ascii[tc[i] + 256]) {
				return false;
			}
			ascii[sc[i]] = ascii[tc[i] + 256] = i;
		}
		return true;
	}
}
