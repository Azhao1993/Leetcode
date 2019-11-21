package Leetcode_451_SortCharactersByFrequency;

import java.util.HashMap;
import java.util.Map;

/*
	给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
	
	示例 1:
		输入:
			"tree"
		输出:
			"eert"	
	解释:
		'e'出现两次，'r'和't'都只出现一次。
		因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
		
	示例 2:
		输入:
			"cccaaa"
		输出:
			"cccaaa"
	解释:
		'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
		注意"cacaca"是不正确的，因为相同的字母必须放在一起。
		
	示例 3:
		输入:
			"Aabb"
		
		输出:
			"bbAa"
	解释:
		此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
		注意'A'和'a'被认为是两种不同的字符。
*/
public class SortCharactersByFrequency {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SortCharactersByFrequency scby = new SortCharactersByFrequency();
		System.out.println(scby.frequencySort("eeeee"));
	}

	// 451. 根据字符出现频率排序
	public String frequencySort(String s) {
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		for (int i = 0; i < s.length(); i++) {
			char cur = s.charAt(i);
			map.put(cur, map.getOrDefault(cur, 0) + 1);

		}
		StringBuilder sb = new StringBuilder();
		for (int i = s.length(); i >= 1; i--) {
			for (Character ch : map.keySet()) {
				if (map.get(ch) == i) {
					for (int j = 0; j < i; j++) {
						sb.append(ch);
					}
				}
			}
		}
		return sb.toString();
	}

	public String frequencySort2(String s) {
		// 创建字符串缓冲区
		StringBuffer buffer = new StringBuffer(s);// tree
		StringBuffer result = new StringBuffer();
		// 删除重复字符
		for (int i = 0; i < buffer.length() - 1; i++) {
			for (int j = i + 1; j < buffer.length();) {
				if (buffer.charAt(i) == buffer.charAt(j)) {
					buffer.deleteCharAt(j);
				} else {
					j++;
				}
			}
		}
		if (buffer.length() == 1) {
			return s;
		}
		// 统计字符的频率 tre
		int[] requency = new int[buffer.length()];// 112
		for (int i = 0; i < buffer.length(); i++) {
			for (int j = 0; j < s.length(); j++) {
				if (buffer.charAt(i) == s.charAt(j)) {
					requency[i]++;
				}
			}
		}

		// 根据频率排序
		char[] bufferchar = buffer.toString().toCharArray();
		for (int i = 0; i < requency.length - 1; i++) {
			for (int j = i + 1; j < requency.length; j++) {
				if (requency[i] < requency[j]) {
					int temp = requency[i];
					char tempchar = bufferchar[i];
					requency[i] = requency[j];
					bufferchar[i] = bufferchar[j];
					requency[j] = temp;
					bufferchar[j] = tempchar;
				}
			}
			for (int m = 0; m < requency[i]; m++) {
				result.append(bufferchar[i]);
			}
			// 最后一个字母
			if (i == requency.length - 2) {
				for (int m = 0; m < requency[requency.length - 1]; m++) {
					result.append(bufferchar[requency.length - 1]);
				}
			}

		}

		return result.toString();

	}

}
