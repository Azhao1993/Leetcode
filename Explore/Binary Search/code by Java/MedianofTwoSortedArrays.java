package Leetcode_004_MedianofTwoSortedArrays;

import Leetcode_448_FindAllNumbersDisappearedinanArray.FindAllNumbersDisappearedinanArray;

/*
	给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
	请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
	你可以假设 nums1 和 nums2 不同时为空。
	
	示例 1:
		nums1 = [1, 3]
		nums2 = [2]
		中位数是 2.0
		
	示例 2:
		nums1 = [1, 2]
		nums2 = [3, 4]
		中位数是 (2 + 3)/2 = 2.5
*/
public class MedianofTwoSortedArrays {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums1 = { 1,3 };
		int[] nums2 = { 2};
		MedianofTwoSortedArrays mtsa = new MedianofTwoSortedArrays();
		System.out.println(mtsa.findMedianSortedArrays(nums1, nums2));
	}

	// 4.两个排序数组的中位数
	/*
	 * 思路： 两个数组的长度和（size） 如果是偶数，应该找到第size/2和第size/2+1个数，进行求平均
	 * 如果是奇数，应该找到第size/2+1个数，就是中位数 问题转化为：找到双数组中的第k个数 从两个数组中分别取出前k/2个数。
	 * 比较其最大值，小的那一组，一定属于前k个数。 特殊情况：
	 * 较短的一组已经全部加在前k个数中，此时len1-start1==0,第k个为nums2[k-1]; 如果k ==
	 * 1,则表示前k-1小的数已经找过了，则第k个数肯定是nums1[start1]和nums2[start2]中较小的那个数。
	 *  
	 */
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		// 获取nums1的长度
		int length1 = nums1.length;
		// 获取nums2的长度
		int length2 = nums2.length;
		// 总长度
		int size = length1 + length2;
		// 总长度为偶数
		if (size % 2 == 0) {
			// 总长度为偶数
			return (findKth(nums1, 0, length1, nums2, 0, length2, size / 2) + findKth(nums1, 0, length1, nums2, 0, length2, size / 2 + 1)) / 2;
		} else {
			// 总长度为奇数
			return findKth(nums1, 0, length1, nums2, 0, length2, size / 2 + 1);
		}
	}

	public double findKth(int[] nums1, int start1, int len1, int[] nums2, int start2, int len2, int k) {
		// 保证较短的在前面
		if (len1 - start1 > len2 - start2) {
			return findKth(nums2, start2, len2, nums1, start1, len1, k);
		}
		// len1-start1==0,第k个为nums2[k-1];
		if (len1 - start1 == 0) {
			return nums2[k - 1];
		}
		// k==1
		if (k == 1) {
			return Math.min(nums1[start1], nums2[start2]);
		}
		// 需要比较的位,p1=start1+k/2,p2=start2+k-k/2
		int p1 = start1 + Math.min(len1 - start1, k / 2);// 防止nums1过短
		int p2 = start2 + k - (p1 - start1);
		if (nums1[p1 - 1] > nums2[p2 - 1]) {
			return findKth(nums1, start1, len1, nums2, p2, len2, k - p2 + start2);
		} else if (nums1[p1 - 1] < nums2[p2 - 1]) {
			return findKth(nums1, p1, len1, nums2, start2, len2, k - p1 + start1);
		} else {
			return nums1[p1 - 1];
		}
	}

}
