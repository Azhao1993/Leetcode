package Leetcode_451_SortCharactersByFrequency;

import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

class Node {
	int count = 0;
	int letter;

	public Node(int count, int letter) {
		this.count = count;
		this.letter = letter;
	}
}

class SortCharactersByFrequency2 {
	public String frequencySort(String s) {
		int sum = s.length();
		if (sum <= 2)
			return s;
		char[] out = new char[sum];
		int[] counts = new int[256];
		char[] chars = s.toCharArray();
		List<Node> list = new LinkedList<Node>();

		for (char a : chars) {
			counts[a] = counts[a] + 1;
		}
		for (int i = 0; i <= 255; i++) {
			if (counts[i] != 0)
				list.add(new Node(counts[i], i));

		}
		int j = 0;
		Collections.sort(list, new Comparator<Node>() {
			public int compare(Node o1, Node o2) {
				return o2.count - o1.count;
			}
		});
		for (Node temp : list) {// 取出元素temp
			for (int i = temp.count; i > 0; i--) {// 用temp的key做计数
				out[j++] = (char) temp.letter;
			}
		}
		return new String(out);
	}
}
