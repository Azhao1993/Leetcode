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
	// 149. 直线上最多的点数
	public int maxPoints(Point[] points) {
		// 没有点
		if (points == null) {
			return 0;
		}
		// 0、1、2个点
		if (points.length <= 2) {
			return points.length;
		}
		// key,value
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
					// 同一个点
					overlap++;
					continue;
				}
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
			result = Math.max(result, max + overlap + 1);
		}
		return result;

	}

	private int generateGCD(int a, int b) {
		// 水平直线
		if (b == 0) {
			return a;
		} else {
			return generateGCD(b, a % b);
		}

	}
}
