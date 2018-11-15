package Leetcode_475_Heaters;

import java.util.Arrays;

/*
	冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。	
	现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。	
	所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
	
	说明:	
		给出的房屋和供暖器的数目是非负数且不会超过 25000。
		给出的房屋和供暖器的位置均是非负数且不会超过10^9。
		只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
		所有供暖器都遵循你的半径标准，加热的半径也一样。
	示例 1:	
		输入: [1,2,3],[2]
		输出: 1
		解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
		
	示例 2:	
		输入: [1,2,3,4],[1,4]
		输出: 1
		解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
*/
public class Heaters {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] houses = { 1, 2, 3, 15 };

		int[] heaters = { 2, 15 };
		Heaters h = new Heaters();
		System.out.println(h.findRadius(houses, heaters));
	}

	// 475. 供暖器
	public int findRadius(int[] houses, int[] heaters) {
		// 对房子排序
		Arrays.sort(houses);
		// 对加热器排序
		Arrays.sort(heaters);
		// 房子的个数
		int n = houses.length;
		// 加热器的个数
		int m = heaters.length;
		// 最大距离差
		int minimum = 0;
		// j加热器
		int j = 0;
		// 遍历房子
		for (int i = 0; i < n; i++) {
			// Math.abs(heaters[j] - houses[i]);j到当前房子的距离
			// right = Math.abs(heaters[j+1] - houses[i]);j+1到当前房子的距离
			// j>=j+1,加热器右移，直到j<j+1,j是离当前i的最近的加热器
			while (j < m - 1 && ((Math.abs(heaters[j] - houses[i])) >= (Math.abs(heaters[j + 1] - houses[i])))) {
				j++;
			}
			// 判断当前的房子离哪个加热器近，如果离左边的加热器比较近，更新最小半径为 以前的 和 这次中的较大的
			// 如果离右边加热器比较近，遍历下一个加热器
			// 如[1,2,3,4],[1,4] 1，2离1近，3，4离4近，距离差最大是1
			minimum = Math.max(minimum, Math.abs(heaters[j] - houses[i]));
		}
		return minimum;

	}

}
