package Leetcode_1041_RobotBoundedInCircle;

/*
	在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。机器人可以接受下列三条指令之一：	
		"G"：直走 1 个单位
		"L"：左转 90 度
		"R"：右转 90 度
		机器人按顺序执行指令 instructions，并一直重复它们。	
	只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。
	
	示例 1：	
		输入："GGLLGG"
		输出：true
		解释：
		机器人从 (0,0) 移动到 (0,2)，转 180 度，然后回到 (0,0)。
		重复这些指令，机器人将保持在以原点为中心，2 为半径的环中进行移动。
	示例 2：	
		输入："GG"
		输出：false
		解释：
		机器人无限向北移动。
	示例 3：	
		输入："GL"
		输出：true
		解释：
		机器人按 (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ... 进行移动。	
	提示：	
		1 <= instructions.length <= 100
		instructions[i] 在 {'G', 'L', 'R'} 中
 */
//1041.困于环中的机器人
public class RobotBoundedInCircle {
	// 又臭又长
	public boolean isRobotBounded(String instructions) {
		int[] cur = { 0, 0 };
		int curf = 3;
		return isRobotBounded(instructions, curf, cur);
	}

	public boolean isRobotBounded(String instructions, int curf, int[] cur) {
		// 东西南北
		int[][] dirc = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
		for (int i = 0; i < instructions.length(); i++) {
			switch (instructions.charAt(i)) {
			case 'G':
				cur[0] += dirc[curf][0];
				cur[1] += dirc[curf][1];
				break;
			case 'L':
				if (curf == 0) {
					curf = 3;
				} else if (curf == 1) {
					curf = 2;
				} else if (curf == 2) {
					curf = 0;
				} else {
					curf = 1;
				}
				break;
			case 'R':
				if (curf == 0) {
					curf = 2;
				} else if (curf == 1) {
					curf = 3;
				} else if (curf == 2) {
					curf = 1;
				} else {
					curf = 0;
				}
				break;
			}
		}
		System.out.println(curf);
		System.out.println(cur[0] + "," + cur[1]);
		if (cur[0] == 0 && cur[1] == 0) {
			return true;
		}
		if (curf == 3) {
			return false;
		} else {
			return true;
		}

	}

	// 1ms
	public boolean isRobotBounded0(String instructions) {
		// 定义起始位置
		int x = 0;
		int y = 0;

		// 北 -R->东 +1
		// 东 -R->南 +1
		// 南 -R->西 +1
		// 西 -R->北 +1
		// L=RRR

		// 初始化方向为北
		int i = 0;
		// 定义方向:北0，东1，南2，西3
		int[][] d = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		for (char ch : instructions.toCharArray()) {
			switch (ch) {
			case 'R':
				i = (i + 1) % 4;
				break;
			case 'L':
				i = (i + 3) % 4;
				break;
			default:
				x += d[i][0];
				y += d[i][1];
			}
		}
		return (x == 0 && y == 0) || i > 0;
	}

}
