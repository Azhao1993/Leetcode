package Leetcode_008_StringtoInteger_atoi;

/*
	实现 atoi，将字符串转为整数。
	该函数首先根据需要丢弃任意多的空格字符，直到找到第一个非空格字符为止。
	如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。
	如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
	字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。
	当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
	若函数不能执行有效的转换，返回 0。
	
	说明：	
		假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。
		如果数值超过可表示的范围，则返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
	
	示例 1:	
		输入: "42"
		输出: 42
	示例 2:	
		输入: "   -42"
		输出: -42
		解释: 第一个非空白字符为 '-', 它是一个负号。
	     	我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
	示例 3:	
		输入: "4193 with words"
		输出: 4193
		解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
	示例 4:	
		输入: "words and 987"
		输出: 0
		解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
	     	因此无法执行有效的转换。
	示例 5:	
		输入: "-91283472332"
		输出: -2147483648
		解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
		     因此返回 INT_MIN (−231) 。
 */
public class StringtoInteger_atoi {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StringtoInteger_atoi si = new StringtoInteger_atoi();
		System.out.println(si.myAtoi("2147483648"));

	}

	// 8. 字符串转整数 (atoi)
	public int myAtoi(String str) {
		if ((str.length() == 0) || (str == null)) {
			return 0;
		}
		// 字符串缓冲器
		StringBuilder sb = new StringBuilder(str);
		// 删除前面的‘ ’
		while (sb.charAt(0) == ' ') {
			sb.deleteCharAt(0);
			if (sb.length() == 0) {
				return 0;
			}
		}

		// 判断符号
		int a = 0;
		if (sb.charAt(0) == '-') {
			a = -1;
			sb.deleteCharAt(0);
		} else if (sb.charAt(0) == '+') {
			sb.deleteCharAt(0);
		} else if ((sb.charAt(0) < '0') || (sb.charAt(0) > '9')) {
			return 0;
		}

		// 取数
		int result = 0;
		//是否溢出
		boolean bool = false;
		for (int i = 0; i < sb.length(); i++) {
			//判断是否是数字
			if ((sb.charAt(i) >= '0') && (sb.charAt(i) <= '9')) {
				
				if(result<=Integer.MAX_VALUE / 10) {
					result *= 10; 
				}else {
					bool = true;;
					break;					
				}			
				
				if (result <= Integer.MAX_VALUE-(sb.charAt(i)-48)) {
					result +=  sb.charAt(i) - 48;
				}else {
					bool = true;;
					break;
				}
				
					
			} else {
				//遇到非数字
				break;
			}
		}

		if (a == -1) {
			if (bool) {
				return Integer.MIN_VALUE;
			}
			return a * result;
		} else {
			if (bool) {
				return Integer.MAX_VALUE;
			}
			return result;
		}

	}

}
