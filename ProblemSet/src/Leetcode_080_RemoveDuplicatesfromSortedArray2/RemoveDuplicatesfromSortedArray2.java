package Leetcode_080_RemoveDuplicatesfromSortedArray2;

/*
	给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
	不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
	
	示例 1:
		给定 nums = [1,1,1,2,2,3],
		函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
		你不需要考虑数组中超出新长度后面的元素。
	
	示例 2:
		给定 nums = [0,0,1,1,1,1,2,3,3],	
		函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。	
		你不需要考虑数组中超出新长度后面的元素。
		
	说明:
		为什么返回数值是整数，但输出的答案是数组呢?
		请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
	你可以想象内部操作如下:
		// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
		int len = removeDuplicates(nums);
		
		// 在函数里修改输入数组对于调用者是可见的。
		// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
		for (int i = 0; i < len; i++) {
		    print(nums[i]);
		}
 */
public class RemoveDuplicatesfromSortedArray2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RemoveDuplicatesfromSortedArray2 rdfsa2 = new RemoveDuplicatesfromSortedArray2();
		int[] nums = { 1, 2, 2 };
		rdfsa2.removeDuplicates(nums);
	}

	// 80. 删除排序数组中的重复项 II
	public int removeDuplicates(int[] nums) {
		if (nums.length <= 2) {
			return nums.length;
		}
		int i = 0;
		int j = 1;
		int count = 1;
		int length = 0;
		while (i < nums.length - length - 1) {
			if (nums[j] == nums[j - 1]) {
				count++;
			} else {
				count = 1;
			}
			// 判断是否大于2
			if (count > 2) {
				move(nums, j);
				length++;
			} else {
				j++;
				i++;
			}

		}
		return nums.length - length;

	}

	// 向前移动
	public void move(int[] nums, int i) {
		for (int j = i + 1; j < nums.length; j++) {
			nums[j - 1] = nums[j];
		}
	}

	// 明确变量定义，循环不变量
	public int removeDuplicates2(int[] nums) {
		int k = 0;// [0,k]表示不包含重复数字的范围
		int count = 1;// count表示nums[k]出现的次数
		for (int i = 1; i < nums.length; i++) {
			if (nums[i] != nums[k]) {
				count = 1;
				nums[++k] = nums[i];
			} else if (count < 2) {
				nums[++k] = nums[i];
				count++;
			}
		}
		return k + 1;
	}

}
