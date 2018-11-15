package Leetcode_387_FirstUniqueCharacterinaString;

/*
	给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
	
	案例:	
		s = "leetcode"
		返回 0.
	
		s = "loveleetcode",
		返回 2.
*/
public class FirstUniqueCharacterinaString {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FirstUniqueCharacterinaString fucs = new FirstUniqueCharacterinaString();
		System.out.println("cabccaddcd");
		System.out.println(fucs.firstUniqChar("cabccaddcd"));

	}
	//387.字符串中的第一个唯一字符
	public int firstUniqChar(String s) {
		// 字符串长度为1
		if (s.length() == 1) {
			return 0;
		}
		// 字符数组
		char[] chs = s.toCharArray();
		int length = chs.length;
		int[] flag = new int[chs.length];
		for (int i = 0; i < length; i++) {
			// 前面是否存在
			if (i > 0) {
				if (flag[i - 1] == 0) {
					return i - 1;
				}
			}
			if (flag[i] != 0) {
				continue;
			}
			// 最后一位
			if (i == length - 1) {
				return i;
			}
			for (int j = i + 1; j < length; j++) {
				if (flag[j] != 0) {
					continue;
				}
				if (chs[i] == chs[j]) {
					flag[i]++;
					flag[j]++;
				}
			}

		}
		return -1;

	}

}
