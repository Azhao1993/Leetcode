package Leetcode_279_PerfectSquares;

import java.util.LinkedList;
import java.util.Queue;

/*
	给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。
	你需要让组成和的完全平方数的个数最少。
	
	示例 1:	
		输入: n = 12
		输出: 3 
		解释: 12 = 4 + 4 + 4.
	
	示例 2:	
		输入: n = 13
		输出: 2
		解释: 13 = 4 + 9.
 */
public class PerfectSquares {
	public static void main(String[] args) {
		int n = 7186;
		PerfectSquares ps = new PerfectSquares();
		System.out.println(ps.numSquares0(n));
	}

	// 279. 完全平方数
	// Lagrange 四平方定理： 任何一个正整数都可以表示成不超过四个整数的平方之和。
	// 结果只有1,2,3,4，四种可能。
	// 推论：满足四数平方和定理的数n（必须满足由四个数构成），必定满足 n=4^a*(8^b+7)
	// 1ms
	public int numSquares0(int n) {
		while (n % 4 == 0) {
			n /= 4;
		}
		if (n % 8 == 7) // 满足推论 说明由4个完全平方数构成
			return 4;
		int a = 0;
		while (a * a <= n) {
			// 判断这个缩小后的数是否可以通过两个平方数的和或一个平方数组成
			int b = (int) (Math.sqrt((n - a * a)));// 如果n=a^2 那么b=0
			// if (a * a == n)
			// return 1;
			if (a * a + b * b == n)
				// 返回 a、b中非0的个数和
				return (a != 0 ? 1 : 0) + (b != 0 ? 1 : 0);
			a += 1;
		}
		return 3;
	}

	public int numSquares(int n) {
		Queue<int[]> queue = new LinkedList<int[]>();
		int[] first = { n, 0 };
		queue.offer(first);
		while (!queue.isEmpty()) {
			int num = queue.peek()[0];
			int step = queue.peek()[1];
			for (int i = Close(num); i > 0; i--) {
				int[] temp = { num - i * i, step + 1 };
				if (temp[0] == 0) {
					return temp[1];
				}
				queue.offer(temp);
			}
			queue.poll();
		}
		return -1;
	}

	// 最大的接近的数
	private int Close(int n) {
		for (int i = (int) Math.ceil(Math.sqrt(n)); i >= 0; i--) {
			if (i * i <= n) {
				return i;
			}
		}
		return 0;
	}

}
