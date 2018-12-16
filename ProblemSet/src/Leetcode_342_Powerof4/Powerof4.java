package Leetcode_342_Powerof4;

/*
	给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
	
	示例 1:	
		输入: 16
		输出: true
	
	示例 2:	
		输入: 5
		输出: false
	
	进阶：
		你能不使用循环或者递归来完成本题吗？


 */
public class Powerof4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Powerof4 p4 = new Powerof4();
		p4.isPowerOfFour(16);
		int temp = 0x55555555;
		System.out.println(temp);
	}

	// 342.4的幂（位运算）
	public boolean isPowerOfFour(int num) {
		//首先判断是否是2的幂
		if((num <= 0) || (num & (num - 1)) != 0) {
			return false;
		}
		//
		int temp = 0x55555555;
		//1010101010101010101010101010101
		return ((num & temp)==num);
	}

}
