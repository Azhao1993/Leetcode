package Leetcode_336_PalindromePairs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//336. 回文对
public class PalindromePairs {

	// 前缀树节点
	class TrieNode {
		// 标记单词的开始
		int index = -1;
		// childs
		TrieNode[] childs = new TrieNode[26];
		// 标记从0开始到此节点结束，前面的内容可以自己构成回文的单词标号
		ArrayList<Integer> list = new ArrayList<>();
	}

	TrieNode root = new TrieNode();

	// 构造倒序前缀树
	void addWord(String s, int index) {
		TrieNode node = root;
		for (int i = s.length() - 1; i >= 0; i--) {
			char ch = s.charAt(i);
			if (node.childs[ch - 'a'] == null) {
				node.childs[ch - 'a'] = new TrieNode();
			}
			if (isPalindrome(s, 0, i)) {
				node.list.add(index);
			}
			node = node.childs[ch - 'a'];
		}
		node.list.add(index);
		node.index = index;
	}

	// 搜索单词
	void search(String[] words, int index, List<List<Integer>> res) {

		TrieNode node = root;
		for (int i = 0; i < words[index].length(); i++) {
			// 当前节点是否是某个单词开头index>=0
			// 当前节点是否是同一单词index!=node.index
			// 当前单词从i-length-1,是否能构成回文
			if (node.index >= 0 && index != node.index && isPalindrome(words[index], i, words[index].length() - 1)) {
				res.add(Arrays.asList(index, node.index));
			}
			char ch = words[index].charAt(i);
			if (node.childs[ch - 'a'] == null) {
				return;
			}
			node = node.childs[ch - 'a'];
		}

		for (int j : node.list) {
			if (index != j) {
				res.add(Arrays.asList(index, j));
			}
		}
		return;
	}

	private boolean isPalindrome(String s, int i, int j) {
		while (i < j) {
			if (s.charAt(i++) != s.charAt(j--)) {
				return false;
			}
		}
		return true;
	}

	public List<List<Integer>> palindromePairs(String[] words) {
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		// 构造
		for (int i = 0; i < words.length; i++) {
			addWord(words[i], i);
		}
		// 搜索
		for (int i = 0; i < words.length; i++) {
			search(words, i, res);
		}
		return res;
	}

	// 超时
	public List<List<Integer>> palindromePairs2(String[] words) {
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		for (int i = 0; i < words.length - 1; i++) {
			for (int j = i + 1; j < words.length; j++) {
				if (isPalindrome(words[i] + words[j])) {
					List<Integer> list = new ArrayList<Integer>();
					list.add(i);
					list.add(j);
					res.add(list);
				}
				if (isPalindrome(words[j] + words[i])) {
					List<Integer> list = new ArrayList<Integer>();
					list.add(j);
					list.add(i);
					res.add(list);
				}
			}
		}
		return res;

	}

	public boolean isPalindrome(String s) {
		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
}
