package Leetcode_752_OpentheLock;

import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/*
	你有一个带有四个圆形拨轮的转盘锁。
	每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
	每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
	
	锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。	
	列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。	
	字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。 
	
	示例 1:	
		输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
		输出：6
	解释：
		可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
		注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
		因为当拨动到 "0102" 时这个锁就会被锁定。
		
	示例 2:	
		输入: deadends = ["8888"], target = "0009"
		输出：1
	解释：
		把最后一位反向旋转一次即可 "0000" -> "0009"。
		
	示例 3:	
		输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
		输出：-1
	解释：
		无法旋转到目标数字且不被锁定。
		
	示例 4:	
		输入: deadends = ["0000"], target = "8888"
		输出：-1	 
	
	提示：	
		死亡列表 deadends 的长度范围为 [1, 500]。
		目标数字 target 不会在 deadends 之中。
		每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
 */
public class OpentheLock {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] deadends = { "0000" };
		String target = "8888";
		OpentheLock ol = new OpentheLock();
		System.out.println(ol.openLock(deadends, target));
		// System.out.println(ol.back("9", 0));
	}

	// 752. 打开转盘锁
	public int openLock(String[] deadends, String target) {
		Set<String> deadset = new HashSet<String>();
		Set<String> set = new HashSet<String>();
		for (String str : deadends) {
			deadset.add(str);
		}
		if (deadset.contains("0000")) {
			return -1;
		}

		Queue<String> queue = new LinkedList<String>();
		queue.offer("0000");
		set.add("0000");
		int step = 0;
		while (!queue.isEmpty()) {
			step++;

			int size = queue.size();
			for (int i = 0; i < size; i++) {
				String cur = queue.peek();

				// 转动
				for (int j = 0; j < 4; j++) {
					String temp = forward(cur, j);
					if (!deadset.contains(temp) && !set.contains(temp)) {
						if (temp.equals(target)) {
							return step;
						}
						queue.offer(temp);
						set.add(temp);
					}
					String temp2 = back(cur, j);
					if (!deadset.contains(temp2) && !set.contains(temp2)) {

						if (temp2.equals(target)) {

							return step;
						}
						queue.offer(temp2);
						set.add(temp2);
					}
				}
				queue.poll();
			}
		}
		return -1;
	}

	// 向后转动
	public String back(String cur, int j) {
		StringBuilder sb = new StringBuilder(cur);
		char temp = sb.charAt(j);
		sb.deleteCharAt(j);
		temp = (char) ((temp - '0' + 9) % 10 + '0');
		sb.insert(j, temp);
		return sb.toString();
	}

	// 向前转动
	public String forward(String cur, int j) {
		StringBuilder sb = new StringBuilder(cur);
		char temp = sb.charAt(j);
		sb.deleteCharAt(j);
		temp = (char) ((temp - '0' + 1) % 10 + '0');
		sb.insert(j, temp);
		return sb.toString();
	}

	// 18ms
	public int openLock0(String[] deadends, String target) {
		boolean[] isVisit = new boolean[10000];
		boolean[] isDead = new boolean[10000];
		for (String deadEnd : deadends) {
			int deadNum = Integer.parseInt(deadEnd);
			isDead[deadNum] = true;
		}
		// 如果"0000"在deadEnds中，返回-1
		if (isDead[0]) {
			return -1;
		}
		if ("0000".equals(target)) {
			return 0;
		}

		int step = 0;

		Queue<Integer> queue = new ArrayDeque<Integer>();
		queue.offer(Integer.parseInt(target));
		isVisit[Integer.parseInt(target)] = true;
		int last = Integer.parseInt(target);
		int cenglast = last;
		while (!queue.isEmpty()) {
			while (true) {
				int[] neighbor = new int[8];
				int head = queue.poll();
				if (head == 0) {
					return step;
				}
				int[] nei = neighbor(head);
				for (int i = 0; i < 8; i++) {
					int trans = nei[i];
					if (isVisit[trans] || isDead[trans]) {
						continue;
					}
					queue.offer(trans);
					last = trans;
					isVisit[trans] = true;
				}
				if (head == cenglast) {
					break;
				}
			}
			step++;
			cenglast = last;
		}
		return -1;

	}

	private int[] neighbor(int code) {
		int[] res = new int[8];
		int a = code % 10;
		int b = (code / 10) % 10;
		int c = (code / 100) % 10;
		int d = (code / 1000) % 10;
		res[0] = d * 1000 + c * 100 + b * 10 + (a + 10 - 1) % 10;
		res[1] = d * 1000 + c * 100 + b * 10 + (a + 1) % 10;
		res[2] = d * 1000 + c * 100 + ((b + 10 - 1) % 10) * 10 + a;
		res[3] = d * 1000 + c * 100 + ((b + 1) % 10) * 10 + a;
		res[4] = d * 1000 + ((c + 10 - 1) % 10) * 100 + b * 10 + a;
		res[5] = d * 1000 + ((c + 1) % 10) * 100 + b * 10 + a;
		res[6] = ((d + 10 - 1) % 10) * 1000 + c * 100 + b * 10 + a;
		res[7] = ((d + 1) % 10) * 1000 + c * 100 + b * 10 + a;
		return res;
	}

}
