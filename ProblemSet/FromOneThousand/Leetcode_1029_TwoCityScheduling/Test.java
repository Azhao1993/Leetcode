package Leetcode_1029_TwoCityScheduling;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Test {

	public static void main(String[] args) {
		TwoCityScheduling tcs = new TwoCityScheduling();
		int[][] costs = { { 259, 770 }, { 448, 54 }, { 926, 667 }, { 184, 139 }, { 840, 118 }, { 577, 469 } };

		System.out.println(tcs.twoCitySchedCost0(costs));
		for (int i = 0; i < costs.length; i++) {
			System.out.print(costs[i][0]);
			System.out.print("-");
			System.out.print(costs[i][1]);
			System.out.print("=");
			System.out.println(costs[i][0] - costs[i][1]);
		}
	}

}
