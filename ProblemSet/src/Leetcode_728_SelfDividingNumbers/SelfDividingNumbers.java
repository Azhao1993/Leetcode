package Leetcode_728_SelfDividingNumbers;

import java.util.ArrayList;
import java.util.List;

/*
	自除数 是指可以被它包含的每一位数除尽的数。	
	例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。	
	还有，自除数不允许包含 0 。	
	给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。
	
	示例 1：	
		输入： 
			上边界left = 1, 下边界right = 22
		输出：
		 	[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
		注意：		
			每个输入参数的边界满足 1 <= left <= right <= 10000。
 */
public class SelfDividingNumbers {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		SelfDividingNumbers sdn = new SelfDividingNumbers();
		int left = 9;
		int right = 22;
		sdn.selfDividingNumbers(left, right);
	}

	// 728. 自除数
	public List<Integer> selfDividingNumbers(int left, int right) {
		List<Integer> result = new ArrayList<Integer>();
		for (int i = left; i <= right; i++) {
			if (isselfDividingNumbers(i)) {
				result.add(i);
			}
		}
		return result;
	}

	// 自除
	public boolean isselfDividingNumbers(int num) {
		if (num < 10) {
			return true;
		}
		int temp = num;
		while (temp > 0) {
			if (temp % 10 == 0) {
				return false;
			}
			if (num % (temp % 10) == 0) {
				temp /= 10;
			} else {
				return false;
			}

		}
		return true;
	}

	public boolean isSelfDivNum(int num) {
		int digit;
		int tmp = num;
		while (tmp != 0) {
			digit = tmp % 10;
			if (digit == 0 || num % digit != 0)
				return false;
			tmp = tmp / 10;
		}
		return true;
	}

}
