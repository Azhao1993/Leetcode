package Leetcode_748_ShortestCompletingWord;

import java.util.HashMap;
import java.util.Map;

/*
	如果单词列表（words）中的一个单词包含牌照（licensePlate）中所有的字母，那么我们称之为完整词。
	在所有完整词中，最短的单词我们称之为最短完整词。	
	单词在匹配牌照中的字母时不区分大小写，比如牌照中的 "P" 依然可以匹配单词中的 "p" 字母。	
	我们保证一定存在一个最短完整词。当有多个单词都符合最短完整词的匹配条件时取单词列表中最靠前的一个。	
	牌照中可能包含多个相同的字符，比如说：对于牌照 "PP"，单词 "pair" 无法匹配，但是 "supper" 可以匹配。
	
	 
	
	示例 1：	
		输入：
			licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
		输出：
			"steps"
		说明：
			最短完整词应该包括 "s"、"p"、"s" 以及 "t"。
			对于 "step" 它只包含一个 "s" 所以它不符合条件。
			同时在匹配过程中我们忽略牌照中的大小写。
	 
	
	示例 2：	
		输入：
			licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
		输出：
			"pest"
		说明：
			有三个单词都符合完整词的定义，但是我们返回最先出现的单词。
	 
	
	注意:
	
	牌照（licensePlate）的长度在区域[1, 7]中。
	牌照（licensePlate）将会包含数字、空格、或者字母（大写和小写）。
	单词列表（words）长度在区间 [10, 1000] 中。
	每一个单词 words[i] 都是小写，并且长度在区间 [1, 15] 中。
 */
public class ShortestCompletingWord {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		ShortestCompletingWord scw = new ShortestCompletingWord();
		// String licensePlate = "1s3 PSt";
		String licensePlate = "1s3 456";
		// ["looks", "pest", "stew", "show"]
		String[] words = { "looks", "pest", "stew", "show" };
		// String[] words = { "step", "steps", "stripe", "stepple" };
		// "GrC8950"
		// String[] words = { "according", "level", "meeting", "none", "marriage",
		// "rest" };
		// ["measure","other","every","base","according","level","meeting","none","marriage","rest"]
		scw.shortestCompletingWord(licensePlate, words);
	}

	// 748. 最短完整词
	public String shortestCompletingWord(String licensePlate, String[] words) {
		Map<Character, Integer> licenseMap = stringToMap(licensePlate);
		int minIndex = Integer.MAX_VALUE;
		for (int i = 0; i < words.length; i++) {
			Map<Character, Integer> wordMap = stringToMap(words[i]);
			int index = 0;
			for (Character ch : licenseMap.keySet()) {
				if ((wordMap.containsKey(ch)) && (wordMap.get(ch) != 0) && (wordMap.get(ch) >= licenseMap.get(ch))) {
					index++;
					if (index == licenseMap.size()) {
						if (minIndex < words.length) {
							if (words[minIndex].length() > words[i].length()) {
								minIndex = i;
							}
						} else {
							minIndex = i;
						}
					}
					continue;
				} else {
					break;
				}

			}

		}
		return words[minIndex];

	}

	// StringToMap
	public Map<Character, Integer> stringToMap(String str) {
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		for (int i = 0; i < str.length(); i++) {
			if ((str.toLowerCase().charAt(i) >= 'a') && (str.toLowerCase().charAt(i) <= 'z')) {
				map.put(str.toLowerCase().charAt(i), map.getOrDefault(str.toLowerCase().charAt(i), 0) + 1);
			}
		}
		return map;
	}

	// 7ms
	private final static long[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
			73, 79, 83, 89, 97, 101, 103 };

	public String shortestCompletingWord0(String licensePlate, String[] words) {
		if (licensePlate == null || licensePlate.length() == 0 || words == null || words.length == 0) {
			return "";
		}
		long pro = getProduct(licensePlate.toLowerCase());
		String res = "aaaaaaaaaaaaaaaaaaaaaaaaa";
		for (String word : words) {
			if (word.length() < res.length() && getProduct(word) % pro == 0) {
				res = word;
			}
		}
		return res;
	}

	private long getProduct(String str) {
		long res = 1L;
		char[] array = str.toCharArray();
		for (char ch : array) {
			int index = ch - 'a';
			if (index >= 0 && index <= 25) {
				res *= primes[index];
			}
		}
		return res;
	}

}
