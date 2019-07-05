package Leetcode_049_GroupAnagrams;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
	
	示例:	
		输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
		输出:
		[
		  ["ate","eat","tea"],
		  ["nat","tan"],
		  ["bat"]
		]
	说明：	
		所有输入均为小写字母。
		不考虑答案输出的顺序。
 */
public class GroupAnagrams {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		GroupAnagrams ga = new GroupAnagrams();
		String[] strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
		System.out.println(ga.groupAnagrams(strs));
	}

	// 49. 字母异位词分组
	public List<List<String>> groupAnagrams(String[] strs) {
		HashMap<String, List<String>> map = new HashMap<>();
		for (String str : strs) {
			char[] arr = str.toCharArray();
			Arrays.sort(arr);
			String key = String.valueOf(arr);
			if (map.containsKey(key)) {
				map.get(key).add(str);
			} else {
				List<String> list = new ArrayList<String>();
				list.add(str);
				map.put(key, list);
			}
		}
		List<List<String>> res = new ArrayList<>();
		for (String key : map.keySet()) {
			res.add(map.get(key));
		}
		return res;

	}

}
