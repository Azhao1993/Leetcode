package Leetcode_149_MaxPointsonaLine;

import java.util.HashMap;
import java.util.Map;

import Point.Point;

/*
	给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
	
	示例 1:	
		输入: [[1,1],[2,2],[3,3]]
		输出: 3
		解释:
		^
		|
		|        o
		|     o
		|  o  
		+------------->
		0  1  2  3  4
	
	示例 2:	
		输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
		输出: 4
		解释:
		^
		|
		|  o
		|     o        o
		|        o
		|  o        o
		+------------------->
		0  1  2  3  4  5  6
 */
public class MaxPointsonaLine {
	public static void main(String[] args) {
		int[][] p = { { 1, 1 }, { 3, 2 }, { 5, 3 }, { 4, 1 }, { 2, 3 }, { 1, 4 } };
		Point[] points = new Point[p.length];
		int i = 0;
		for (int[] temp : p) {
			int x = temp[0];
			int y = temp[1];
			points[i++] = new Point(x, y);
		}
		MaxPointsonaLine mpl = new MaxPointsonaLine();
		mpl.maxPoints(points);
	}

	// 149. 直线上最多的点数
	public int maxPoints(Point[] points) {
		// 没有点
		if (points == null) {
			return 0;
		}
		// 0、1、2个点肯定在同一条直线上
		if (points.length <= 2) {
			return points.length;
		}
		// <△x,<△y,count>>
		// 经过同一个点，且△x,△y相同一定在同一条直线上
		Map<Integer, Map<Integer, Integer>> map = new HashMap<Integer, Map<Integer, Integer>>();
		int result = 0;

		for (int i = 0; i < points.length; i++) {
			map.clear();
			int overlap = 0;
			int max = 0;
			for (int j = i + 1; j < points.length; j++) {
				int x = points[j].x - points[i].x;// x1-x2
				int y = points[j].y - points[i].y;// y1-y2
				if (x == 0 && y == 0) {
					// 重复
					overlap++;
					continue;
				}
				// 约分
				int gcd = generateGCD(x, y);
				if (gcd != 0) {
					x /= gcd;
					y /= gcd;
				}

				if (map.containsKey(x)) {
					if (map.get(x).containsKey(y)) {
						map.get(x).put(y, map.get(x).get(y) + 1);
					} else {
						map.get(x).put(y, 1);
					}
				} else {
					Map<Integer, Integer> m = new HashMap<Integer, Integer>();
					m.put(y, 1);
					map.put(x, m);
				}
				max = Math.max(max, map.get(x).get(y));
			}
			// max + 重复点 + 本身
			result = Math.max(result, max + overlap + 1);
		}
		return result;

	}

	// 获取最小公约数
	private int generateGCD(int a, int b) {
		if (b == 0) {
			return a;
		} else {
			return generateGCD(b, a % b);
		}
	}

	// 6ms
	public int maxPoints0(Point[] points) {
		if (points.length == 0) {
			return 0;
		}
		if (points.length <= 2) {
			return points.length;
		}

		int max = 2;
		// 第一个点point[i]
		for (int i = 0; i < points.length; i++) {
			int samePosition = 0; // 重复位置的点 个数
			int sameSlope = 1; // 斜率相同的点 个数
			// 第一个点point[j]
			for (int j = i + 1; j < points.length; j++) {
				// 判断是否为重复位置的点
				long x1 = points[j].x - points[i].x;
				long y1 = points[j].y - points[i].y;
				if (x1 == 0 && y1 == 0) {
					samePosition++;
				} else {
					// 第二个点与第一个点一定在同一直线上
					sameSlope++;
					// 遍历找到与前两个点在同一个直线上的点
					for (int k = j + 1; k < points.length; k++) {
						// 第一个点point[k]
						long x2 = points[k].x - points[i].x;
						long y2 = points[k].y - points[i].y;
						// 斜率相同
						if (x1 * y2 == x2 * y1) {
							sameSlope++;
						}
					}
				}
				if (max < (samePosition + sameSlope)) {
					max = samePosition + sameSlope;
				}
				sameSlope = 1;
			}
		}
		return max;

	}
}
