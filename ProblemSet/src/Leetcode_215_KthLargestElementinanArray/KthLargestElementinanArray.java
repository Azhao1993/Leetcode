package Leetcode_215_KthLargestElementinanArray;

import java.util.PriorityQueue;

/*
	在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
	
	示例 1:	
		输入: [3,2,1,5,6,4] 和 k = 2
		输出: 5
	
	示例 2:	
		输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
		输出: 4
	
	说明:	
		你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 */

/*
	思路：
		排序，找到第k个
	改进：
		只排到第K个
		——> 堆排
 */
public class KthLargestElementinanArray {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] nums = {3,2,3,1,2,4,5,5,6};
		int k = 4;
		KthLargestElementinanArray klea = new KthLargestElementinanArray();
		System.out.println(klea.findKthLargest(nums, k));

	}
	//215. 数组中的第K个最大元素
	
	
	//三路快排:超时
    public int findKthLargest(int[] nums, int k) {
    	//
    	Quick3way(nums,0,nums.length-1);
    	//返回第K大的元素
    	return nums[nums.length-k];
    }
    
    //三路快排
    public void Quick3way(int[] nums,int lo,int hi) {
    	//递归结束
    	if(hi<=lo) {
    		return ;
    	}
    	
    	int lt = lo;
    	int i = lo+1;//a[i]<v时，lt++，i++
    	int gt = hi;//a[i]>v时，gt--
    	int v = nums[lo];//基准
    	while(i<=gt) {
    		if(nums[i]<v) {
    			int temp = nums[i];
    			nums[i++] = nums[lt];
    			nums[lt++] = temp;
    		}else if(nums[i]>v) {
    			int temp = nums[i];
    			nums[i] = nums[gt];
    			nums[gt--] = temp;
    		}else {
    			i++;
    		}
    		Quick3way(nums,lo,lt-1);
    		Quick3way(nums,gt+1,hi);
    	}
    }

}
