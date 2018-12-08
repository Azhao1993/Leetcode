package Leetcode_409_LongestPalindrome;

import java.util.HashMap;
import java.util.Map;

/*
	给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。	
	在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
	
	注意:
		假设字符串的长度不会超过 1010。
	
	示例 1:	
		输入:
			"abccccdd"
		
		输出:
			7
		
		解释:
			我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 */
public class LongestPalindrome {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
		new LongestPalindrome().longestPalindrome(s);
	}

	// 409. 最长回文串
	public int longestPalindrome(String s) {
		int maxLength = 0;
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		for (char ch : s.toCharArray()) {
			map.put(ch, map.getOrDefault(ch, 0) + 1);
		}
		int oddCount = 0;
		for (Character ch : map.keySet()) {
			if (map.get(ch) % 2 == 0) {
				maxLength += map.get(ch);
			} else {
				maxLength += map.get(ch) - 1;
				oddCount++;
			}
		}

		if (oddCount >= 1) {
			maxLength++;
		}

		return maxLength;
	}

	// 5ms
	public int longestPalindrome0(String s) {
		int max = 'z' - 'A' + 1;
		int[] mark = new int[max];
		int maxLen = 0;
		char[] s1 = s.toCharArray();
		for (char aS1 : s1) {
			mark[aS1 - 'A']++;
		}
		boolean flag = false;
		for (int i = 0; i < max; i++) {
			if (mark[i] != 0) {
				if (mark[i] % 2 == 0) {
					maxLen += mark[i];
				} else {
					if (mark[i] >= 1) {
						flag = true;
						maxLen += mark[i] - 1;
					}
				}
			}
		}

		return flag ? maxLen + 1 : maxLen;
	}

}
