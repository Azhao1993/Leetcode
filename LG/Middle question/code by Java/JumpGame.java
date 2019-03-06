package Leetcode_055_JumpGame;

/*
	给定一个非负整数数组，你最初位于数组的第一个位置。	
	数组中的每个元素代表你在该位置可以跳跃的最大长度。	
	判断你是否能够到达最后一个位置。	
	
	示例 1:	
		输入: [2,3,1,1,4]
		输出: true
		解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
	示例 2:	
		输入: [3,2,1,0,4]
		输出: false
		解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 */

//55.跳跃游戏
public class JumpGame {
	public boolean canJump(int[] nums) {
		// 最大能到的位置
		int max = 0;
		for (int i = 0; i < nums.length; i++) {
			// 当前位置不能到达
			if (i > max) {
				return false;
			}
			// 从i的位置能到大的最远的地方
			max = Math.max(nums[i] + i, max);
			if (max >= nums.length - 1) {
				return true;
			}
		}
		return true;
	}

	// 4ms
	public boolean canJump0(int[] nums) {
		int index = nums.length - 2;
		int min = nums.length - 1;
		while (index >= 0) {
			if (index + nums[index] >= min)
				min = index;
			index--;
		}
		return min == 0;
	}
}
