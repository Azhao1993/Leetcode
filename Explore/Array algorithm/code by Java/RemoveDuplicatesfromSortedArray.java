package Leetcode_026_RemoveDuplicatesfromSortedArray;

/*

	给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
	不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
	
	示例 1:	
		给定数组 nums = [1,1,2], 		
		函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。		
		你不需要考虑数组中超出新长度后面的元素。
		
	示例 2:	
		给定 nums = [0,0,1,1,1,2,2,3,3,4],		
		函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。		
		你不需要考虑数组中超出新长度后面的元素。
*/
public class RemoveDuplicatesfromSortedArray {
	//26.删除排序数组中的重复项
	public int removeDuplicates(int[] nums) {
		if (nums.length <= 1) {
			return nums.length;
		}
		// 定义不重复元素个数
		int count = 0;
		// 定义比较元素
		int now = nums[0];
		// 遍历数组
		for (int i = 1; i < nums.length; i++) {
			// 判断是否与now相同
			if (now != nums[i]) {
				// 不同，计数加1，现在比较器改变，对应的位置换成当前的值
				count++;
				now = nums[i];
				nums[count] = nums[i];
			}
		}
		count++;
		return count;
	}
}
