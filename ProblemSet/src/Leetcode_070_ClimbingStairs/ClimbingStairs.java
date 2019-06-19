package Leetcode_070_ClimbingStairs;

import java.util.HashMap;

/*
	假设你正在爬楼梯。需要 n 阶你才能到达楼顶。	
	每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
		
	注意：给定 n 是一个正整数。
	
	示例 1：	
		输入： 2
		输出： 2
		解释： 有两种方法可以爬到楼顶。
		1.  1 阶 + 1 阶
		2.  2 阶
		
	示例 2：	
		输入： 3
		输出： 3
		解释： 有三种方法可以爬到楼顶。
		1.  1 阶 + 1 阶 + 1 阶
		2.  1 阶 + 2 阶
		3.  2 阶 + 1 阶
*/
public class ClimbingStairs {
	// 70.爬楼梯

	// 暴力法:O（2^n）
	public int climbStairs0(int n) {
		if (n <= 2) {
			return 2;
		}
		return climbStairs0(n - 1) + climbStairs0(n - 2);
	}

	// hash记忆化递归:O(n)
	private HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

	public int climbStairs1(int n) {
		if (map.containsKey(n)) {
			return map.get(n);
		}
		if (n <= 2) {
			return n;
		}
		int res = climbStairs1(n - 1) + climbStairs1(n - 2);
		map.put(n, res);
		return res;
	}

	// 动态规划O(N)+O(N)
	public int climbStairs2(int n) {
		if (n <= 2) {
			return n;
		}
		int[] dp = new int[n + 1];
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

	// 迭代：斐波那契数(N-1,N-2,N)
	public int climbStairs3(int n) {
		if (n <= 2) {
			return n;
		}
		int first = 1;
		int second = 2;
		for (int i = 3; i <= n; i++) {
			int temp = second;
			second = first + second;
			first = temp;
		}
		return second;
	}

	// Binets 方法(矩阵乘法)

//	 Q=[ Fn+1,Fn  ]  
//	   [ Fn  ,Fn−1]    
//	     第 n个斐波那契数可以由 Q^{n-1}[0,0]给出
//	     
//	  解释：
//		[ Fn+2,Fn+1] = [ Fn+1 + Fn  ,Fn+1 + 0*Fn] = [ Fn+1,Fn  ]  [1,1]
//	   	[ Fn+1,Fn  ]   [ Fn   + Fn-1,Fn   + 0*Fn]   [ Fn  ,Fn-1]  [1,0]	
//	   	Fn+1 = Q^n[0,0]

	public int climbStairs4(int n) {
		int[][] q = { { 1, 1 }, { 1, 0 } };
		int[][] res = pow(q, n);
		return res[0][0];
	}

	/**
	 * 矩阵快速幂
	 * 
	 * @param a
	 * @param n
	 * @return
	 */
	public int[][] pow(int[][] a, int n) {
		int[][] ret = { { 1, 0 }, { 0, 1 } };
		while (n > 0) {
			if ((n & 1) == 1) {
				ret = multiply(ret, a);
			}
			n >>= 1;
			a = multiply(a, a);
		}
		return ret;
	}

	/**
	 * 矩阵乘法
	 * 
	 * @param a
	 * @param b
	 * @return
	 */
	public int[][] multiply(int[][] a, int[][] b) {
		int[][] c = new int[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
			}
		}
		return c;
	}

	// 通项公式法
	public int climbStairs5(int n) {
		double sqrt5 = Math.sqrt(5);
		double fibn = Math.pow((1 + sqrt5) / 2, n + 1) - Math.pow((1 - sqrt5) / 2, n + 1);
		return (int) (fibn / sqrt5);
	}

	// 尾递归
	public int climbStairs6(int n) {
		if (n <= 2) {
			return n;
		}
		return climbStairs6(n, 1, 2, 3);
	}

	public int climbStairs6(int n, int first, int second, int i) {
		if (i == n) {
			return first + second;
		}
		return climbStairs6(n, second, first + second, i + 1);
	}
	
	

}
