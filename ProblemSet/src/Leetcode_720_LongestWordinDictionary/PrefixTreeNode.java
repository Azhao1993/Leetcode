package Leetcode_720_LongestWordinDictionary;

public class PrefixTreeNode {

	/**
	 * 保存插入的字符串
	 */
	String word = "";

	/**
	 * 对于每一个节点来说，其可以与a-z中所有的其他节点相连，因此用数组来保存节点与其他节点间的联系 如对于wo单词来说，假设树根节点为root。'w' -
	 * 'a' = 22，root节点对应的数组root.links[22] = null 此时新建一个节点表示root节点和w所对应的节点相连。'o' -
	 * 'a' = 14，对于w所对应的节点有w.links[14] = null 同样新建一个节点来表示节点'w'和节点'o'相连
	 */
	PrefixTreeNode[] links = new PrefixTreeNode[26];

	/**
	 * 实现向前缀树中插入一个单词
	 */
	public void insert(String s) {
		char[] chs = s.toCharArray();
		PrefixTreeNode curNode = this;
		// 遍历当前单词中的每一个字符
		for (int i = 0; i < chs.length; i++) {
			// 判断当前字符对应的节点是否在curNode的索引数组中，不存在则加入该字符对应节点
			int index = chs[i] - 'a';
			if (curNode.links[index] == null) {
				curNode.links[index] = new PrefixTreeNode();
			}
			// 判断下一个字符
			curNode = curNode.links[index];
		}
		// 当前节点对应的单词为s
		curNode.word = s;
	}

}
