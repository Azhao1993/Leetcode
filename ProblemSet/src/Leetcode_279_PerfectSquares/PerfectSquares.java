package Leetcode_279_PerfectSquares;

import java.util.Arrays;
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
		int n = 12;
		PerfectSquares ps = new PerfectSquares();
		ps.numSquares1(n);
	}

	// 279. 完全平方数
	
	//递归 DFS(超时)
	public int numSquares2(int n) {
		return getNumSquares(n,0);
	}

	private int getNumSquares(int n,int count) {
		if(n==0) {
			return count;
		}
		int res = Integer.MAX_VALUE;
		for(int i = 1;n-i*i>=0;i++) {
			res = Math.min(res, getNumSquares(n-i*i,count+1));
		}
		return res;
	}
	
	//记忆化搜索
	public int numSquares1(int n) {
		int[] memo = new int[n+1];
		Arrays.fill(memo, -1);
		for(int i = 1;i*i<=n;i++) {
			memo[i*i] = 1;
		}
		return getNumSquares(n,memo);
	}

	private int getNumSquares(int n, int[] memo) {
		if(memo[n]!=-1) {
			return memo[n];
		}
		int res = Integer.MAX_VALUE;
		for(int i = 1;n-i*i>=0;i++) {
			res = Math.min(res, getNumSquares(n-i*i,memo)+1);
		}
		memo[n] = res;
		return memo[n];
		
	}
	
	//动态规划
	public int numSquares(int n) {
		int[] dp = new int[n+1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		for(int i = 1;i*i<=n;i++) {
			dp[i*i] = 1;
		}
		for(int i = 1;i<=n;i++) {			
			for(int j = 1;j*j<i;j++) {
				dp[i] = Math.min(dp[i], 1+dp[i-j*j]);
			}
		}
		return dp[n];
	}

	// 广度优先遍历
	public int numSquares4(int n) {
		boolean[] used = new boolean[n + 1];
		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[] { n, 0 });
		used[n] = true;
		while (!queue.isEmpty()) {
			int[] temp = queue.poll();
			int num = temp[0];
			int step = temp[1];
			for (int i = 1;; i++) {
				int a = num - i * i;
				if (a == 0) {
					return step + 1;
				} else if (a < 0) {
					break;
				}
				if (!used[a]) {
					queue.add(new int[] { a, step + 1 });
					used[a] = true;
				}
			}
		}
		return n;
	}

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
}
