package Leetcode_12_IntegertoRoman;

import java.util.HashMap;

/*
	罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
	
	字符       		   数值
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000
	例如，
	 	罗马数字 2 写做 II ，即为两个并列的 1。
	 	12 写做 XII ，即为 X + II 。 
	 	27 写做  XXVII, 即为 XX + V + II 。
	
	通常情况下，罗马数字中小的数字在大的数字的右边。
	但也存在特例，例如 4 不写做 IIII，而是 IV。
	数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
	同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
	
	I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
	X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
	C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
	给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
	
	示例 1:
		输入: 3
		输出: "III"
	示例 2:
		输入: 4
		输出: "IV"
	示例 3:
		输入: 9
		输出: "IX"
	示例 4:
		输入: 58
		输出: "LVIII"
	解释: C = 100, L = 50, XXX = 30, III = 3.
	示例 5:
		输入: 1994
		输出: "MCMXCIV"
	解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/
public class IntegertoRoman {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IntegertoRoman itor = new IntegertoRoman();
		System.out.println(itor.intToRoman(1994));
		System.out.println("MCMXCIV");
	}

	// 12. 整数转罗马数字:152 ms
	public String intToRoman(int num) {
		StringBuffer result = new StringBuffer();
		int index = 0;
		// 创建字符串数组
		String[] str = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		// 创建整形数组
		int[] nums = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		while (num > 0) {
			if (num >= nums[index]) {
				num -= nums[index];
				result.append(str[index]);
			}else{
				index++;
			}
		}

		return result.toString();
	}

	// 12. 整数转罗马数字:104 ms
//	public String intToRoman(int num) {
//		StringBuilder result = new StringBuilder();		
//		//1000以上
//		while(num>=1000) {
//			num -= 1000;
//			result.append("M");
//		}
//		//1000以下900以上
//		if(num>=900) {
//			num -= 900;
//			result.append("CM");
//		}
//		//900以下500以上
//		if(num>=500) {
//			num -= 500;
//			result.append("D");
//		}
//		//500以下400以上
//		if(num>=400) {
//			num-=400;
//			result.append("CD");
//		}
//		//400以下100以上
//		while(num>=100) {
//			num-=100;
//			result.append("C");
//		}
//		//100以下90以上
//		if(num>=90) {
//			num-=90;
//			result.append("XC");
//		}
//		//90以下50以上
//		if(num>=50) {
//			num-=50;
//			result.append("L");		
//		}
//		//50以下40以上
//		if(num>=40) {
//			num-=40;
//			result.append("XL");		
//		}
//		//40以下10以上
//		while(num>=10) {
//			num-=10;
//			result.append("X");		
//		}
//		//10以下9以上
//		if(num>=9) {
//			num-=9;
//			result.append("IX");
//		}
//		//9以下5以上
//		if(num>=5) {
//			num-=5;
//			result.append("V");
//		}
//		//5以下4以上
//		if(num>=4) {
//			num-=4;
//			result.append("IV");
//		}
//		//4以下1以上
//		while(num>=1) {
//			num-=1;
//			result.append("I");
//		}
//		    
//		return result.toString();
//	}

}
