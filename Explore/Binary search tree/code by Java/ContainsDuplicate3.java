package Leetcode_220_ContainsDuplicate3;

import java.util.TreeSet;

/*
	缁欏畾涓�涓暣鏁版暟缁勶紝鍒ゆ柇鏁扮粍涓槸鍚︽湁涓や釜涓嶅悓鐨勭储寮� i 鍜� j锛�
	浣垮緱 nums [i] 鍜� nums [j] 鐨勫樊鐨勭粷瀵瑰�兼渶澶т负 t锛�
	骞朵笖 i 鍜� j 涔嬮棿鐨勫樊鐨勭粷瀵瑰�兼渶澶т负 k銆�
	
	绀轰緥 1:	
		杈撳叆: nums = [1,2,3,1], k = 3, t = 0
		杈撳嚭: true
		
	绀轰緥 2:	
		杈撳叆: nums = [1,0,1,1], k = 1, t = 2
		杈撳嚭: true
		
	绀轰緥 3:	
		杈撳叆: nums = [1,5,9,1,5,9], k = 2, t = 3
		杈撳嚭: false
 */

public class ContainsDuplicate3 {
	// 220. 存在重复元素 III

	public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
		// k>=|i-j|
		// t>=|nums[i]-nums[j]|
		if (nums == null || nums.length == 0 || k <= 0) {
			return false;
		}

		for (int i = 0; i < nums.length; i++) {
			for (int j = 1; j <= k && i + j < nums.length; j++) {
				long n1 = nums[i];
				long n2 = nums[i + j];
				if (Math.abs(n1 - n2) <= t) {
					return true;
				}
			}
		}
		return false;
	}
}
