package Leetcode_884_UncommonWordsfromTwoSentences;

import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;

/*
	给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）	
	如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。	
	返回所有不常用单词的列表。	
	您可以按任何顺序返回列表。	 
	
	示例 1：	
		输入：A = "this apple is sweet", B = "this apple is sour"
		输出：["sweet","sour"]
	示例 2：	
		输入：A = "apple apple", B = "banana"
		输出：["banana"]	 
	
	提示：	
		0 <= A.length <= 200
		0 <= B.length <= 200
		A 和 B 都只包含空格和小写字母。
 */
public class UncommonWordsfromTwoSentences {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根

	}

	// 884. 两句话中的不常见单词
	public String[] uncommonFromSentences(String A, String B) {
		List<String> list = new ArrayList<String>();
		Map<String, Integer> map = new HashMap<String, Integer>();
		// String[] strA = ;
		// String[] strB = );
		for (String str : A.split(" ")) {
			map.put(str, map.getOrDefault(str, 0) + 1);
		}
		for (String str : B.split(" ")) {
			map.put(str, map.getOrDefault(str, 0) + 1);
		}
		for (String str : map.keySet()) {
			if (map.get(str) == 1) {
				list.add(str);
			}
		}
		return list.toArray(new String[list.size()]);

	}

	// 5ms
	public String[] uncommonFromSentences0(String A, String B) {
		HashMap<String, Integer> map = new HashMap<>();
		for (String str : A.split(" ")) {
			if (!map.containsKey(str))
				map.put(str, 1);
			else
				map.put(str, map.get(str) + 1);
		}

		for (String str : B.split(" ")) {
			if (!map.containsKey(str))
				map.put(str, 1);
			else
				map.put(str, map.get(str) + 1);
		}
		ArrayList<String> list = new ArrayList<>();
		for (String key : map.keySet()) {
			if (map.get(key) == 1)
				list.add(key);
		}

		return list.toArray(new String[list.size()]);
	}

}
