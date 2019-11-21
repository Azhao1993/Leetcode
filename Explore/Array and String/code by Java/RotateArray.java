package Leetcode_189_RotateArray;

/*

	给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

	示例 1:	
		输入: [1,2,3,4,5,6,7] 和 k = 3
		输出: [5,6,7,1,2,3,4]
		解释:
		向右旋转 1 步: [7,1,2,3,4,5,6]
		向右旋转 2 步: [6,7,1,2,3,4,5]
		向右旋转 3 步: [5,6,7,1,2,3,4]
		
	示例 2:	
		输入: [-1,-100,3,99] 和 k = 2
		输出: [3,99,-1,-100]
		解释: 
		向右旋转 1 步: [99,-1,-100,3]
		向右旋转 2 步: [3,99,-1,-100]
		
	说明:	
		尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
		要求使用空间复杂度为 O(1) 的原地算法。
*/
public class RotateArray {
	// 189. 旋转数组
	// 算法1
	public void rotate(int[] nums, int k) {

		// 获取数组的长度
		int length = nums.length;
		if (k > length) {
			for (int i = 0; i < k; i++) {
				// 旋转1位
				int temp = nums[length - 1];
				for (int j = length - 1; j > 0; j--) {
					nums[j] = nums[j - 1];
				}
				nums[0] = temp;
			}
		} else {
			// 整体翻转
			for (int i = 0; i < length / 2; i++) {
				int temp = nums[i];
				nums[i] = nums[length - 1 - i];
				nums[length - 1 - i] = temp;
			}
			// 前k个翻转
			for (int i = 0; i < k / 2; i++) {
				int temp = nums[i];
				nums[i] = nums[k - 1 - i];
				nums[k - 1 - i] = temp;
			}
			// 后面nums.length-k个旋转
			for (int i = k; i < (k + length) / 2; i++) {
				int temp = nums[i];
				nums[i] = nums[length - 1 + k - i];
				nums[length - 1 + k - i] = temp;
			}
		}

	}

	// 算法2
	public void rotate2(int[] nums, int k) {

	}

	// 算法3
	public void rotate3(int[] nums, int k) {

	}
}
