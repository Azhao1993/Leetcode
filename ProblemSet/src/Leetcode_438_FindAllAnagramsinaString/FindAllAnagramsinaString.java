package Leetcode_438_FindAllAnagramsinaString;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。	
	字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
	
	说明：	
		字母异位词指字母相同，但排列不同的字符串。
		不考虑答案输出的顺序。
		
	示例 1:	
		输入:
			s: "cbaebabacd" p: "abc"		
		输出:
			[0, 6]		
		解释:
			起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
			起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
	
	 示例 2:	
		输入:
		s: "abab" p: "ab"		
		输出:
		[0, 1, 2]	
	解释:
		起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
		起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
		起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
 */
public class FindAllAnagramsinaString {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String s = "abab";
		String p = "ab";
		new FindAllAnagramsinaString().findAnagrams(s, p);
	}

	// 438. 找到字符串中所有字母异位词
	public List<Integer> findAnagrams(String s, String p) {
		List<Integer> list = new ArrayList<>();
		int m = s.length();
		int n = p.length();
		if (m < n) {
			return list;
		}
		for (int i = 0; i <= m - n; i++) {
			int[] t = new int[26];
			for (int j = 0; j < n; j++) {
				t[s.charAt(i + j) - 'a']++;
				t[p.charAt(j) - 'a']--;
			}
			boolean flag = true;
			for (int j = 0; j < t.length; j++) {
				if (t[j] != 0) {
					flag = false;
					break;
				}
			}
			if (flag)
				list.add(i);
		}
		return list;
	}

	// 7ms
	public List<Integer> findAnagrams0(String s, String p) {
		List<Integer> list = new ArrayList<Integer>();
		int[] sump = new int[123];
		int[] sums = new int[123];
		char[] chs = s.toCharArray();
		char[] chp = p.toCharArray();
		int k = chp.length, end = chp.length;
		if (chs.length < end)
			return list;

		for (int i = 0; i < end; i++) {
			sump[chp[i]]++;
			sums[chs[i]]++;
		}

		while (true) {
			boolean flag = true;
			for (int j = 97; j < 123; j++) {
				if (sums[j] != sump[j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				list.add(k - end);
			if (k == chs.length)
				break;
			sums[chs[k - end]]--;
			sums[chs[k]]++;
			k++;
		}
		return list;
	}

	// 超时
	private Map<Character, Integer> mapP;

	public List<Integer> findAnagrams2(String s, String p) {
		
		List<Integer> list = new ArrayList<Integer>();
		if(s.length()<p.length()){
			return list;
		}
		// p的map
		mapP = stringtoMap(p);
		for (int i = 0; i <= s.length() - p.length(); i++) {
			Map<Character, Integer> mapTemp = stringtoMap(s.substring(i, i + p.length()));
			if (equalsToMapP(mapTemp)) {
				list.add(i);
			}
		}
		return list;

	}

	// String to Map
	public Map<Character, Integer> stringtoMap(String str) {
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		for (int i = 0; i < str.length(); i++) {
			map.put(str.charAt(i), map.getOrDefault(str.charAt(i), 0) + 1);
		}
		return map;
	}

	// mapTemp 是否等于mapP
	public boolean equalsToMapP(Map<Character, Integer> mapTemp) {
		for (Character ch : mapP.keySet()) {
			if (mapTemp.containsKey(ch) && (mapTemp.get(ch) == mapP.get(ch))) {
				continue;
			} else {
				return false;
			}
		}
		return true;
	}
}
