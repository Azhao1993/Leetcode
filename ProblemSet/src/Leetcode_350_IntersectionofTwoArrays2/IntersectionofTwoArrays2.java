package Leetcode_350_IntersectionofTwoArrays2;

import java.util.Arrays;



/*
	给定两个数组，编写一个函数来计算它们的交集。
	
	示例 1:	
		输入: nums1 = [1,2,2,1], nums2 = [2,2]
		输出: [2,2]
	示例 2:	
		输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
		输出: [4,9]
	说明：	
		输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
		我们可以不考虑输出结果的顺序。
	进阶:	
		如果给定的数组已经排好序呢？你将如何优化你的算法？
		如果 nums1 的大小比 nums2 小很多，哪种方法更优？
		如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/
public class IntersectionofTwoArrays2 {

	public static void main(String[] args) {
		
	}

	// 350. 两个数组的交集 II
	public int[] intersect(int[] nums1, int[] nums2) {
		// nums2大nums1小
		int length1 = nums1.length;
		int length2 = nums2.length;
		if (length1 > length2) {
			return intersect(nums2, nums1);
		}
		// 数组是排序的
		Arrays.sort(nums1);
		Arrays.sort(nums2);
		int i = 0;
		int j = 0;
		int count = 0;
		// 遍历小数组
		for (; i < length1; i++) {
			// 遍历查找
			for (; j < length2; j++) {
				if (nums1[i] == nums2[j]) {
					nums1[count++] = nums2[j];
					j++;
					break;
				}
				if (nums1[i] < nums2[j]) {
					break;
				}

			}
		}
		// 存入数组
		int[] result = new int[count];
		for (int x = 0; x < count; x++) {
			result[x] = nums1[x];
		}
		return result;

	}

}
