package Contest_College_2019_spring;

/*
	给定一个数字 N，当它满足以下条件的时候返回 true：	
	把原数字旋转180°以后得到新的数字。	
	如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。	
	2, 3, 4, 5, 7 旋转 180° 后,得到的不是数字。
	
	易混淆数字 (confusing number) 就是一个数字旋转180°以后，得到和原来不同的数字，且新数字的每一位都是有效的。	 
	
	示例 1：	
		输入：6
		输出：true
		解释： 
			把 6 旋转 180° 以后得到 9，9 是有效数字且 9!=6 。
	示例 2：	
		输入：89
		输出：true
		解释: 
			把 89 旋转 180° 以后得到 68，86 是有效数字且 86!=89 。
	示例 3：	
		输入：11
		输出：false
		解释：
			把 11 旋转 180° 以后得到 11，11 是有效数字但是值保持不变，所以 11 不是易混淆数字。 
	示例 4：	
		输入：25
		输出：false
		解释：
			把 25 旋转 180° 以后得到的不是数字。
	 
	
	提示：	
		0 <= N <= 10^9
		可以忽略掉旋转后得到的前导零，例如，如果我们旋转后得到 0008 那么该数字就是 8 。
 */
public class ConfusingNumber {
	public static void main(String[] args) {
		for (int i = 0; i < 1000; i++) {
			System.out.println(i + ":" + confusingNumber(i));
		}
	}

	public static boolean confusingNumber(int N) {
		if (N == 0) {
			return false;
		}
		int old = N;
		int temp = 0;
		while (old != 0) {
			int cur = old % 10;
			if (cur == 2 || cur == 3 || cur == 4 || cur == 5 || cur == 7) {
				return false;
			}
			if (cur == 6) {
				temp = temp * 10 + 9;// 6->9
			} else if (cur == 9) {
				temp = temp * 10 + 6;// 9->6
			} else {
				temp = temp * 10 + cur;// 1,8保持不变
			}
			old /= 10;
		}

		return temp != N;
	}

}
