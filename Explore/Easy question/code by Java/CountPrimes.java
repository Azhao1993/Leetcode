package Leetcode_204_CountPrimes;

/*
	统计所有小于非负整数 n 的质数的数量。
	
	示例:	
		输入: 10
		输出: 4
		解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 */
public class CountPrimes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(new CountPrimes().countPrimes(499979));
	}

	// 204. 计数质数
	public int countPrimes(int n) {
		// 厄拉多塞筛法
		if (n <= 2) {
			return 0;
		}

		//
		int count = 0;
		boolean[] bool = new boolean[n];
		for (int i = 2; i < n; i++) {
			if (bool[i] == false) {
				count++;
				for (int j = 2; j * i < n; j++) {
					bool[j * i] = true;
					// 超时
//					if (j % i == 0) {
//						if (bool[j] == false) {
//							bool[j] = true;
//						}
//					}
				}
			}
		}

		return count;
	}

}
