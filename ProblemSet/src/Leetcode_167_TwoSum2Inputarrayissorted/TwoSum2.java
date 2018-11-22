package Leetcode_167_TwoSum2Inputarrayissorted;



/*

	给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
	函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
	
	说明:	
		返回的下标值（index1 和 index2）不是从零开始的。
		你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
		
	示例:	
		输入: numbers = [2, 7, 11, 15], target = 9
		输出: [1,2]
		解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

*/

public class TwoSum2 {

	public static void main(String[] args) {
		
	}

	// 167. 两数之和 II - 输入有序数组
	public int[] twoSum1(int[] numbers, int target) {

		int[] sum = new int[2];
		for (int i = 1; i < numbers.length; i++) {
			sum[1] = i + 1;
			for (int j = 0; j < i; j++) {
				if (numbers[i] + numbers[j] == target) {
					sum[0] = j + 1;
					return sum;
				}
			}
		}
		return sum;
	}

	// 二分查找
	public int[] twoSum(int[] numbers, int target) {
		// 定义结果数组
		int[] result = new int[2];
		// 从第2个数字开始遍历最大索引
		for (int i = 1; i < numbers.length; i++) {
			// 记录大索引位置
			result[1] = i + 1;
			// 二分查找小索引
			int left = 0;
			int right = i - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (numbers[mid] + numbers[i] == target) {
					result[0] = mid + 1;
					return result;
				} else if (numbers[mid] + numbers[i] > target) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
		}
		return result;
	}
}
