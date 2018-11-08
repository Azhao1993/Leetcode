package Leetcode_191_Numberof1Bits;

/*
	编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
	
	示例 :	
		输入: 11
		输出: 3
		解释: 整数 11 的二进制表示为 00000000000000000000000000001011	 
	
	示例 2:	
		输入: 128
		输出: 1
		解释: 整数 128 的二进制表示为 00000000000000000000000010000000
 */
public class Numberof1Bits {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//java中没有 无符号整型
		//System.out.println(new Numberof1Bits().hammingWeight(2147483648));
	}

	// 191. 位1的个数
	// you need to treat n as an unsigned value
	// 认为n为无符号数值
	public int hammingWeight(int n) {
		int count = 0;
		
//		输出为0
//		while (n != 0) {
//			if (n % 2 == 1) {
//				count++;
//			}
//			n /= 2;			
//			//The literal 2147483648 of type int is out of range
//		}
//		
		while(n!=0) {
			count += n&1;
			n >>>= 1;
		}
		return count;
	}

}
