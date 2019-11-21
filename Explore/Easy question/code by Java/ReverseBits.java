package Leetcode_190_ReverseBits;

/*
	颠倒给定的 32 位无符号整数的二进制位。
	
	示例:	
		输入: 43261596
		输出: 964176192
	解释:
		     43261596 的二进制表示形式为 00000010100101000001111010011100 ，
	 	返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
	
	进阶:
	如果多次调用这个函数，你将如何优化你的算法？
 */
public class ReverseBits {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		  //2147483648 (10000000000000000000000000000000)
		  ReverseBits rb = new ReverseBits();
		  //rb.reverseBits(2147483648);
	}

	// 190. 颠倒二进制位
	
	//依次将n的末尾位给result的末尾位，并且result向左移31次
	// you need treat n as an unsigned value
    public int reverseBits(int n) {
        int result = 0;
        int i = 0;
        while (i < 32) {
        	//取出n的第0位
            int temp = n & 0x01;//0x01 十六进制
            //带符号右移1位
            n = n >> 1;//<<（左移）、>>（带符号右移）和>>>（无符号右移）
        	//result*2+temp
            result = (result << 1) | temp;
            i++;
        }
        return result;
    }
    
    

}
