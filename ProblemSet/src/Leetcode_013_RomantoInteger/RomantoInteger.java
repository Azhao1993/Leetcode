package Leetcode_013_RomantoInteger;

import java.util.HashMap;

/*
	罗马数字包含以下七种字符：I， V， X， L，C，D 和 M。
	
	字符          数值
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
	
	I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。//IV IX
	X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 //XL XC	
	C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。//CD CM
	
	给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
	
	示例 1:
		输入: "III"
		输出: 3
	示例 2:
		输入: "IV"
		输出: 4
	示例 3:
		输入: "IX"
		输出: 9
	示例 4:
		输入: "LVIII"
		输出: 58
	解释: C = 100, L = 50, XXX = 30, III = 3.
	示例 5:
		输入: "MCMXCIV"
		输出: 1994
	解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/
public class RomantoInteger {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		System.out.println("M = 1000, CM = 900, XC = 90, IV = 4");
		System.out.println(romanToInt("MCMXCIV"));
		
	}
	//13.罗马数字转整数
	public static int romanToInt(String s) {
		//hashmap数据结构
		 HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		 map.put('I', 1);
	     map.put('V', 5);
	     map.put('X', 10);
	     map.put('L', 50);
	     map.put('C', 100);
	     map.put('D', 500);
	     map.put('M', 1000);
	     char[] chs = s.toCharArray();
	     int length =chs.length;
		//结果
		int result = map.get(chs[length-1]);
		for(int i =length-2;i>=0;i--) {
			//前面的数
			int a = map.get(chs[i]);
			//后面的数
			int b = map.get(chs[i+1]);
			//前面的数比后面的数小就为-
			if(a<b) {
				result -= a;
			}else {
				result += a;
			}
		}
		return result;
	}
	/*
	public static int romanToInt(String s) {
		//结果
		int result = 0;
        //将字符串转成数组
		char[] chs = s.toCharArray();
		for(int i = 0;i<chs.length;i++) {
			if(i<chs.length-1) {
				if(chs[i]=='I') {
					if(chs[i+1]=='V') {
						result += 4;
						i++;
					}else if(chs[i+1]=='X') {
						result += 9;
						i++;
					}else {
						result += 1;
					}
				}else if(chs[i]=='V') {
					result += 5;
				}else if(chs[i]=='X') {
					if(chs[i+1]=='L') {
						result += 40;
						i++;
					}else if(chs[i+1]=='C') {
						result += 90;
						i++;
					}else {
						result += 10;					
					}
				}else if(chs[i]=='L') {
					result += 50;
				}else if(chs[i]=='C') {
					if(chs[i+1]=='D') {
						result += 400;
						i++;
					}else if(chs[i+1]=='M') {
						result += 900;
						i++;
					}else {
						result += 100;					
					}
				}else if(chs[i]=='D') {
					result += 500;
				}else{
					result += 1000;
				}
			}else {
				if(chs[i]=='I') {					
						result += 1;
				}else if(chs[i]=='V') {
					result += 5;
				}else if(chs[i]=='X') {					
					result += 10;					
				}else if(chs[i]=='L') {
					result += 50;
				}else if(chs[i]=='C') {					
					result += 100;				
				}else if(chs[i]=='D') {
					result += 500;
				}else{
					result += 5000;
				}
			}
			
		}
		return result;		
    }
	*/
}
