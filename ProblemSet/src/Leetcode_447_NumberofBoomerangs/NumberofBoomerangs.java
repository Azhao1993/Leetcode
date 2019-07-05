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
	// 76ms
	public int numberOfBoomerangs(int[][] points) {
		int res = 0;
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		// 每个第一个点对应一个map
		for (int i = 0; i < points.length; i++) {
			for (int j = 0; j < points.length; j++) {
				if (j == i)
					continue;
				int d = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0])
						+ (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
				// 存在这个距离说明，能找到三个点points[i]为第一个点map中的点为第二个点，points[j]为第三个点
				int tmp = map.containsKey(d) ? map.get(d) : 0;
				// map中的点在前或在后
				res += 2 * tmp;
				map.put(d, tmp + 1);
			}
			map.clear();
		}
		return res;
	}

	// O(N^2)
	public int numberOfBoomerangs3(int[][] points) {
		int res = 0;
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < points.length; i++) {
			map.clear();
			for (int j = 0; j < points.length; j++) {
				if (i == j) {
					continue;
				} else {
					int dis = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0])
							+ (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
					map.put(dis, map.getOrDefault(dis, 0) + 1);
				}
			}
			for (int key : map.keySet()) {
				int j = map.get(key);
				res += j * (j - 1);
			}
		}
		return res;
	}
}
