package Leetcode_371_SumofTwoIntegers;

/*
	不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
	
	示例 1:	
		输入: a = 1, b = 2
		输出: 3
	
	示例 2:	
		输入: a = -2, b = 3
		输出: 1
 */
public class SumofTwoIntegers {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 371. 两整数之和
	public int getSum(int a, int b) {
		// 如果没有进位
		int result = a ^ b;
		// 进位标志
		int carry = a & b;
		if (carry != 0) {
			carry <<= 1;
			return getSum(carry,result);
		}
		return result;

	}

}
