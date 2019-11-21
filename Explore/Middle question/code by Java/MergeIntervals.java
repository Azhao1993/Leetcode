package Leetcode_056_MergeIntervals;

import java.util.ArrayList;
import java.util.List;

import Interval.Interval;

/*
	给出一个区间的集合，请合并所有重叠的区间。
	
	示例 1:	
		输入: [[1,3],[2,6],[8,10],[15,18]]
		输出: [[1,6],[8,10],[15,18]]
		解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
	示例 2:	
		输入: [[1,4],[4,5]]
		输出: [[1,5]]
		解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 */
//56.合并区间
public class MergeIntervals {
	public static void main(String[] args) {
		Interval inter1 = new Interval();
		inter1.start = 1;
		inter1.end = 3;

		Interval inter2 = new Interval();
		inter2.start = 2;
		inter2.end = 6;

		Interval inter3 = new Interval();
		inter3.start = 8;
		inter3.end = 10;

		Interval inter4 = new Interval();
		inter4.start = 15;
		inter4.end = 18;

		ArrayList<Interval> intervals = new ArrayList<Interval>();
		intervals.add(inter1);
		intervals.add(inter2);
		intervals.add(inter3);
		intervals.add(inter4);

		MergeIntervals mi = new MergeIntervals();
		mi.merge0(intervals);

	}

	public List<Interval> merge(List<Interval> intervals) {
		for (int i = 0; i < intervals.size(); i++) {
			Interval inter = intervals.get(i);
			for (int j = i + 1; j < intervals.size(); j++) {
				Interval res = intervals.get(j);
				// 比较start
				if (inter.start < res.start) {
					if (inter.end >= res.start && inter.end <= res.end) {
						res.start = inter.start;
						intervals.remove(i);
						i = i - 1;
						break;
					} else if (inter.end > res.end) {
						res.start = inter.start;
						res.end = inter.end;
						intervals.remove(i);
						i = i - 1;
						break;
					}
				} else if (inter.start >= res.start && inter.start <= res.end) {
					if (inter.end <= res.end) {
						intervals.remove(i);
						i = i - 1;
						break;
					} else if (inter.end > res.end) {
						res.end = inter.end;
						intervals.remove(i);
						i = i - 1;
						break;
					}
				}
			}
		}

		return intervals;
	}

	// 10ms
	public List<Interval> merge0(List<Interval> intervals) {
		List<Interval> list = new ArrayList<Interval>();
		Interval L = new Interval();// 一层循环保存对象
		Interval R = new Interval();// 二层循环保存对象
		// 如果被合并则进行下一个
		for (int i = 0; i < intervals.size(); i++) {
			L = intervals.get(i);
			int j = i + 1;
			for (; j < intervals.size(); j++) {
				R = intervals.get(j);
				// 两区间左端点相等
				if (R.start == L.start) {
					// 将j位置的区间设置为【start,maxEnd】
					intervals.set(j, new Interval(L.start, Math.max(L.end, R.end)));
					break;
					// 左端点左小右大
				} else if (L.start < R.start) {
					// 比较右端点和左端点
					if (L.end >= R.start) {
						Interval inter = new Interval(L.start, Math.max(L.end, R.end));
						intervals.set(j, inter);
						break;
					}

				} else {
					if (R.end >= L.start) {
						Interval inter = new Interval(R.start, Math.max(L.end, R.end));
						intervals.set(j, inter);
						break;
					}
				}
			}

			if (j >= intervals.size()) {
				list.add(intervals.get(i));
			}
		}
		return list;
	}
}
