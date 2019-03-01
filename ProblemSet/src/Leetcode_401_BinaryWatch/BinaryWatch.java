package Leetcode_401_BinaryWatch;

import java.util.ArrayList;
import java.util.List;

/*
	二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。	
	每个 LED 代表一个 0 或 1，最低位在右侧。
	
	https://upload.wikimedia.org/wikipedia/commons/8/8b/Binary_clock_samui_moon.jpg
	
	例如，上面的二进制手表读取 “3:25”。	
	给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
	
	案例:	
		输入: n = 1
		返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
	 
	
	注意事项:	
		输出的顺序没有要求。
		小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
		分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
 */
public class BinaryWatch {

	public static void main(String[] args) {
		int num = 4;
		BinaryWatch bw = new BinaryWatch();

		List<String> list = bw.readBinaryWatch(num);
		System.out.println(list);
		List<String> res = bw.readBinaryWatch0(num);
		System.out.print("[");
		for (String str : list) {
			if (res.contains(str)) {
				continue;
			}
			System.out.print(str);
			System.out.print(", ");
		}
		System.out.println();
		System.out.print("[");
		for (String str : res) {
			if (list.contains(str)) {
				continue;
			}
			System.out.print(str);
			System.out.print(", ");
		}

	}

	// 401. 二进制手表

	// 遍历时间
	public List<String> readBinaryWatch1(int num) {
		List<String> times = new ArrayList<>();
		for (int h = 0; h < 12; h++)
			for (int m = 0; m < 60; m++)
				if (Integer.bitCount(h * 64 + m) == num)
					times.add(String.format("%d:%02d", h, m));
		return times;
	}

	// 回溯
	public List<String> readBinaryWatch(int num) {
		List<String> result = new ArrayList<String>();
		if (num == 0) {
			result.add("0:00");
			return result;
		}
		// boolean[] used = new boolean[10];
		int[] time = new int[2];
		readBinaryWatch(0, 0, time, num, result);
		return result;
	}

	private void readBinaryWatch(int start, int count, int[] time, int num, List<String> result) {
		if (count == num) {
			// result.add(getTime(used, num));
			result.add(String.format("%d:%02d", time[1], time[0]));
			return;
		}
		int hour = 0;
		int min = 0;
		for (int i = start; i < 10; i++) {

			if (i <= 5) {
				min = (int) Math.pow(2, i);
				time[0] += min;
				if (time[0] >= 60) {
					time[0] -= min;
					continue;
				}
			} else {
				min = 0;
				hour = (int) Math.pow(2, i - 6);
				time[1] += hour;
				if (time[1] > 11) {
					time[1] -= hour;
					continue;
				}

			}
			// used[i] = true;
			readBinaryWatch(i + 1, count + 1, time, num, result);
			time[0] -= min;
			time[1] -= hour;
			// used[i] = false;
		}

	}

//	public String getTime(boolean[] used, int num) {
//		int hour = 0;
//		int min = 0;
//		int count = 0;
//		StringBuilder res = new StringBuilder();
//		for (int i = 0; i < 10; i++) {
//			if (used[i]) {
//				if (i <= 5) {
//					min += (int) Math.pow(2, i);
//				} else {
//					hour += (int) Math.pow(2, i - 6);
//				}
//				count++;
//				if (count == num) {
//					break;
//				}
//			}
//		}
//		res.append(hour).append(":");
//		if (min < 10) {
//			res.append("0");
//		}
//		res.append(min);
//		return res.toString();
//	}

	// 1ms
	public List<String> readBinaryWatch0(int num) {
		int[] sign = new int[10];
		List<String> res = new ArrayList<>();
		result(res, sign, 0, num);
		return res;
	}

	public void result(List<String> list, int[] sign, int n, int num) {
		if (num == 0) {
			input(list, sign);
			return;
		}
		if (n > 9)
			return;
		sign[n] = 1;
		if (valid(sign)) {
			result(list, sign, n + 1, num - 1);
		}
		sign[n] = 0;
		result(list, sign, n + 1, num);
	}

	public Boolean valid(int[] sign) {
		int hour = 8 * sign[0] + 4 * sign[1] + 2 * sign[2] + 1 * sign[3];
		int minute = 32 * sign[4] + 16 * sign[5] + 8 * sign[6] + 4 * sign[7] + 2 * sign[8] + 1 * sign[9];
		if (hour > 11 || minute > 59)
			return false;
		return true;
	}

	public void input(List<String> list, int[] sign) {
		int hour = 8 * sign[0] + 4 * sign[1] + 2 * sign[2] + 1 * sign[3];
		int minute = 32 * sign[4] + 16 * sign[5] + 8 * sign[6] + 4 * sign[7] + 2 * sign[8] + 1 * sign[9];
		if (minute > 9)
			list.add(hour + ":" + minute);
		else
			list.add(hour + ":0" + minute);
	}
}
