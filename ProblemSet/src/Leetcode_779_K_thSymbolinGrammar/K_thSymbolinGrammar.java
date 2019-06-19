package Leetcode_779_K_thSymbolinGrammar;

import java.util.ArrayList;

/*
	在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。	
	给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）	
	
	例子:	
		输入: N = 1, K = 1
		输出: 0
		
		输入: N = 2, K = 1
		输出: 0
		
		输入: N = 2, K = 2
		输出: 1
		
		输入: N = 4, K = 5
		输出: 1
	
	解释:
		第一行: 0
		第二行: 01
		第三行: 0110
		第四行: 01101001
	
	注意：	
		N 的范围 [1, 30].
		K 的范围 [1, 2^(N-1)].
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/k-th-symbol-in-grammar
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//779. 第K个语法符号
public class K_thSymbolinGrammar {
	public static void main(String[] args) {
		new K_thSymbolinGrammar().kthGrammar2(2, 2);
	}

	// 暴力法(超时)
	public int kthGrammar0(int N, int K) {
		ArrayList<Integer> list = new ArrayList<>();
		while (list.size() < Math.pow(2, N - 1)) {
			int size = list.size();
			if (size == 0) {
				list.add(0);
			} else {
				for (int i = 0; i < size; i++) {
					int x = list.remove(0);
					if (x == 0) {
						list.add(0);
						list.add(1);
					} else {
						list.add(1);
						list.add(0);
					}
				}
			}
		}
		return list.get(K - 1);
	}

	// 递归（父变体）
	public int kthGrammar1(int N, int K) {
		if (N == 1) {
			return 0;
		}
		return kthGrammar1(N - 1, (K + 1) / 2) ^ (1 - K % 2);

	}

	// 递归（翻转变体）
	public int kthGrammar2(int N, int K) {
		if (N == 1) {
			return 0;
		}
		int halflength = 1 << N - 2;
		if (K <= halflength) {
			return kthGrammar2(N - 1, K);
		} else {
			return kthGrammar2(N - 1, K - halflength) ^ 1;
		}
	}

	// 二进制计数
	public int kthGrammar3(int N, int K) {
		return Integer.bitCount(K - 1) % 2;
	}
}
