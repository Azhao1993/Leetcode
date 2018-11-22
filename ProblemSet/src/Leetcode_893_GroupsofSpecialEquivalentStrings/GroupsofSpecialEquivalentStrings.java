package Leetcode_893_GroupsofSpecialEquivalentStrings;

import java.util.Arrays;

/*
	你将得到一个字符串数组 A。
	如果经过任意次数的移动，S == T，那么两个字符串 S 和 T 是特殊等价的。
	一次移动包括选择两个索引 i 和 j，且 i％2 == j％2，并且交换 S[j] 和 S [i]。
	现在规定，A 中的特殊等价字符串组是 A 的非空子集 S，这样不在 S 中的任何字符串与 S 中的任何字符串都不是特殊等价的。
	
	返回 A 中特殊等价字符串组的数量。
	
	示例 1：
		输入：["a","b","c","a","c","c"]
		输出：3
		解释：3 组 ["a","a"]，["b"]，["c","c","c"]
		
	示例 2：
		输入：["aa","bb","ab","ba"]
		输出：4
		解释：4 组 ["aa"]，["bb"]，["ab"]，["ba"]
		
	示例 3：
		输入：["abc","acb","bac","bca","cab","cba"]
		输出：3
		解释：3 组 ["abc","cba"]，["acb","bca"]，["bac","cab"]
		
	示例 4：
		输入：["abcd","cdab","adcb","cbad"]
		输出：1
		解释：1 组 ["abcd","cdab","adcb","cbad"]
		
	 
	
	提示：
		1 <= A.length <= 1000
		1 <= A[i].length <= 20
		所有 A[i] 都具有相同的长度。
		所有 A[i] 都只由小写字母组成。
 */
public class GroupsofSpecialEquivalentStrings {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		GroupsofSpecialEquivalentStrings gses = new GroupsofSpecialEquivalentStrings();
		String[] A = { "abcd", "cdab", "adcb", "cbad" };

		System.out.println(gses.numSpecialEquivGroups(A));
	}

	// 893. 特殊等价字符串组(269 ms)
	public int numSpecialEquivGroups(String[] A) {
		int count = 0;
		for (int i = 0; i < A.length; i++) {
			if (A[i] != null) {
				count++;
				int j = i + 1;
				while (j < A.length) {
					if (A[i].equals(A[j])) {
						A[j] = null;
						j++;
						continue;
					}
					// 判断是否是等价，等价置空
					if (A[j] == null) {
						j++;
						continue;
					}
					if (A[i].length() == A[j].length()) {
						// A[i] A[j]
						// 是等价字符串
						if (isSpecialEquivalent(A[i], A[j])) {
							A[j] = null;
						} else {
							j++;
							continue;
						}
					} else {
						j++;
						continue;
					}
				}
			}
		}
		return count;
	}

	private boolean isSpecialEquivalent(String a, String b) {
		// TODO Auto-generated method stub
		if (a.length() == 1) {
			return a.equals(b);
		}
		// 偶数位数组
		char[] atemp = new char[(a.length() + 1) / 2];
		char[] btemp = new char[(a.length() + 1) / 2];
		// 奇数位数组
		char[] atemp2 = new char[a.length() / 2];
		char[] btemp2 = new char[a.length() / 2];

		int index1 = 0;
		int index2 = 0;

		for (int i = 0; i < a.length(); i++) {
			if (i % 2 == 0) {
				atemp[index1] = a.charAt(i);
				btemp[index1++] = b.charAt(i);

			} else {
				atemp2[index2] = a.charAt(i);
				btemp2[index2++] = b.charAt(i);
			}
		}
		// 排序
		Arrays.sort(atemp);
		Arrays.sort(btemp);
		for (int i = 0; i < atemp.length; i++) {
			if (atemp[i] != btemp[i]) {
				return false;
			}
		}
		Arrays.sort(atemp2);
		Arrays.sort(btemp2);
		for (int i = 0; i < atemp2.length; i++) {
			if (atemp2[i] != btemp2[i]) {
				return false;
			}
		}
		return true;

	}

}
