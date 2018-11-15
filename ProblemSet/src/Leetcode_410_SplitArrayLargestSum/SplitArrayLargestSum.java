package Leetcode_410_SplitArrayLargestSum;

/*
	给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
	
	注意:
		数组长度 n 满足以下条件:	
		1 ≤ n ≤ 1000
		1 ≤ m ≤ min(50, n)
	示例:	
		输入:
			nums = [7,2,5,10,8]
			m = 2		
		输出:
			18		
	解释:
		一共有四种方法将nums分割为2个子数组。
		其中最好的方式是将其分为[7,2,5] 和 [10,8]，
		因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
*/
public class SplitArrayLargestSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SplitArrayLargestSum sals = new SplitArrayLargestSum();
		int[] nums = { 7, 2, 5, 10, 8 };
		int m = 2;
		System.out.println(sals.splitArray(nums, m));

	}

	// 410. 分割数组的最大值
	public int splitArray(int[] nums, int m) {
		int low = nums[0];
		int high = nums[0];
		for (int i = 1; i < nums.length; i++) {
			// 所有数字的和
			high += nums[i];
			// 最大的数
			low = Math.max(low, nums[i]);
		}
		// 二分查找，找到子数组中和最大值的最小情况
		while (low < high) {
			//用来确定是否能被分组
			int mid = low + (high - low) / 2;
			// 如果能被分组
			if (can_split(nums, mid, m)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		return low;
	}
	//为什么？
	public boolean can_split(int[] nums, int mid, int m) {
		int sum = 0;
		int cnt = 1;
		for (int i = 0; i < nums.length; i++) {
			sum += nums[i];
			// 大于当前mid中值，需要重新分一组，cnt++
			if (sum > mid) {
				sum = nums[i];
				cnt++;
				if (cnt > m) {
					return false;
				}
			}
		}
		return true;
	}

}
