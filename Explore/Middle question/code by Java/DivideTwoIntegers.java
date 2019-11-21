package Leetcode_029_DivideTwoIntegers;

/*
	给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。	
	返回被除数 dividend 除以除数 divisor 得到的商。
		
	示例 1:	
		输入: dividend = 10, divisor = 3
		输出: 3
	示例 2:	
		输入: dividend = 7, divisor = -3
		输出: -2
	说明:	
		被除数和除数均为 32 位有符号整数。
		除数不为 0。
		假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 */

//29.两数相除
public class DivideTwoIntegers {
	public static void main(String[] args) {
		int dividend = -2147483648;
		int divisor = -1;
		DivideTwoIntegers dti = new DivideTwoIntegers();
		System.out.println(dti.divide(dividend, divisor));
	}
	public int divide(int dividend, int divisor) {
		// 将int转为long
		// 使用long类型防止溢出
		int sign = 1;// 符号标志
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
			sign = -1;
		long ldividend = Math.abs((long) dividend);// 将数据升级为long,并取绝对值
		long ldivisor = Math.abs((long) divisor);// 将数据升级为long,并取绝对值

		// 边界
		if (ldivisor == 0)
			return Integer.MAX_VALUE;// 除数为0
		if ((ldividend == 0) || (ldividend < ldivisor))
			return 0;// 被除数为0，或小于除数

		long lans = ldivide(ldividend, ldivisor);

		int ans;
		// 溢出
		if (lans > Integer.MAX_VALUE) {
			ans = (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
		} else {
			ans = (int) (sign * lans);
		}
		return ans;
	}

	private long ldivide(long ldividend, long ldivisor) {
		// 递归终止条件
		if (ldividend < ldivisor)
			return 0;

		// 找到最大的倍数 multiple(divisor * multiple <= dividend),
		// 提高效率1,2,4,8,16....
		// 二分查找思想
		long sum = ldivisor;// 1倍
		long multiple = 1;// 倍数
		while ((sum + sum) <= ldividend) {
			sum += sum;
			multiple += multiple;
		}
		// (dividend - sum)/dividend
		// 递归
		return multiple + ldivide(ldividend - sum, ldivisor);
	}
}
