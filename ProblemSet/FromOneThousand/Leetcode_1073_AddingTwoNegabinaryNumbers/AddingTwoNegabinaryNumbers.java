package Leetcode_1073_AddingTwoNegabinaryNumbers;

/*
	给出基数为 -2 的两个数 arr1 和 arr2，返回两数相加的结果。	
	数字以 数组形式 给出：数组由若干 0 和 1 组成，按最高有效位到最低有效位的顺序排列。
	例如，arr = [1,1,0,1] 表示数字 (-2)^3 + (-2)^2 + (-2)^0 = -3。
	数组形式 的数字也同样不含前导零：以 arr 为例，这意味着要么 arr == [0]，要么 arr[0] == 1。
	
	返回相同表示形式的 arr1 和 arr2 相加的结果。两数的表示形式为：不含前导零、由若干 0 和 1 组成的数组。	 
	
	示例：	
		输入：arr1 = [1,1,1,1,1], arr2 = [1,0,1]
		输出：[1,0,0,0,0]
		解释：arr1 表示 11，arr2 表示 5，输出表示 16 。 
	
	提示：	
		1 <= arr1.length <= 1000
		1 <= arr2.length <= 1000
		arr1 和 arr2 都不含前导零
		arr1[i] 为 0 或 1
		arr2[i] 为 0 或 1
 */

//1073.负二进制数相加
public class AddingTwoNegabinaryNumbers {
	public static void main(String[] args) {
		int[] arr1 = { 1, 1, 1, 1, 1 };
		int[] arr2 = { 1, 0, 1 };
		new AddingTwoNegabinaryNumbers().addNegabinary(arr1, arr2);
	}

	public int[] addNegabinary(int[] arr1, int[] arr2) {
		int length = Math.max(arr1.length, arr2.length);
		int[] res = new int[length + 2];
		for (int i = 0; i < res.length; i++) {
			int a = arr1.length - 1 - i < 0 ? 0 : arr1[arr1.length - 1 - i];
			int b = arr2.length - 1 - i < 0 ? 0 : arr2[arr2.length - 1 - i];
			int temp = a + b + res[res.length - 1 - i];
			if (temp == -1) {
				// 低位有进位，且当前位a+b=0
				res[res.length - 2 - i] += 1;// 向高位借位
				res[res.length - 1 - i] = 1;
			} else if (temp >= 2) {
				// 低位或有借位，a+b==2
				res[res.length - 2 - i] -= 1;// 向高位进位
				res[res.length - 1 - i] = temp - 2;
			} else {
				// 0,1
				res[res.length - 1 - i] = temp;
			}
		}
		// 去掉前导位0
		length = res.length;
		for (int i = 0; i < res.length; i++) {
			if (res[i] == 1) {
				break;
			} else {
				length--;
			}
		}
		if (length == res.length) {
			return res;
		}
		if (length == 0) {
			return new int[] { 0 };
		}
		int[] result = new int[length];
		for (int i = 0; i < length; i++) {
			result[i] = res[res.length - length + i];
		}
		return result;
	}
}
