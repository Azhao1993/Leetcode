package Leetcode_169_MajorityElement;

public class MajorityElementTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MajorityElement me = new MajorityElement();
		int[] nums = {2,2};
		//System.out.println(nums[nums.length/2]);
		//me.majorityElement(nums);
		System.out.println(me.majorityElement(nums));
		// Êä³öÊý×é
		for (int j = 0; j < nums.length; j++) {
			System.out.print(nums[j]+",");
		}
	}

}
