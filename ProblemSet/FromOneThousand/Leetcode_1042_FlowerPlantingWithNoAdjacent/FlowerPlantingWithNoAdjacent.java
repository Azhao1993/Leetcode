package Leetcode_1042_FlowerPlantingWithNoAdjacent;

import java.util.Arrays;
import java.util.HashMap;
import java.util.TreeSet;

/*
	有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。	
	paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。	
	另外，没有花园有 3 条以上的路径可以进入或者离开。	
	你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。	
	以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。
	
	示例 1：	
		输入：N = 3, paths = [[1,2],[2,3],[3,1]]
		输出：[1,2,3]
	示例 2：	
		输入：N = 4, paths = [[1,2],[3,4]]
		输出：[1,2,1,2]
	示例 3：	
		输入：N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
		输出：[1,2,3,4]
	
	提示：	
		1 <= N <= 10000
		0 <= paths.size <= 20000
		不存在花园有 4 条或者更多路径可以进入或离开。
		保证存在答案。
 */
//1042. 不邻接植物
public class FlowerPlantingWithNoAdjacent {
	public int[] gardenNoAdj(int N, int[][] paths) {
		int[] gardens = new int[N];
		// boolean[] flag = new boolean[N];
		Arrays.fill(gardens, -1);
		//
		HashMap<Integer, TreeSet<Integer>> map = new HashMap<>();
		int min = 0;
		int max = 0;
		for (int i = 0; i < paths.length; i++) {
			min = Math.min(paths[i][0], paths[i][1]);
			max = Math.max(paths[i][0], paths[i][1]);
			if (map.containsKey(min)) {
				map.get(min).add(max);
			} else {
				TreeSet<Integer> set = new TreeSet<>();
				set.add(max);
				map.put(min, set);
			}
		}

		for (int i = 1; i <= N; i++) {
			if (gardens[i - 1] == -1) {
				gardens[i - 1] = 1;
			}
			if (map.containsKey(i)) {
				for (Integer j : map.get(i)) {
					if (gardens[j - 1] == -1) {
						if (gardens[i - 1] == 1) {
							gardens[j - 1] = gardens[i - 1] + 1;
						} else {
							gardens[j - 1] = 1;
						}

					} else if (gardens[i - 1] == gardens[j - 1]) {
						if (gardens[j - 1] - 2 > 0) {
							gardens[j - 1] = 1;
						} else {
							gardens[j - 1] = gardens[i - 1] + 1;
						}
					}

				}
			}
		}
		for (int i = 0; i < N; i++) {
			System.out.println(gardens[i]);
		}
		return gardens;
	}

	public static void main(String[] args) {
		int N = 8;

		int[][] paths = { { 1, 4 }, { 1, 5 }, { 6, 8 }, { 3, 5 }, { 7, 5 }, { 3, 2 }, { 3, 6 }, { 2, 7 }, { 7, 8 },
				{ 1, 2 }, { 4, 6 } };
		new FlowerPlantingWithNoAdjacent().gardenNoAdj(N, paths);
	}
}
