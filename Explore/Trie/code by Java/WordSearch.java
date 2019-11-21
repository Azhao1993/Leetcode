package Leetcode_212_WordSearchII;

import java.util.ArrayList;
import java.util.List;

/*
	给定一个二维网格 board 和一个字典中的单词列表 words，
	找出所有同时在二维网格和字典中出现的单词。
	
	单词必须按照字母顺序，通过相邻的单元格内的字母构成，
	其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
	同一个单元格内的字母在一个单词中不允许被重复使用。
	
	示例:	
		输入: 
			words = ["oath","pea","eat","rain"] and board =
			[
			  ['o','a','a','n'],
			  ['e','t','a','e'],
			  ['i','h','k','r'],
			  ['i','f','l','v']
			]		
		输出: ["eat","oath"]
		说明:
			你可以假设所有输入都由小写字母 a-z 组成。
	
	提示:	
		你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
		如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。
		什么样的数据结构可以有效地执行这样的操作？
		散列表是否可行？为什么？ 前缀树如何？
		如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
 */

//212.单词搜索 II
public class WordSearch {
	// 前缀树+dfs
	class TrieNode {
		TrieNode[] next = new TrieNode[26];
		String word;// 标识单词的结尾
	}

	public TrieNode buildTrie(String[] words) {
		TrieNode root = new TrieNode();
		for (String w : words) {
			TrieNode p = root;
			for (char c : w.toCharArray()) {
				int i = c - 'a';
				if (p.next[i] == null) {
					p.next[i] = new TrieNode();
				}
				p = p.next[i];
			}
			p.word = w;
		}
		return root;
	}

	public List<String> findWords(char[][] board, String[] words) {
		List<String> res = new ArrayList<>();
		TrieNode root = buildTrie(words);
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				dfs(board, i, j, root, res);
			}
		}
		return res;
	}

	public void dfs(char[][] board, int i, int j, TrieNode p, List<String> res) {
		char c = board[i][j];
		// # 代表搜索过
		// null 代表不存在当前字符
		if (c == '#' || p.next[c - 'a'] == null)
			return;
		p = p.next[c - 'a'];
		if (p.word != null) { // 找到一个
			res.add(p.word);
			p.word = null; // 去重
		}

		board[i][j] = '#';
		// 向上
		if (i > 0) {
			dfs(board, i - 1, j, p, res);
		}
		// 向左
		if (j > 0) {
			dfs(board, i, j - 1, p, res);
		}
		// 向下
		if (i < board.length - 1) {
			dfs(board, i + 1, j, p, res);
		}
		// 向右
		if (j < board[0].length - 1) {
			dfs(board, i, j + 1, p, res);
		}
		// 恢复
		board[i][j] = c;
	}

}
