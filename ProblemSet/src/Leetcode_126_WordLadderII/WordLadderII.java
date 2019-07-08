package Leetcode_126_WordLadderII;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
	给定两个单词（beginWord 和 endWord）和一个字典 wordList，
	找出所有从 beginWord 到 endWord 的最短转换序列。
	转换需遵循如下规则：	
		每次转换只能改变一个字母。
		转换过程中的中间单词必须是字典中的单词。
	说明:	
		如果不存在这样的转换序列，返回一个空列表。
		所有单词具有相同的长度。
		所有单词只由小写字母组成。
		字典中不存在重复的单词。
		你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
	示例 1:	
		输入:
			beginWord = "hit",
			endWord = "cog",
			wordList = ["hot","dot","dog","lot","log","cog"]		
		输出:
			[
			  ["hit","hot","dot","dog","cog"],
			  ["hit","hot","lot","log","cog"]
			]
	示例 2:	
		输入:
			beginWord = "hit"
			endWord = "cog"
			wordList = ["hot","dot","dog","lot","log"]	
		输出: []	
		解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/word-ladder-ii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class WordLadderII {
	class Node {
		String word;
		int index;
		List<Node> child;
		int length;

		public Node(String w, int index, int length) {
			this.word = w;
			this.index = index;
			this.length = length;
			child = new ArrayList<>();
		}
	}

	public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
		List<List<String>> res = new ArrayList<>();
		if (wordList == null || wordList.size() == 0 || !wordList.contains(endWord)) {
			return res;
		}
		int length = wordList.size();
		boolean[] used = new boolean[length];
		Queue<Node> queue = new LinkedList<>();
		Node root = new Node(beginWord, -1, 1);
		queue.add(root);
		int minLength = Integer.MAX_VALUE;
		while (!queue.isEmpty()) {
			Node curNode = queue.poll();
			String start = curNode.word;
			int curLength = curNode.length;
			if (curLength > minLength) {
				break;
			}
			List<Node> child = curNode.child;
			for (int i = 0; i < length; i++) {
				String next = wordList.get(i);
				if (!used[i] || next.equals(endWord) && canGoToNext(start, next)) {
					used[i] = true;
					Node nextNode = new Node(next, i, curLength + 1);
					if (!next.equals(endWord)) {
						child.add(nextNode);
						queue.add(nextNode);
					} else {
						child.add(nextNode);
						minLength = curLength + 1;
					}
				}
			}

		}
		return res;

	}

	private boolean canGoToNext(String start, String next) {
		char[] st = start.toCharArray();
		char[] nt = next.toCharArray();
		int res = 0;
		for (int i = 0; i < st.length; i++) {
			if (st[i] != nt[i]) {
				res++;
			}
			if (res > 1) {
				return false;
			}
		}
		return res == 1;
	}
}
