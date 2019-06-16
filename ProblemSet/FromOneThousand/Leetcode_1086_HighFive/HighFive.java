package Leetcode_1086_HighFive;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;

/*
	给你一个不同学生的分数列表，请按 学生的 id 顺序 返回每个学生 最高的五科 成绩的 平均分。	
	对于每条 items[i] 记录， items[i][0] 为学生的 id，items[i][1] 为学生的分数。平均分请采用整数除法计算。	 
	
	示例：	
		输入：[[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
		输出：[[1,87],[2,88]]
		解释：
		id = 1 的学生平均分为 87。
		id = 2 的学生平均分为 88.6。但由于整数除法的缘故，平均分会被转换为 88。 
	
	提示：	
		1 <= items.length <= 1000
		items[i].length == 2
		学生的 ID 在 1 到 1000 之间
		学生的分数在 1 到 100 之间
		每个学生至少有五个分数
 */
//1086. 前五科的均分
public class HighFive {
	public int[][] highFive(int[][] items) {
		Arrays.sort(items, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				// return 0;
				int a = o1[0] - o2[0];
				int b = (a == 0 ? o2[1] - o1[1] : a);
				return b;
			}
		});

		int count = 0;
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int[] item : items) {
			int id = item[0];
			int score = item[1];
			if (map.containsKey(id) && count < 5) {
				count++;
				map.put(id, map.get(id) + score);
			} else if (!map.containsKey(id)) {
				count = 1;
				map.put(id, score);
			}
		}

		int[][] res = new int[map.keySet().size()][2];
		int i = 0;
		for (int key : map.keySet()) {
			res[i][0] = key;
			res[i++][1] = map.get(key) / 5;
		}
		return res;
	}
}
