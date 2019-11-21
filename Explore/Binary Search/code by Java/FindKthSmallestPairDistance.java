package Leetcode_719_FindKthSmallestPairDistance;

import java.util.Arrays;

/*
	给定一个整数数组，返回所有数对之间的第 k 个最小距离。
	一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
	
	示例 1:	
		输入：
			nums = [1,3,1]
			k = 1
		输出：0 
		解释：
			所有数对如下：
			(1,3) -> 2
			(1,1) -> 0
			(3,1) -> 2
			因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
	提示:	
		2 <= len(nums) <= 10000.
		0 <= nums[i] < 1000000.
		1 <= k <= len(nums) * (len(nums) - 1) / 2.
*/
public class FindKthSmallestPairDistance {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FindKthSmallestPairDistance fspd = new FindKthSmallestPairDistance();
		int[] nums = { 1, 3, 1 };
		int k = 3;
		System.out.println(fspd.smallestDistancePair(nums, k));
	}

	// 719. 找出第 k 小的距离对
	public int smallestDistancePair(int[] nums, int k) {
		// 首先排序
		Arrays.sort(nums);
		// n是数组的长度
		int n = nums.length;
		// 二分查找，
		// 找到距离<=mid的个数cnt,
		// cnt>=k,需要缩小距离right=mid
		// right是第k个距离
		int left = 0;
		// right 为最大差值，最后一个数字减第一个
		int right = nums[n - 1] - nums[0];

		while (left < right) {
			// mid为最大距离与最小距离的中间值
			int mid = left + (right - left) / 2;
			// 记录小于等于mid的距离个数
			int cnt = 0;
			// start是较小数字的位置
			int start = 0;
			// 遍历数组，比较与较小数字的距离和mid的大小
			for (int i = 0; i < n; i++) {
				while (start < n && nums[i] - nums[start] > mid) {
					// 距离大于mid,较小数字右移
					start++;
				}
				// 距离小于等于mid,cnt计数
				cnt += (i - start);
			}
			// cnt比k小，在右边
			if (cnt < k) {
				left = mid + 1;
			} else {
				// 在左边
				right = mid;
			}
		}
		//为什么right值就是第k个最小距离？
		return right;
	}

}
