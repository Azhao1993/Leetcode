package Leetcode_209_MinimumSizeSubarraySum;
/*
	给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
	
	示例: 	
		输入: s = 7, nums = [2,3,1,2,4,3]
		输出: 2
		解释: 
			子数组 [4,3] 是该条件下的长度最小的连续子数组。
	进阶:	
		如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 */
public class MinimumSizeSubarraySum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	//209. 长度最小的子数组
    public int minSubArrayLen(int s, int[] nums) {
        //暴力算法
    	int minlength=Integer.MAX_VALUE;
    	for(int i = 0;i<nums.length;i++) {
    		int sum = 0;
    		int count = 0;
    		for(int j = i;j<nums.length;j++) {    			
    			if(sum<s) {
    				sum += nums[j];
    				count++;
    			}
    			if(sum >= s) {
    				minlength = Math.min(minlength, count);
    				continue;
    			}
    			
    		}    		
    	}
    	if(minlength==Integer.MAX_VALUE) {
    		return 0;
    	}
    	return minlength;
    }

}
