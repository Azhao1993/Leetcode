package Leetcode_401_BinaryWatch;

import java.util.ArrayList;
import java.util.Arrays;
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
		new BinaryWatch().readBinaryWatch2(1);
	}

	// 401. 二进制手表
	List<String> res = new ArrayList<>();
	int num;
	int[] watch = new int[10];

	public List<String> readBinaryWatch2(int num) {
		this.num = num;
		getBinaryTime(0, 0, 0, 0);
		return res;
	}

	private void getBinaryTime(int c, int start, int h, int m) {
		if (c == num) {
			res.add(String.valueOf(h) + ":" + String.format("%02d", m));
			return;
		}

		for (int i = start; i < 10; i++) {
			int th = h;
			int tm = m;
			if (i <= 3) {
				if (h + (1 << (3 - i)) < 12) {
					h += (1 << (3 - i));
					watch[i] = 1;
				} else {
					continue;
				}
			} else {
				if (m + (1 << (9 - i)) < 60) {
					m += (1 << (9 - i));
					watch[i] = 1;
				} else {
					continue;
				}
			}
			getBinaryTime(c + 1, i + 1, h, m);
			h = th;
			m = tm;
			watch[i] = 0;
		}
	}

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
