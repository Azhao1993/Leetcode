package Leetcode_172_FactorialTrailingZeroes;
/*
	给定一个整数 n，返回 n! 结果尾数中零的数量。
	
	示例 1:	
		输入: 3
		输出: 0
	解释: 3! = 6, 尾数中没有零。
	示例 2:	
		输入: 5
		输出: 1
	解释: 5! = 120, 尾数中有 1 个零.
	说明: 你算法的时间复杂度应为 O(log n) 。
 */

//172.阶乘后的零(只需要计算包含多少个5)
public class FactorialTrailingZeroes {
	public static void main(String[] args) {
		System.out.println(new FactorialTrailingZeroes().trailingZeroes(2147483647));
	}

	// 
	public int trailingZeroes(int n) {
		// int countoftwo = 0;
		int countoffive = 0;
		while (n >= 5) {
			if (n % 5 != 0) {
				n--;
				continue;
			}
			int temp5 = n;
			while (temp5 % 5 == 0) {
				countoffive++;
				temp5 /= 5;
			}
			n -= 5;
		}
		return countoffive;
	}

	// 13ms
	public int trailingZeroes0(int n) {
		if (n < 5)
			return 0;
		else
			return n / 5 + trailingZeroes(n / 5);
	}
}
