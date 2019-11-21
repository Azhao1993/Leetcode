package Leetcode_202_HappyNumber;

import java.util.HashSet;

/*
	编写一个算法来判断一个数是不是“快乐数”。
	
	一个“快乐数”定义为：
		对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
		然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。
		如果可以变为 1，那么这个数就是快乐数。
	
	示例: 	
		输入: 19
		输出: true
		解释: 
			1^2 + 9^2 = 82
			8^2 + 2^2 = 68
			6^2 + 8^2 = 100
			1^2 + 0^2 + 0^2 = 1
 */
public class HappyNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HappyNumber hn = new HappyNumber();
		hn.isHappy(19);
	}

	//202. 快乐数
	public boolean isHappy(int n) {
		while (n >= 10) {
			n = toNum(n);
		}
		if (n == 1 || n == 7) {
			return true;
		} else {
			return false;
		}
	}

	public int toNum(int x) {
		int result = 0;
		while (x > 0) {
			result += (x % 10) * (x % 10);
			x /= 10;
		}
		return result;
	}

	// 0ms
	public boolean isHappy0(int num) {
		if (num < 10) {
			return num == 1 || num == 7;
		}
		int n = num;
		int b = 0;
		while (n > 0) {
			b += (n % 10) * (n % 10);
			n = n / 10;
		}
		return isHappy(b);
	}

}
