package Leetcode_746_MinCostClimbingStairs;

/*
	数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。
	每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。
	您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。
	
	示例 1:
		输入: cost = [10, 15, 20]
		输出: 15
	解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
	
	 示例 2:
		输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
		输出: 6
	解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
	注意：
		cost 的长度将会在 [2, 1000]。
		每一个 cost[i] 将会是一个Integer类型，范围为 [0, 999]。
*/
public class MinCostClimbingStairs {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MinCostClimbingStairs mccs = new MinCostClimbingStairs();
		int[] cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
		System.out.println(mccs.minCostClimbingStairs(cost));
	}

	// 746. 使用最小花费爬楼梯
	public int minCostClimbingStairs(int[] cost) {
		// 动态规划
		int length = cost.length;
		int[] sumcost = new int[length + 1];
		// 上第一个台阶
		sumcost[0] = cost[0];
		// 上第二个台阶
		sumcost[1] = cost[1];
		// 后面的台阶
		for (int i = 2; i < cost.length + 1; i++) {
			int temp = 0;
			if (i != cost.length ) {
				temp = cost[i];
			}
			// 从i-1到i需要花费cost[i];
			sumcost[i] = Math.min(sumcost[i - 2], sumcost[i - 1]) + temp;
		}
		return sumcost[length];
	}
}
