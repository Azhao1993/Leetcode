package Contest_College_2019_spring;

/*
	给定一系列价格 [p1,p2...,pn] 和一个目标 target，
	将每个价格 pi 舍入为 Roundi(pi) 以使得舍入数组 [Round1(p1),Round2(p2)...,Roundn(pn)] 之和达到给定的目标值 target。
	每次舍入操作 Roundi(pi) 可以是向下舍 Floor(pi) 也可以是向上入 Ceil(pi)。
	
	如果舍入数组之和无论如何都无法达到目标值 target，就返回 -1。
	否则，以保留到小数点后三位的字符串格式返回最小的舍入误差，其定义为 Σ |Roundi(pi) - (pi)|（ i 从 1 到 n ）。	 
	
	示例 1：	
		输入：prices = ["0.700","2.800","4.900"], target = 8
		输出："1.000"
		解释： 
		使用 Floor，Ceil 和 Ceil 操作得到 (0.7 - 0) + (3 - 2.8) + (5 - 4.9) = 0.7 + 0.2 + 0.1 = 1.0 。
	示例 2：	
		输入：prices = ["1.500","2.500","3.500"], target = 10
		输出："-1"
		解释：
		达到目标是不可能的。 
	
	提示：	
		1 <= prices.length <= 500
		表示价格的每个字符串 prices[i] 都代表一个介于 0 和 1000 之间的实数，并且正好有 3 个小数位。
		target 介于 0 和 1000000 之间。
 */
import java.util.PriorityQueue;

public class MinimizeRoundingErrortoMeetTarget {
	public static void main(String[] args) {
		String[] prices = { "0.700", "2.800", "4.900" };
		int target = 8;
		MinimizeRoundingErrortoMeetTarget mremt = new MinimizeRoundingErrortoMeetTarget();
		System.out.println(mremt.minimizeError(prices, target));
	}

	public String minimizeError0(String[] prices, int target) {
		int n = prices.length;
		// 第一列 整数部分 第二列 小数部分
		String[][] pri = new String[n][2];

		for (int i = 0; i < n; i++) {
			pri[i][0] = prices[i].split("\\.")[0];
			pri[i][1] = prices[i].split("\\.")[1];
		}
		// 向下取整和
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += Integer.parseInt(pri[i][0]);
		}
		// target太小
		if (target < sum) {
			return "-1";
		}
		// 从小到大 存 小数部分
		PriorityQueue<Integer> queue = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(pri[i][1]);
			if (temp != 0) {
				queue.add(temp);
			}
		}
		// target太大
		if (sum + queue.size() < target) {
			return "-1";
		}
		int err = 0;
		int size = queue.size();
		for (int i = 0; !queue.isEmpty(); i++) {
			// 小的向下取整，大的向上取整
			// terget-sum个向上取整
			if (i >= size - target + sum) {
				// 向上取整
				err += (1000 - queue.poll());
			} else {
				// 向下取整
				err += queue.poll();
			}
		}
		double res = (double) err / 1000;
		return String.format("%.3f", res);
	}

	// clean
	public String minimizeError(String[] prices, int target) {
		int n = prices.length;
		// 从小到大存小数部分
		PriorityQueue<Integer> queue = new PriorityQueue<>();
		int sum = 0;// 整数部分和
		for (int i = 0; i < n; i++) {
			sum += Integer.parseInt(prices[i].split("\\.")[0]);
			int temp = Integer.parseInt(prices[i].split("\\.")[1]);
			// 存在整数的情况
			if (temp != 0) {
				queue.add(temp);
			}
		}
		// target太小或太大
		if (target < sum || sum + queue.size() < target) {
			return "-1";
		}
		double err = 0;
		// 向上取整的个数为terget-sum
		int count = queue.size() - target + sum;
		while (!queue.isEmpty()) {
			if (count == 0) {
				// 向上取整
				err += (1000 - queue.poll());
			} else {
				// 向下取整
				err += queue.poll();
				count--;
			}
		}
		return String.format("%.3f", err / 1000);
	}

}
