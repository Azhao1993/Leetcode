package Leetcode_166_FractiontoRecurringDecimal;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
	
	如果小数部分为循环小数，则将循环的部分括在括号内。
	
	示例 1:	
		输入: numerator = 1, denominator = 2
		输出: "0.5"
	示例 2:	
		输入: numerator = 2, denominator = 1
		输出: "2"
	示例 3:	
		输入: numerator = 2, denominator = 3
		输出: "0.(6)"
 */

//166. 分数到小数
public class FractiontoRecurringDecimal {
	public static void main(String[] args) {
		System.out.println(new FractiontoRecurringDecimal().fractionToDecimal(2, 3));
	}

	public String fractionToDecimal(int num, int den) {
		long numerator = num;
		long denominator = den;
		StringBuilder result = new StringBuilder();
		boolean flag = false;
		if (numerator < 0 && denominator > 0) {
			flag = true;
			numerator = -1 * numerator;
		} else if (numerator > 0 && denominator < 0) {
			flag = true;
			denominator = -1 * denominator;
		} else if (numerator < 0 && denominator < 0) {
			numerator = -1 * numerator;
			denominator = -1 * denominator;
		}
		if (flag) {
			result.append("-");
		}
		// 余数
		long rem = numerator % denominator;
		long quo = numerator / denominator;
		if (rem == 0) {
			return result.append(quo).toString();
		}

		StringBuilder quopart = new StringBuilder();
		List<Long> rempart = new ArrayList<Long>();
		// StringBuilder rempart = new StringBuilder();

		while (rem != 0) {
			int index = rempart.indexOf(rem);
			if (index != -1) {
				quopart.insert(index, "(").append(")");
				break;
			}
			rempart.add(rem);
			quo = rem * 10 / denominator;// 商
			quopart.append(quo);
			rem = rem * 10 % denominator;
		}

		quo = numerator / denominator;

		result.append(quo).append(".").append(quopart);
		return result.toString();

	}

	// 3ms
	public String fractionToDecimal0(int numerator, int denominator) {
		// 边界处理
		if (numerator == -1 && denominator == Integer.MIN_VALUE)
			return "0.0000000004656612873077392578125";
		if (numerator == 0)
			return "0";
		//
		StringBuilder res = new StringBuilder();
		// 异或：不同时<0,添负号
		if (numerator < 0 ^ denominator < 0) {
			res.append("-");
		}

		long l_numerator = Math.abs((long) numerator);
		denominator = Math.abs(denominator);

		res.append(l_numerator / denominator);
		int remainder = (int) (l_numerator % denominator);
		if (remainder == 0)
			return res.toString();
		res.append(".");
		Map<Integer, Integer> map = new HashMap<>();
		int pos = 0, len = res.length();
		while (remainder != 0) {
			if (map.containsKey(remainder)) {
				Integer start = map.get(remainder);
				res.insert(len + start, "(");
				res.append(")");
				return res.toString();
			}
			map.put(remainder, pos++);
			res.append(remainder * 10 / denominator);
			remainder = remainder * 10 % denominator;
		}

		return res.toString();
	}
}
