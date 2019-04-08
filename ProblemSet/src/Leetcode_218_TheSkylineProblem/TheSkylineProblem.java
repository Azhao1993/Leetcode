package Leetcode_218_TheSkylineProblem;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map.Entry;
import java.util.TreeMap;

/*
	城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。
	现在，假设您获得了城市风光照片（图A:skyline1）上显示的所有建筑物的位置和高度，
	请编写一个程序以输出由这些建筑物形成的天际线（图B:skyline2）。
	
	每个建筑物的几何信息用三元组 [Li，Ri，Hi] 表示，
	其中 Li 和 Ri 分别是第 i 座建筑物左右边缘的 x 坐标，Hi 是其高度。
	可以保证 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX 和 Ri - Li > 0。
	您可以假设所有建筑物都是在绝对平坦且高度为 0 的表面上的完美矩形。
	
	例如，图A中所有建筑物的尺寸记录为：
		 	[Li Ri Hi] 
		[	[2 9 10], 
			[3 7 15], 
			[5 12 12], 
			[15 20 10], 
			[19 24 8] ] 。
	
	输出是以 [ [x1,y1], [x2, y2], [x3, y3], ... ] 格式的“关键点”（图B中的红点）的列表，它们唯一地定义了天际线。
	关键点是水平线段的左端点。
	请注意，最右侧建筑物的最后一个关键点仅用于标记天际线的终点，并始终为零高度。
	此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
	
	例如，图B中的天际线应该表示为：
		[ 	[2 10], 
			[3 15], 
			[7 12], 
			[12 0], 
			[15 10], 
			[20 8], 
			[24, 0] ]。
	
	说明:
	任何输入列表中的建筑物数量保证在 [0, 10000] 范围内。
	输入列表已经按左 x 坐标 Li  进行升序排列。
	输出列表必须按 x 位排序。
	输出天际线中不得有连续的相同高度的水平线。
	例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；
	三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
 */
public class TheSkylineProblem {
	// 218. 天际线问题
	public List<int[]> getSkyline(int[][] buildings) {
		// Node数组将原始数据拆分成两组
		Node[] nodes = new Node[buildings.length * 2];
		for (int i = 0; i < buildings.length; i++) {
//			L:buildings[i][0]
//			R:buildings[i][1]
//			H:buildings[i][2]
			nodes[i * 2] = new Node(true, buildings[i][0], buildings[i][2]);
			nodes[i * 2 + 1] = new Node(false, buildings[i][1], buildings[i][2]);
		}
		// 将数据按照横坐标的大小，从小到大排序
		Arrays.sort(nodes, new NodeComparator());
		// 遍历数组将数据放入TreeMap: key：高度 value:词频
		TreeMap<Integer, Integer> htMap = new TreeMap<>();
		// 记录高度变化，形成轮廓线时使用
		TreeMap<Integer, Integer> pmMap = new TreeMap<>();
		for (int i = 0; i < nodes.length; i++) {
			if (nodes[i].isUp) {
				// 向下
				if (htMap.containsKey(nodes[i].h)) {
					htMap.put(nodes[i].h, htMap.get(nodes[i].h) + 1);
				} else {
					htMap.put(nodes[i].h, 1);
				}
			} else {
				// 向上
				if (htMap.containsKey(nodes[i].h)) {
					if (htMap.get(nodes[i].h) == 1) {
						htMap.remove(nodes[i].h);
					} else {
						htMap.put(nodes[i].h, htMap.get(nodes[i].h) - 1);
					}
				}
			}
			// 在pmMap中记录高度变化
			if (htMap.isEmpty()) {
				pmMap.put(nodes[i].x, 0);
			} else {
				pmMap.put(nodes[i].x, htMap.lastKey());
			}
		}

		// 产生轮廓点
		List<int[]> res = new ArrayList<>();
		int hight = 0;
		int start = 0;
		for (Entry<Integer, Integer> entry : pmMap.entrySet()) {
			int curStation = entry.getKey();
			int curMaxHight = entry.getValue();
			// 高度发生变化
			if (hight != curMaxHight) {

				int[] newres = new int[2];
				newres[0] = curStation;
				newres[1] = curMaxHight;
				res.add(newres);

				hight = curMaxHight;
				start = curStation;
			}
		}
		return res;

	}

}

//TreeMap的比较器
class NodeComparator implements Comparator<Node> {
	@Override
	public int compare(Node o1, Node o2) {
		// 开始位置是否相等，小的放前面
		if (o1.x != o2.x) {
			return o1.x - o2.x;
		}
		// 向下的放前面
		if (o1.isUp != o2.isUp) {
			return o1.isUp ? -1 : 1;
		}
		return 0;
	}
}

//节点
class Node {
	public boolean isUp;
	public int x;
	public int h;

	public Node(boolean flag, int x, int h) {
		this.isUp = flag;
		this.x = x;
		this.h = h;
	}
}
