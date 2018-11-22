package Leetcode_231_Powerof2;

/*
	给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
	
	示例 1:	
		输入: 1
		输出: true
		解释: 20 = 1
	
	示例 2:	
		输入: 16
		输出: true
		解释: 24 = 16
	
	示例 3:	
		输入: 218
		输出: false
 */
public class Powerof2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 231. 2的幂
	// （ n & n-1 == 0）
	public boolean isPowerOfTwo(int n) {
		return (n > 0) && ((n & (n - 1)) == 0);
	}

}
