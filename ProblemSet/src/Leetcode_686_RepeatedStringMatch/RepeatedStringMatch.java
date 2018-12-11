package Leetcode_686_RepeatedStringMatch;

/*
	给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。
	
	举个例子，A = "abcd"，B = "cdabcdab"。	
	答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。
	
	注意:	
	 	A 与 B 字符串的长度在1和10000区间范围内。
*/
public class RepeatedStringMatch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RepeatedStringMatch rsm = new RepeatedStringMatch();
		System.out.println(rsm.repeatedStringMatch("abcd", "cdabcdab"));
	}

	// 686. 重复叠加字符串匹配
	public int repeatedStringMatch(String A, String B) {
		// 计数器
		int count = 1;
		StringBuilder abuilder = new StringBuilder(A);
		while (count <= B.length() / A.length() + 2) {
			if (abuilder.indexOf(B) != -1) {
				return count;
			}
			count++;
			abuilder.append(A);
		}
		return -1;
	}

	// 6ms
	public int repeatedStringMatch0(String A, String B) {
		int lenA = A.length();
		int lenB = B.length();
		int indexA = 0;
		int indexB = 0;
		while (indexB < lenB) {
			if (lenA < lenB && indexA >= 2 * lenB) {
				return -1;
			}

			if (lenA >= lenB && indexA >= 2 * lenA) {
				return -1;
			}

			if (A.charAt(indexA % lenA) == B.charAt(indexB)) {
				indexA++;
				indexB++;
			} else if (indexB == 0) {
				indexA++;
			} else {
				// TODO find next ch(b)
				int i = indexA + 1;
				for (; i < indexA + 1 + lenB; i++) {
					if (A.charAt(i % lenA) == B.charAt(indexB)) {
						break;
					}
				}
				if (i == indexA + 1 + lenB)
					return -1;
				indexA = i - indexB;
				indexB = 0;
			}
		}
		return (indexA - 1) / lenA + 1;
	}

}
