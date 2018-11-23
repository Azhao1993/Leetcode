package Leetcode_088_MergeSortedArray;

import UsualMethod.ArrayUtil;

/*

	给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

	说明:	
		初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
		你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
		示例:
	
	输入:
		nums1 = [1,2,3,0,0,0], m = 3
		nums2 = [2,5,6],       n = 3	
	输出: [1,2,2,3,5,6]
*/
public class MergeSortedArray {
	
	public static void main(String[] args) {
		MergeSortedArray msa = new MergeSortedArray();
		int[] nums1 = {4,5,6,0,0,0};
		int m = 3;
		int[] nums2 = {1,2,3};
		int n = 3;
		msa.merge(nums1, m, nums2, n);
	}
	// 88.合并两个有序数组
	public void merge(int[] nums1, int m, int[] nums2, int n) {
		for(int i = m;i<nums1.length;i++) {			
			nums1[i] = nums2[i-m];
			int j = i;
			while((m>0)&&(j>0)&&(nums1[j]<nums1[j-1])) {
				ArrayUtil.exchange(nums1, j, j-1);
				j--;
			}
		}
	}
	
	
	//冒泡排序
	public void merge2(int[] nums1, int m, int[] nums2, int n) {
		// 将两个数组重新放在一起重新排序
		for (int i = 0; i < n; i++) {
			nums1[m + i] = nums2[i];
		}
		for (int i = 1; i < nums1.length; i++) {
			for (int j = 0; j < i; j++) {
				if (nums1[i] < nums1[j]) {
					int temp = nums1[i];
					nums1[i] = nums1[j];
					nums1[j] = temp;
				}
			}
		}
	}
}
