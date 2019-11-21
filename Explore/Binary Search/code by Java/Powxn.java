package Leetcode_050_Powxn;

/*
	实现 pow(x, n) ，即计算 x 的 n 次幂函数。

	示例 1:	
		输入: 2.00000, 10
		输出: 1024.00000
	
	示例 2:	
		输入: 2.10000, 3
		输出: 9.26100
		
	示例 3:
	
		输入: 2.00000, -2
		输出: 0.25000
		解释: 2-2 = 1/22 = 1/4 = 0.25
		
	说明:	
		-100.0 < x < 100.0
		n 是 32 位有符号整数，其数值范围是 [−2^31, 2^(31 − 1)] 。
*/
public class Powxn {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double x = 2.00000;
		int n = 12;
		Powxn pxn = new Powxn();
		System.out.println(pxn.myPow(x, n));
	
	}

	// 50.Pow(x,n)
	public double myPow(double x, int n) {
		
		if (n == 0 || x == 1) {
			return 1;
		}
	
		if (n == Integer.MIN_VALUE && x == -1) {
			return 1;
		}
		if (n == Integer.MIN_VALUE) {
			return 0;
		}
		double num = 1.0;
		int m = Math.abs(n);
		while (m > 0) {
			
			if(m%2==1) {
				num*=x;				
			}
			x *= x;
			m >>= 1;
		}
		if (n < 0) {
			num = 1.0 / num;
		}
		return num;
	}

}