package Leetcode_208_ImplementTrie;

import java.util.ArrayList;

/*
	实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
	
	示例:	
		Trie trie = new Trie();
	
		trie.insert("apple");
		trie.search("apple");   // 返回 true
		trie.search("app");     // 返回 false
		trie.startsWith("app"); // 返回 true
		trie.insert("app");   
		trie.search("app");     // 返回 true
	说明:	
	你可以假设所有的输入都是由小写字母 a-z 构成的。
	保证所有输入均为非空字符串。
 */
public class Trie {
	private TrieNode root;

	public Trie() {
		root = new TrieNode();		
	}

	/** Inserts a word into the trie. */
	public void insert(String word) {
		TrieNode curNode = root;
		for (int i = 0; i < word.length(); i++) {
			char temp = word.charAt(i);
			if (curNode.children[temp - 'a'] == null) {
				TrieNode node = new TrieNode();
				curNode.children[temp - 'a'] = node;
			}
			curNode = curNode.children[temp - 'a'];
		}
		curNode.isEnd++;
	}

	/** Returns if the word is in the trie. */
	public boolean search(String word) {
		TrieNode curNode = root;
		for (int i = 0; i < word.length(); i++) {
			char temp = word.charAt(i);
			if (curNode.children[temp - 'a'] == null) {
				return false;
			}
			curNode = curNode.children[temp - 'a'];
		}
		if (curNode.isEnd == 0) {
			return false;
		}
		return true;
	}

	/**
	 * Returns if there is any word in the trie that starts with the given prefix.
	 */
	public boolean startsWith(String prefix) {
		TrieNode curNode = root;
		for (int i = 0; i < prefix.length(); i++) {
			char temp = prefix.charAt(i);
			if (curNode.children[temp - 'a'] == null) {
				return false;
			}
			curNode = curNode.children[temp - 'a'];
		}
		return true;
	}
}

class TrieNode {	
	public int isEnd;
	public TrieNode[] children;

	//构造
	public TrieNode() {
		isEnd = 0;
		children = new TrieNode[26];
	}
}
