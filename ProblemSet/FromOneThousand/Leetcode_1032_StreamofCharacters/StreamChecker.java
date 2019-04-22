package Leetcode_1032_StreamofCharacters;
/*
	按下述要求实现 StreamChecker 类：	
		StreamChecker(words)：
			构造函数，用给定的字词初始化数据结构。
		query(letter)：
			如果存在某些 k >= 1，可以用查询的最后 k个字符
			(按从旧到新顺序，包括刚刚查询的字母)
			拼写出给定字词表中的某一字词时，返回 true。
			否则，返回 false。
	
	示例：	
		StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // 初始化字典
		streamChecker.query('a');          // 返回 false
		streamChecker.query('b');          // 返回 false
		streamChecker.query('c');          // 返回 false
		streamChecker.query('d');          // 返回 true，因为 'cd' 在字词表中
		streamChecker.query('e');          // 返回 false
		streamChecker.query('f');          // 返回 true，因为 'f' 在字词表中
		streamChecker.query('g');          // 返回 false
		streamChecker.query('h');          // 返回 false
		streamChecker.query('i');          // 返回 false
		streamChecker.query('j');          // 返回 false
		streamChecker.query('k');          // 返回 false
		streamChecker.query('l');          // 返回 true，因为 'kl' 在字词表中。 
	
	提示：	
		1 <= words.length <= 2000
		1 <= words[i].length <= 2000
		字词只包含小写英文字母。
		待查项只包含小写英文字母。
		待查项最多 40000 个。
 */

//1032. 字符流(超时)
public class StreamChecker {
	TrieTree tt;
	String s;

	// 构造字典
	public StreamChecker(String[] words) {
		tt = new TrieTree();
		for (int i = 0; i < words.length; i++) {
			tt.reverseBuild(words[i],words[i].length()-1,tt.root);
		}
		s="";
	}

	public boolean query(char letter) {
		s += letter;
		return tt.reverseSearch(s,s.length()-1,tt.root);
	}
}

//前缀树节点
class TrieNode {
	boolean isEnd = false;
	TrieNode[] childs;

	TrieNode() {
		childs = new TrieNode[26];
	}
}

//前缀树
class TrieTree {
	TrieNode root;

	TrieTree() {
		root = new TrieNode();
	}
	//递归
	//翻转
	public void reverseBuild(String s,int i,TrieNode root) {
		if(i==-1) {
			root.isEnd = true;
			return;
		}
		int index = s.charAt(i)-'a';
		if(root.childs[index]==null) {
			root.childs[index]= new TrieNode();			
		}		
		reverseBuild(s,i-1,root.childs[index]);
	}
	//查询
	public boolean reverseSearch(String s,int i,TrieNode root) {
		if(i==-1||root.isEnd) {
			return root.isEnd;
		}
		int index =s.charAt(i)-'a';
		if(root.childs[index]==null) {
			return false;
		}
		return reverseSearch(s,i-1,root.childs[index]);
	}
	
	//迭代
	// 翻转构造
	public void reverseBuild(String s) {
		TrieNode node = root;
		for (int i = s.length() - 1; i >= 0; i--) {
			int index = s.charAt(i) - 'a';
			if (node.childs[index] == null) {
				TrieNode child = new TrieNode();
				node.childs[index] = child;
			}
			node = node.childs[index];
		}
		node.isEnd = true;
	}

	// 翻转查找
	public boolean reverseSearch(String s) {
		TrieNode node = root;

		for (int i = s.length() - 1; i >= 0; i--) {
			if (node.isEnd) {
				return true;
			}
			int index = s.charAt(i) - 'a';
			if (node.childs[index] == null) {
				return false;
			}
			node = node.childs[index];
		}
		return node.isEnd;
	}
}
