package Leetcode_581_ShortestUnsortedContinuousSubarray;

/*
	给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
	你找到的子数组应是最短的，请输出它的长度。
	
	示例 1:	
		输入: [2, 6, 4, 8, 10, 9, 15]
		输出: 5
		解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
		
	说明 :	
		输入的数组长度范围在 [1, 10,000]。
		输入的数组可能包含重复元素 ，所以升序的意思是<=。
*/
public class ShortestUnsortedContinuousSubarray {
	
	public int findUnsortedSubarray(int[] nums) {
		// 获取数组的长度
		int length = nums.length;
		if(length<=1) {
			return 0;
		}
		// 定义需要排序开始的索引
		int beginindex = 0;
		
		// 遍历数组，从开始遍历，依次判断是不是比后面的都小
		begin: for (int i = 0; i < length - 1; i++) {
			for (int j = i + 1; j < length; j++) {
				if (nums[i] > nums[j]) {
					beginindex = i;					
					break begin;
				}
			}
		}
		//System.out.println("beginindex:"+beginindex);		
		// 从后面遍历，依次判断是不是比前面的（需要开始排序开始的索引）都大
		int endindex = 0;
		end: for (int i = length - 1; i >= beginindex; i--) {
			for (int j = i - 1; j >= 0; j--) {
				if (nums[i] < nums[j]) {
					endindex = i;
					break end;
				}
			}
		}
		//System.out.println("endindex:"+endindex);
		if((beginindex==0)&(endindex==0)) {
			return 0;
		}
		return endindex - beginindex + 1;
	}
}
