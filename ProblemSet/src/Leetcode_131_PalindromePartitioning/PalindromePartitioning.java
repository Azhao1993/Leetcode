package Leetcode_131_PalindromePartitioning;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
	给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。	
	返回 s 所有可能的分割方案。
	
	示例:	
		输入: "aab"
		输出:
			[
			  ["aa","b"],
			  ["a","a","b"]
			]
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/palindrome-partitioning
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//131. 分割回文串
public class PalindromePartitioning {
	List<List<String>> res = new ArrayList<>();
	String s;

	public List<List<String>> partition(String s) {
		if (s == null || s.length() == 0) {
			return res;
		}
		this.s = s;
		getPartition(0, new LinkedList<>());
		return res;
	}

	private void getPartition(int start, LinkedList list) {
		if (start == s.length()) {
			res.add(new ArrayList<String>(list));

		}

		for (int i = 1; i < s.length() - start + 1; i++) {
			String str = s.substring(start, start + i);
			if (isVaid(str)) {
				list.add(str);
				getPartition(start + i, list);
				list.removeLast();
			}
		}

	}

	private boolean isVaid(String str) {
		char[] arr = str.toCharArray();
		for (int i = 0; i < arr.length / 2; i++) {
			if (arr[i] != arr[arr.length - 1 - i]) {
				return false;
			}
		}
		return true;
	}

}
