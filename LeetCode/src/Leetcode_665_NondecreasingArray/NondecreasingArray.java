package Leetcode_665_NondecreasingArray;

/*
	给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。	
	我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。
	
	示例 1:	
		输入: [4,2,3]
		输出: True
		解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
		
	示例 2:	
		输入: [4,2,1]
		输出: False
		解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
	说明:  n 的范围为 [1, 10,000]。
*/
public class NondecreasingArray {
	public boolean checkPossibility(int[] nums) {
		// 获取数组长度
		int length = nums.length;
		// 计数器
		int count = 0;
		// 遍历数组
		/*
		从两头往中间找，找出断点的位置		 
		*/
		int i = 0;
		int j = length-1;
		while((i<j)&&(nums[i]<=nums[i+1])) {
			i++;
		}
		while((i<j)&&nums[j]>=nums[j-1]) {
			j--;
		}
		System.out.println("i:"+i+",j:"+j);
		if(j-i<=1) {
			if((i==0)|| (j==length-1)){
				return true;
			}
			if((nums[i-1]<=nums[j])|(nums[i]<=nums[j+1])){
				return true;
			}
		}
		return false;
	}
}
