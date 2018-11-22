package Leetcode_476_NumberComplement;

import java.util.Arrays;

/*
	给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。
	
	注意:	
	
		给定的整数保证在32位带符号整数的范围内。
		你可以假定二进制数不包含前导零位。
	
	示例 1:	
		输入: 5
		输出: 2
		解释: 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
	
	示例 2:	
		输入: 1
		输出: 0
		解释: 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。
 */
public class NumberComplement {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		NumberComplement nc = new NumberComplement();
		nc.findComplement(5);
	}

	// 476. 数字的补数
	public int findComplement(int num) {
		StringBuilder sb = new StringBuilder();
		while (num > 0) {
			if (num % 2 == 1) {
				sb.append(0);
			} else {
				sb.append(1);
			}
			num /= 2;
		}
		char[] reschar = sb.reverse().toString().toCharArray();
		int result = 0;
		for (int i = 0; i < reschar.length; i++) {
			result = result * 2 + reschar[i] - '0';
		}
		return result;
	}

}
