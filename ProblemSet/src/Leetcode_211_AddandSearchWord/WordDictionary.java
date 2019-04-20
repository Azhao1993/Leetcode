package Leetcode_211_AddandSearchWord;

import java.util.HashMap;

/*
	设计一个支持以下两种操作的数据结构：	
		void addWord(word)
		bool search(word)
		search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
	
	示例:	
		addWord("bad")
		addWord("dad")
		addWord("mad")
		search("pad") -> false
		search("bad") -> true
		search(".ad") -> true
		search("b..") -> true
	说明:	
		你可以假设所有单词都是由小写字母 a-z 组成的。
 */

//211. 添加与搜索单词 - 数据结构设计
public class WordDictionary {
	private Node root;

	/** Initialize your data structure here. */
	public WordDictionary() {
		root = new Node();
	}

	/** Adds a word into the data structure. */
	public void addWord(String word) {
		Node temp = root;
		for (int i = 0; i < word.length(); i++) {
			char ch = word.charAt(i);
			if (!temp.child.containsKey(ch)) {
				Node node = new Node();
				temp.child.put(ch, node);
			}
			temp = temp.child.get(ch);
		}
		temp.isEnd = true;
	}

	/**
	 * Returns if the word is in the data structure. A word could contain the dot
	 * character '.' to represent any one letter.
	 */
	public boolean search(String word) {
		return search(0, word, root);
	}

	private boolean search(int i, String word, Node node) {
		Node temp = node;
		for (int j = i; j < word.length(); j++) {
			char ch = word.charAt(j);
			if (ch == '.') {
				for (Character key : temp.child.keySet()) {
					Node child = temp.child.get(key);
					if (search(j + 1, word, child)) {
						return true;
					}
				}
				// return false;
			} else {
				if (!temp.child.containsKey(ch)) {
					return false;
				} else {
					Node child = temp.child.get(ch);
					temp = child;
				}
			}
		}
		if (temp.isEnd) {
			return true;
		}
		return false;

	}
}

class Node {
	HashMap<Character, Node> child;
	boolean isEnd = false;

	Node() {
		child = new HashMap<>();
	}

}
