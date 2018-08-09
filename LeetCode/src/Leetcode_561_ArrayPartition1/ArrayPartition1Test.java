package Leetcode_561_ArrayPartition1;

public class ArrayPartition1Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayPartition1 ap = new ArrayPartition1();
		int[] nums = { 1, 4, 3, 2 };
		System.out.println(ap.arrayPairSum(nums));
		// 一维输出的输出
		for (int i = 0; i < nums.length; i++) {
			if (i != nums.length - 1) {
				System.out.print(nums[i] + ",");
			} else {
				System.out.println(nums[i]);
			}

		}
	}

}
