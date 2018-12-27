package Leetcode_917_ReverseOnlyLetters;

import java.util.Arrays;

/*
	 给定一个字符串 S，返回 “反转后的” 字符串，
	 其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
	
	 示例 1：	
		 输入："ab-cd"
		 输出："dc-ba"
	
	 示例 2：	
		 输入："a-bC-dEf-ghIj"
		 输出："j-Ih-gfE-dCba"
	
	 示例 3：	
		 输入："Test1ng-Leet=code-Q!"
		 输出："Qedo1ct-eeLg=ntse-T!"	
	 提示：	
		 1. S.length <= 100
		 2. 33 <= S[i].ASCIIcode <= 122 
		 3. S 中不包含 \ or "
 */
public class ReverseOnlyLetters {
	
	// 917. 仅仅反转字母
	public String reverseOnlyLetters(String S) {
		StringBuilder sb = new StringBuilder();
		int head = 0;
		int tail = S.length() - 1;
		int j = 0;

		while (head <= tail) {
			if (head == tail) {
				sb.insert(head, S.charAt(head));
				break;
			}
			if (isWord(S.charAt(head)) && (isWord(S.charAt(tail)))) {
				// 在头的位置添加尾
				sb.insert(head, S.charAt(tail));
				// 在尾的位置添加头
				sb.insert(sb.length() - j, S.charAt(head));
				j++;
				head++;
				tail--;
			} else if (!isWord(S.charAt(head))) {
				sb.insert(head, S.charAt(head));
				head++;
			} else if (!isWord(S.charAt(tail))) {
				sb.insert(sb.length() - j, S.charAt(tail));
				j++;
				tail--;
			}
		}
		return sb.toString();

	}

	private boolean isWord(char c) {
		if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
			return true;
		}
		return false;
	}

	// 5ms
	public String reverseOnlyLetters0(String S) {
		int start = 0;
		int end = S.length() - 1;
		char[] c = S.toCharArray();
		while (start < end) {
			while (!((c[start] >= 65 && c[start] <= 90) || (c[start] >= 97 && c[start] <= 122)) && start < end) {
				start++;
			}
			while (!((c[end] >= 65 && c[end] <= 90) || (c[end] >= 97 && c[end] <= 122)) && start < end) {
				end--;
			}
			char temp = c[start];
			c[start++] = c[end];
			c[end--] = temp;
		}
		return String.valueOf(c);
	}

}
