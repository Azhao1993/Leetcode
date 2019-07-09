package Leetcode_126_WordLadderII;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
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

//126. 单词接龙 II
public class WordLadderII {
	class Node {
		String word;
		List<Node> child;
		int length;

		public Node(String w, int length) {
			this.word = w;
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
		Node root = new Node(beginWord, 1);
		queue.add(root);
		int minLength = Integer.MAX_VALUE;
		while (!queue.isEmpty()) {
			Node curNode = queue.poll();
			String start = curNode.word;
			int curLength = curNode.length;
			if (curLength >= minLength) {
				continue;
			}
			List<Node> child = curNode.child;
			for (int i = 0; i < length; i++) {
				String next = wordList.get(i);
				if (!used[i] || next.equals(endWord) && canGoToNext(start, next)) {
					used[i] = true;
					Node nextNode = new Node(next, curLength + 1);
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

		DFS(root, endWord, res);

		return res;

	}

	private void DFS(Node root, String endWord, List<List<String>> res) {

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

	// 花花
	// BFS创建图，DFS搜索路径
	// 同一层中可以重复
	public List<List<String>> findLadders2(String beginWord, String endWord, List<String> wordList) {

		List<List<String>> ans = new ArrayList<>();

		if (wordList == null || wordList.size() == 0) {
			return ans;
		}

		HashSet<String> dict = new HashSet<>(wordList);
		if (!dict.contains(endWord)) {
			return ans;
		}
		dict.remove(beginWord);
		dict.remove(endWord);

		HashMap<String, Integer> steps = new HashMap<>();
		steps.put(beginWord, 1);
		HashMap<String, List<String>> parents = new HashMap<>();

		Queue<String> q = new LinkedList<>();
		q.add(beginWord);

		int l = beginWord.length();
		int step = 0;
		boolean found = false;

		while (!q.isEmpty() && !found) {
			++step;
			for (int size = q.size(); size > 0; size--) {
				String p = q.poll();
				char[] w = p.toCharArray();
				for (int i = 0; i < l; i++) {
					char ch = w[i];
					for (char j = 'a'; j <= 'z'; j++) {
						if (j == ch) {
							continue;
						}
						w[i] = j;
						String newWord = String.valueOf(w);
						if (newWord.equals(endWord)) {
							// parents.getOrDefault(newWord, new ArrayList<String>()).add(p);
							if (parents.containsKey(newWord)) {
								parents.get(newWord).add(p);
							} else {
								List<String> temp = new ArrayList<>();
								temp.add(p);
								parents.put(newWord, temp);
							}
							found = true;
						} else if (steps.containsKey(newWord) && step < steps.get(newWord)) {
							parents.get(newWord).add(p);
						}
						if (dict.contains(newWord)) {
							dict.remove(newWord);
							q.add(newWord);
							steps.put(newWord, step + 1);
							if (parents.containsKey(newWord)) {
								parents.get(newWord).add(p);
							} else {
								List<String> temp = new ArrayList<>();
								temp.add(p);
								parents.put(newWord, temp);
							}
						}
					}
					w[i] = ch;
				}
			}
		}

		if (found) {
			LinkedList<String> curr = new LinkedList<>();
			curr.add(endWord);
			getPaths(endWord, beginWord, parents, curr, ans);
		}

		return ans;

	}

	private void getPaths(String word, String beginWord, HashMap<String, List<String>> parents, LinkedList<String> curr,
			List<List<String>> ans) {
		if (word.equals(beginWord)) {
			ans.add(new ArrayList<String>(curr));
			return;
		}

		for (String p : parents.get(word)) {
			curr.addFirst(p);
			getPaths(p, beginWord, parents, curr, ans);
			curr.pollFirst();
		}

	}

}
