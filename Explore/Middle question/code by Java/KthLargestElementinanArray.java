package Leetcode_215_KthLargestElementinanArray;

import UsualMethod.ArrayUtil;

/*
	在未排序的数组中找到第 k 个最大的元素。
	请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
	
	示例 1:	
		输入: [3,2,1,5,6,4] 和 k = 2
		输出: 5
	
	示例 2:	
		输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
		输出: 4
	
	说明:	
		你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 */
public class KthLargestElementinanArray {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		KthLargestElementinanArray klea = new KthLargestElementinanArray();
		int[] nums = {3,2,3,1,2,4,5,5,6};
		int k = 4;
		System.out.println(klea.findKthLargest(nums, k));
	}
	
	//215. 数组中的第K个最大元素
    public int findKthLargest(int[] nums, int k) {
        Quick3way(nums,0,nums.length-1,k);
        return nums[nums.length-k];
    }
    
    //三路排序
    public void Quick3way(int[] nums,int left,int right,int k) {
    	
    	if(right<=left) {
    		return;
    	}
    	
    	int val = nums[left];//基准    	
    	int l = left;//遇到小的往左边放，l++,i++    	
    	int i = left+1;//当前比较位置
    	int r = right;//遇到大的往右边放，right--
    	//
    	while(i<=r) {
    		if(nums[i]<val) {
    			//交换
    			ArrayUtil.exchange(nums,i,l);
    			//exchange(nums,i,l);
    			i++;
    			l++;
    		}else if(nums[i]>val) {
    			ArrayUtil.exchange(nums,i,r);
    			//exchange(nums,i,r);
    			r--;
    		}else {
    			i++;
    		}   		
    				
    	}
    	//此时将数组分为三段
		//left - l-1 \ l - r \ r+1 - right
		//判断k在的位置
		//第1段
		if(k>right-l+1) {
			Quick3way(nums,left,l-1,k-(right-l+1));
		}else if(k>=right-r+1) {
			return ;
		}else {
			Quick3way(nums,r+1,right,k);
		}    
    	
    	
    }
    

}
