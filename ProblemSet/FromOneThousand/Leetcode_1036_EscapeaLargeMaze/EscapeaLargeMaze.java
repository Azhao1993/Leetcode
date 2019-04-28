package Leetcode_1036_EscapeaLargeMaze;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

/*
	在一个 10^6 x 10^6 的网格中，每个网格块的坐标为 (x, y)，其中 0 <= x, y < 10^6。
	
	我们从源方格 source 开始出发，意图赶往目标方格 target。
	每次移动，我们都可以走到网格中在四个方向上相邻的方格，只要该方格不在给出的封锁列表 blocked 上。
	
	只有在可以通过一系列的移动到达目标方格时才返回 true。否则，返回 false。	 
	
	示例 1：	
		输入：blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
		输出：false
		解释：
		从源方格无法到达目标方格，因为我们无法在网格中移动。
	示例 2：	
		输入：blocked = [], source = [0,0], target = [999999,999999]
		输出：true
		解释：
		因为没有方格被封锁，所以一定可以到达目标方格。 
	
	提示：	
		0 <= blocked.length <= 200
		blocked[i].length == 2
		0 <= blocked[i][j] < 10^6
		source.length == target.length == 2
		0 <= source[i][j], target[i][j] < 10^6
		source != target
 */

//1036.逃离大迷宫
public class EscapeaLargeMaze {
	public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
		// 没有阻碍
		if (blocked.length == 0) {
			return true;
		}
		HashSet<String> visited = new HashSet();
		HashSet<String> blockc = new HashSet();

		for (int[] block : blocked) {
			blockc.add(block[0] + "+" + block[1]);
		}

		Queue<int[]> travel = new LinkedList();
		travel.add(source);
		int level = 0;
		while (!travel.isEmpty()) {

			if (blockc.isEmpty() || blockc.size() < level + 1) {
				return true;
			}
			level++;
			int size = travel.size();
			while (size > 0) {
				size--;
				int[] current = travel.poll();

				String key = current[0] + "+" + current[1];
				if (visited.contains(key)) {
					continue;
				}

				if (blockc.contains(key)) {
					blockc.remove(key);
					visited.add(key);
					continue;
				}
				visited.add(key);
				for (int k = -1; k <= 1; k++) {
					for (int j = -1; j <= 1; j++) {
						if (Math.abs(k + j) == 1 && (current[0] + k) >= 0 && (current[1] + j) >= 0
								&& (current[0] + k) < 999999 && (current[1] + j) < 999999) {
							travel.add(new int[] { current[0] + k, current[1] + j });
						}
					}
				}
			}

		}

		return false;
	}

}
