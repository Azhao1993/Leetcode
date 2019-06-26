package Leetcode_283_MoveZeroes;

/*
	给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

	示例:	
		输入: [0,1,0,3,12]
		输出: [1,3,12,0,0]
	说明:	
		必须在原数组上操作，不能拷贝额外的数组。
		尽量减少操作次数。
*/
public class MoveZeroes {
	// 283. 移动零
	public void moveZeroes(int[] nums) {
		// 统计零的个数
		int count = 0;
		// 遍历数组，删除0
		int length = nums.length;
		for (int i = 0; i < length; i++) {
			if (nums[i] == 0) {
				count++;
			} else {
				nums[i - count] = nums[i];
			}
		}

		// 补充数组
		for (int i = length - count; i < length; i++) {
			nums[i] = 0;
		}
	}

	// 明确变量定义，循环不变量
	public void moveZeroes2(int[] nums) {
		// 明确变量定义
		int i = 0;// 小索引
		int j = 0;// 大索引
		// 循环不变量
		while (j < nums.length) {
			if (nums[j] == 0) {
				j++;
			} else {
				nums[i++] = nums[j++];
			}
		}
		while (i < nums.length) {
			nums[i++] = 0;
		}
	}

	public void moveZeroes3(int[] nums) {
		// 明确变量定义
		int i = 0;// 小索引
		int j = 0;// 大索引
		// 循环不变量
		int temp;
		while (j < nums.length) {
			if (nums[j] != 0) {
				temp = nums[i];
				nums[i++] = nums[j];
				nums[j] = temp;
			}
			j++;
		}

	}
}
