package Leetcode_447_NumberofBoomerangs;

import java.util.HashMap;
import java.util.Map;

/*
	给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。	
	找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
	
	示例:	
		输入:
			[[0,0],[1,0],[2,0]]
		
		输出:
			2
	
	解释:
		两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 */
public class NumberofBoomerangs {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		NumberofBoomerangs nb = new NumberofBoomerangs();
		int[][] points = { { 0, 0 }, { 1, 0 }, { 2, 0 } };
		nb.numberOfBoomerangs(points);
	}

	// 447. 回旋镖的数量
	public int numberOfBoomerangs(int[][] points) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		int count = 0;
		for (int i = 0; i < points.length - 1; i++) {
			for (int j = i+1; j < points.length; j++) {
				int distance = squaredistance(points[i], points[j]);
				map.put(distance, map.getOrDefault(distance, 0) + 1);
			}
		}
		for (Integer key : map.keySet()) {
			count += map.get(key) / 2;
		}
		return count;
	}

	// 超时
	public int numberOfBoomerangs2(int[][] points) {
		// 暴力搜索
		int count = 0;
		for (int i = 0; i < points.length; i++) {
			for (int j = 0; j < points.length; j++) {
				if (i == j) {
					continue;
				}
				for (int k = 0; k < points.length; k++) {
					if ((j == k) || (k == i)) {
						continue;
					}
					if (squaredistance(points[i], points[j]) == squaredistance(points[i], points[k])) {
						count++;
					}
				}
			}
		}
		return count;
	}

	// 距离
	public int squaredistance(int[] a, int[] b) {
		return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
	}
}
