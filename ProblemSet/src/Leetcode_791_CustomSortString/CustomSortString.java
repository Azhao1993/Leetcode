package Leetcode_791_CustomSortString;

/*
	字符串S和 T 只包含小写字符。在S中，所有字符只会出现一次。
	
	S 已经根据某种规则进行了排序。
	我们要根据S中的字符顺序对T进行排序。
	更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。
	
	返回任意一种符合条件的字符串T。
	
	示例:
		输入:
			S = "cba"
			T = "abcd"
		输出: "cbad"
	解释: 
		S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a". 
		由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
	注意:
		S的最大长度为26，其中没有重复的字符。
		T的最大长度为200。
		S和T只包含小写字符。
*/
import java.util.HashMap;

public class CustomSortString {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String S = "kqep";
		String T = "pekeq";
		CustomSortString css = new CustomSortString();
		System.out.println("kqeep");
		System.out.println(css.customSortString(S, T));

	}

	// 791.自定义字符串排序
	public String customSortString(String S, String T) {
		// 将S的顺序存入字符串HashMap
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		for (int i = 0; i < S.length(); i++) {
			map.put(S.charAt(i), i);
		}
		// System.out.println(map);
		// 对T进行排序
		char[] t = T.toCharArray();
		int m = 0;
		int n = 0;
		for (int i = 0; i < t.length - 1; i++) {
			if (map.get(t[i]) == null) {
				continue;
			}
			m = map.get(t[i]);
			// System.out.println(t[i]+":"+m);
			for (int j = i + 1; j < t.length; j++) {
				if (map.get(t[j]) == null) {
					continue;
				}				
				n = map.get(t[j]);
				// System.out.println(t[j]+":"+n);
				if (m > n) {
					char temp = t[i];
					t[i] = t[j];
					m = map.get(t[i]);
					t[j] = temp;
					n = map.get(t[j]);
				}
			}
		}

		return new String(t);

	}

}
