package Leetcode_326_Powerof3;

/*
	给定一个整数，写一个函数来判断它是否是 3 的幂次方。
	
	示例 1:	
		输入: 27
		输出: true
	
	示例 2:	
		输入: 0
		输出: false
	
	示例 3:	
		输入: 9
		输出: true
	
	示例 4:	
		输入: 45
		输出: false
	
	进阶：
		你能不使用循环或者递归来完成本题吗？

 */
public class Powerof3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(new Powerof3().isPowerOfThree(27));
	}

	// 326. 3的幂

	public boolean isPowerOfThree1(int n) {
		// 暴力算法
		if (n == 0) {
			return false;
		}
		while (n != 1) {
			if (n % 3 != 0) {
				return false;
			} else {
				n /= 3;
			}

		}
		return true;
	}
	
	//对数的方法：一个数是3的次方，那么以3为底n的对数一定是个 整数。
	public boolean isPowerOfThree2(int n) {		
		double temp = Math.log10(n)/Math.log10(3);//以3为底n的对数,必须以10为底
		if((temp - (int)temp)==0) {
			return true;
		}else {
			return false;
		}		
	}
	
	

}
