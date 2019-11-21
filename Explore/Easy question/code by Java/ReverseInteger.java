package Leetcode_007_ReverseInteger;
/*
	给定一个 32 位有符号整数，将整数中的数字进行反转。
		示例 1:
			输入: 123
			输出: 321
		
		 示例 2:
			输入: -123
			输出: -321
		
		示例 3:
			输入: 120
			输出: 21
	注意:	
	假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。
	根据这个假设，如果反转后的整数溢出，则返回 0。
 */
public class ReverseInteger {
	   //7. 反转整数
    public int reverse(int x) {    	
    	//符号判断
    	if(x>0) {
    		return reverseWithoutSign(x);
    	}else {
    		return -1*reverseWithoutSign(-1*x);
    	}        
    }
    
    //无符号翻转
    public int reverseWithoutSign(int x) {
    	int result = 0;
    	while(x>0) {    		
    		//判断是否溢出的方法，不能直接相加或者相减
			//判断result*10是否溢出
			//判断
			if ((result>Integer.MAX_VALUE/10)||((x % 10) > Integer.MAX_VALUE - result * 10)){
    			return 0;
    		}else {
    			result = result*10 + x%10;
    			x/=10;
    		}    		
    	}
    	return result;
    }
}
