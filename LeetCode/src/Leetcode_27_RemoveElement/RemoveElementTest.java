package Leetcode_27_RemoveElement;

public class RemoveElementTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RemoveElement re = new RemoveElement();
		int[] nums = {3,2,2,3};
		//输出数组
		for (int i = 0; i < nums.length; i++) {
			if (i != nums.length - 1) {
				System.out.print(nums[i] + ",");
			} else {
				System.out.println(nums[i]);
			}
		}
		int val = 3;
		int length = re.removeElement(nums, val);		
		System.out.println("新数组的长度是"+length);
		//输出数组
		for (int i = 0; i < length; i++) {
			if (i != length - 1) {
				System.out.print(nums[i] + ",");
			} else {
				System.out.println(nums[i]);
			}
		}
	}

}
