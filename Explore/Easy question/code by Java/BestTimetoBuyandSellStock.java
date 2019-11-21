package Leetcode_121_BestTimetoBuyandSellStock;

/*
 	只进行一组交易
 	
	给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
	如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。	
	注意你不能在买入股票前卖出股票。
	
	示例 1:	
		输入: [7,1,5,3,6,4]
		输出: 5
		解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
		     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
	
	示例 2:	
		输入: [7,6,4,3,1]
		输出: 0
		解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/
//（1）首先是对每一天的价格和后面的价格比较，取得最大值，取得n个最大值，在从这n个最大值中取出最大值。时间复杂度O（n） 
//（2）动态规划法。从前向后遍历数组，记录当前出现过的最低价格，作为买入价格，并计算以当天价格出售的收益，作为可能的最大收益，整个遍历过程中，出现过的最大收益就是所求。

public class BestTimetoBuyandSellStock {
	// 算法1
	public int maxProfit(int[] prices) {
		// 数组的长度
		if (prices.length < 2) {
			return 0;
		}

		int maxprofit = 0;
		int max = 0;
		for (int i = 0; i < prices.length - 1; i++) {
			for (int j = i + 1; j < prices.length; j++) {
				// 每天的最大收益
				max = Math.max(max, prices[j] - prices[i]);
			}
			if (max > maxprofit) {
				maxprofit = max;
			}
		}
		return maxprofit;
	}

	// 算法2
	public int maxProfit2(int[] prices) {
		// 数组的长度
		if (prices.length < 2) {
			return 0;
		}

		// 定义最低值
		int min = prices[0];
		// 定义最大收益
		int max = 0;
		// 从前往后遍历数组
		for (int i = 0; i < prices.length; i++) {
			max = Math.max(max, prices[i] - min);
			min = Math.min(min, prices[i]);
		}
		return max;

	}
}
