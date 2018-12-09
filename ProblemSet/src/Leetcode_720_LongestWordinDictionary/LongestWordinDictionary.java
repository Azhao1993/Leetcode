package Leetcode_720_LongestWordinDictionary;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	给出一个字符串数组words组成的一本英语词典。
	从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。
	若其中有多个可行的答案，则返回答案中字典序最小的单词。	
	若无答案，则返回空字符串。
	
	示例 1:	
		输入: 
			words = ["w","wo","wor","worl", "world"]
		输出:
		 	"world"
		解释: 
			单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
	示例 2:	
		输入: 
			words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
		输出:
		 	"apple"
		解释: 
			"apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。
	注意:	
		所有输入的字符串都只包含小写字母。
		words数组长度范围为[1,1000]。
		words[i]的长度范围为[1,30]。
 */
public class LongestWordinDictionary {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String[] words = { "w", "wo", "wor", "worl", "world" };
		Arrays.sort(words);
		LongestWordinDictionary lwd = new LongestWordinDictionary();
		System.out.println("apple".compareTo("apply"));
		System.out.println(lwd.longestWord(words));
		// System.out.println("a".compareTo("ap"));
		Arrays.sort(words);
		Arrays.toString(words);

	}

	// 720. 词典中最长的单词
	public String longestWord(String[] words) {
		// Arrays.sort(words);
		Map<String, Integer> map = new HashMap<String, Integer>();
		// 将数组存入map
		for (int i = words.length - 1; i >= 0; i--) {
			map.put(words[i], i);
		}
		// 遍历数组
		String result = new String();// words[words.length-1];
		for (int i = words.length - 1; i >= 0; i--) {
			// 记录当前最长单词的索引
			int maxIndex = i;
			StringBuilder sb = new StringBuilder(words[i]);
			while (sb.length() > 0) {
				// sb.deleteCharAt(sb.length() - 1);
				if (map.containsKey(sb.toString())) {
					if (sb.length() == 1) {
						if (result.length() < words[maxIndex].length()) {
							result = words[maxIndex];
						} else if (result.length() == words[maxIndex].length()) {
							if (result.compareTo(words[maxIndex]) > 0) {
								result = words[maxIndex];
							}
						}
					}
					sb.deleteCharAt(sb.length() - 1);
				} else {
					break;
				}
			}

		}

		return result;
	}

	// 11ms
	public String longestWord0(String[] words) {
		// 首先构建前缀树的根节点
		PrefixTreeNode root = new PrefixTreeNode();
		root.word = "_";
		// 利用单词数组构建前缀树
		for (String word : words) {
			root.insert(word);
		}
		String[] result = new String[] { "z" };
		// 在前缀树中搜索
		dfs(root, result);
		return result[0];
	}

	/**
	 * 利用深度优先遍历来进行搜索
	 */
	void dfs(PrefixTreeNode node, String[] result) {
		// 如果一个节点包含的单词长度为0则说明原先单词数组中没有单词与该节点对应，直接返回
		if (node == null || node.word.length() == 0) {
			return;
		}
		for (PrefixTreeNode child : node.links) {
			if (child != null) {
				dfs(child, result);
				// 寻找最长单词并且长度相等的情况下返回最小的，因此在这里进行判断
				boolean valid = child.word.length() > result[0].length()
						|| (child.word.length() == result[0].length() && child.word.compareTo(result[0]) < 0);
				if (valid) {
					result[0] = child.word;
				}
			}
		}
	}

}
