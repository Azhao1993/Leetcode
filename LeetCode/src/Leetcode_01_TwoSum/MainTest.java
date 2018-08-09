package Leetcode_01_TwoSum;

public class MainTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 创建对象
		TwoSum ts = new TwoSum();
		int[] nums = new int[] { 2, 7, 7, 15 };
		int target = 9;
		int[] result = ts.twoSum(nums, target);
		System.out.println(result[0]+","+result[1]);
	}

}
