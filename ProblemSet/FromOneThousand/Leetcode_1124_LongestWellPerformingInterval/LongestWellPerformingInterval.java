package Leetcode_1124_LongestWellPerformingInterval;

/*
	给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。	
	我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。	
	所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。	
	请你返回「表现良好时间段」的最大长度。	 
	
	示例 1：	
		输入：hours = [9,9,6,0,6,6,9]
		输出：3
		解释：最长的表现良好时间段是 [9,9,6]。
	 
	
	提示：	
		1 <= hours.length <= 10000
		0 <= hours[i] <= 16
 */
//1124.表现良好的最长时间段
public class LongestWellPerformingInterval {
	// 超时
	public int longestWPI2(int[] hours) {
		int[] dp = new int[hours.length];
		for (int i = 0; i < hours.length; i++) {
			int tired = 0;
			int normal = 0;
			for (int j = i; j >= 0; j--) {
				if (hours[j] > 8) {
					tired++;
				} else {
					normal++;
				}
				if (tired > normal) {
					dp[i] = Math.max(dp[i], i - j + 1);
				}
			}
		}
		int res = 0;
		for (int i : dp) {
			res = Math.max(i, res);
		}
		return res;
	}

	public int longestWPI(int[] hours) {
		int len = hours.length;
		int[] sum = new int[len + 1];

		// sum[i] : 0-i有sum[i]天超过8小时
		for (int i = 0; i < len; i++) {
			sum[i + 1] = sum[i] + (hours[i] > 8 ? 1 : 0);
		}

		for (int k = len; k > 0; k--) {
			for (int i = len; i - k >= 0; i--) {
				// [i-k+1,i] 这k天一半以上
				if (sum[i] - sum[i - k] > k / 2) {
					return k;
				}
			}
		}
		return 0;
	}
}
