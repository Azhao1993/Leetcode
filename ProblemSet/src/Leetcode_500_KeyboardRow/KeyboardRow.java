package Leetcode_500_KeyboardRow;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
	
	图片（American keyboard）：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/keyboard.png	 
	
	示例：	
		输入: ["Hello", "Alaska", "Dad", "Peace"]
		输出: ["Alaska", "Dad"]
	
	注意：	
		你可以重复使用键盘上同一字符。
		你可以假设输入的字符串将只包含字母。
 */
public class KeyboardRow {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] words = { "Hello", "Alaska", "Dad", "Peace" };
		new KeyboardRow().findWords(words);
	}

	// 500. 键盘行
	public String[] findWords(String[] words) {
		List<String> list = new ArrayList<String>();
		for (int i = 0; i < words.length; i++) {
			if (words[i].length() == 1) {
				list.add(words[i]);
				continue;
			}
			int temp = inCol(words[i].charAt(0));
			for (int j = 1; j < words[i].length(); j++) {
				if (!(inCol(words[i].charAt(j)) == temp)) {
					break;
				}
				if (j == words[i].length() - 1) {
					list.add(words[i]);
				}
			}
		}
		return (String[]) list.toArray(new String[list.size()]);
	}

	public int inCol(char ch) {
		List<Character> list1 = Arrays.asList('q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p');
		List<Character> list2 = Arrays.asList('a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l');
		char temp = Character.toLowerCase(ch);
		if (list1.contains(temp)) {
			return 1;
		} else if (list2.contains(temp)) {
			return 2;
		} else {
			return 3;
		}
	}

	// 1ms
	public String[] findWords0(String[] words) {
		int[] k1 = new int[256];
		k1['q'] = 1;
		k1['w'] = 1;
		k1['e'] = 1;
		k1['r'] = 1;
		k1['t'] = 1;
		k1['y'] = 1;
		k1['u'] = 1;
		k1['i'] = 1;
		k1['o'] = 1;
		k1['p'] = 1;
		k1['a'] = 4;
		k1['s'] = 4;
		k1['d'] = 4;
		k1['f'] = 4;
		k1['g'] = 4;
		k1['h'] = 4;
		k1['j'] = 4;
		k1['k'] = 4;
		k1['l'] = 4;
		k1['z'] = 9;
		k1['x'] = 9;
		k1['c'] = 9;
		k1['v'] = 9;
		k1['b'] = 9;
		k1['n'] = 9;
		k1['m'] = 9;
		if (words.length == 0)
			return new String[] {};
		List<String> list = new ArrayList<String>();
		for (String temp : words) {
			char[] chars = temp.toCharArray();
			if (valid(k1, chars))
				list.add(temp);
		}
		return list.toArray(new String[list.size()]);
	}

	public boolean valid(int[] k1, char[] a) {
		if (a.length == 1)
			return true;
		int count = 0;
		for (char temp : a) {
			if (temp < 97)
				count += k1[temp + 32];
			else
				count += k1[temp];
		}
		if (count == a.length)
			return true;
		else if (count == a.length * 4)
			return true;
		else if (count == a.length * 9)
			return true;
		else
			return false;
	}

}
