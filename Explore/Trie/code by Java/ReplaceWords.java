package Leetcode_648_ReplaceWords;

import java.util.List;

/*
	在英语中，我们有一个叫做 词根(root)的概念，
	它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。
	例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
	
	现在，给定一个由许多词根组成的词典和一个句子。
	你需要将句子中的所有继承词用词根替换掉。
	如果继承词有许多可以形成它的词根，则用最短的词根替换它。
	
	你需要输出替换之后的句子。
	
	示例 1:
	
	输入: dict(词典) = ["cat", "bat", "rat"]
	sentence(句子) = "the cattle was rattled by the battery"
	输出: "the cat was rat by the bat"
	注:
	
	输入只包含小写字母。
	1 <= 字典单词数 <=1000
	1 <=  句中词语数 <= 1000
	1 <= 词根长度 <= 100
	1 <= 句中词语长度 <= 1000
 */
public class ReplaceWords {
	public String replaceWords(List<String> dict, String sentence) {
		// 将词根存入前缀树
		Node root = new Node();		
		for (String str : dict) {
			Node temp = root;
			for (int i = 0; i < str.length(); i++) {
				int index = str.charAt(i) - 'a';
				if (temp.child[index] == null) {
					Node node = new Node();
					temp.child[index] = node;
				}
				temp = temp.child[index];
			}
			temp.isEnd = true;
		}
		// 将句子成数组
		String[] sent = sentence.split(" ");
		StringBuilder res = new StringBuilder();
		for (int j = 0; j < sent.length; j++) {
			Node temp = root;
			String str = sent[j];
			for (int i = 0; i < str.length(); i++) {
				int index = str.charAt(i) - 'a';
				if (temp.child[index] == null) {
					res.append(str);
					break;
				} else if (temp.child[index].isEnd) {
					res.append(str.substring(0, i + 1));
					break;
				}
				if (i == str.length() - 1) {
					res.append(str);
				}
				temp = temp.child[index];
			}
			if (j != sent.length - 1) {
				res.append(" ");
			}
		}
		return res.toString();

	}
}

class Node {
	boolean isEnd;
	Node[] child;

	Node() {
		isEnd = false;
		child = new Node[26];
	}
}
