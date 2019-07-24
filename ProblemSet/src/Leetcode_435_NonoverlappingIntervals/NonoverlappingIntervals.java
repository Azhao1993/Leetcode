package Leetcode_435_NonoverlappingIntervals;

import java.util.Arrays;
import java.util.Comparator;

/*
	给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
	
	注意:	
		可以认为区间的终点总是大于它的起点。
		区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
	示例 1:	
		输入: [ [1,2], [2,3], [3,4], [1,3] ]	
		输出: 1	
		解释: 移除 [1,3] 后，剩下的区间没有重叠。
	示例 2:	
		输入: [ [1,2], [1,2], [1,2] ]	
		输出: 2	
		解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
	示例 3:	
		输入: [ [1,2], [2,3] ]	
		输出: 0	
		解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/non-overlapping-intervals
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class NonoverlappingIntervals {
	// 动态规划(最长上升子序列)
	public int eraseOverlapIntervals(int[][] intervals) {
		if (intervals == null || intervals.length == 0) {
			return 0;
		}
		Arrays.sort(intervals, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[0] - o2[0] == 0 ? o1[1] - o2[1] : o1[0] - o2[0];
			}
		});
		// dp[i] =
		int[] dp = new int[intervals.length];
		Arrays.fill(dp, 1);
		for (int i = 0; i < intervals.length; i++) {
			for (int j = 0; j < i; j++) {
				if (intervals[j][1] <= intervals[i][0]) {
					dp[i] = Math.max(dp[i], dp[j] + 1);
				}
			}
		}
		int res = 1;
		for (int d : dp) {
			res = Math.max(d, res);
		}
		return intervals.length - res;
	}

	// 贪心 结束的早的留下
	public int eraseOverlapIntervals2(int[][] intervals) {
		if (intervals == null || intervals.length == 0) {
			return 0;
		}
		Arrays.sort(intervals, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[1] - o2[1] == 0 ? o1[0] - o2[0] : o1[1] - o2[1];
			}
		});
		int res = 1;
		int pre = 0;
		for (int i = 1; i < intervals.length; i++) {
			if (intervals[i][0] >= intervals[pre][1]) {
				res++;
				pre = i;
			}
		}
		return intervals.length - res;

	}

}
