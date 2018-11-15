package Leetcode_038_CountandSay;

/*
	报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
	
	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
	1 被读作  "one 1"  ("一个一") , 即 11。
	11 被读作 "two 1s" ("两个一"）, 即 21。
	21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
	
	给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
	
	注意：整数顺序将表示为一个字符串。
	
	示例 1:	
		输入: 1
		输出: "1"
	示例 2:	
		输入: 4
		输出: "1211"
 */
public class CountandSay {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CountandSay cs = new CountandSay();
		System.out.println(cs.countAndSay(3));
	}

	// 38. 报数
	public String countAndSay(int n) {
		// n=1
		if (n == 1) {
			return "1";
		}
		// n>=2
		String str = "11";
		char[] charr = str.toCharArray();
		while (n > 2) {
			StringBuilder sb = new StringBuilder();
			int count = 1;
			for (int i = 1; i < charr.length; i++) {
				// 与前一个相比
				if (charr[i - 1] == charr[i]) {
					//相等，count++
					count++;
				}else {
					//不相等,增加个数和数字，计数器归零
					sb.append(count).append(charr[i-1]);
					count = 1;
				}
				//如果最后一个数字，缓冲器增加个数和数字
				if(i==charr.length-1) {
					sb.append(count).append(charr[i]);
				}
			}
			//将缓冲器存入数组
			charr = sb.toString().toCharArray();
			n--;
		}
		
		return String.valueOf(charr);
	}

}
