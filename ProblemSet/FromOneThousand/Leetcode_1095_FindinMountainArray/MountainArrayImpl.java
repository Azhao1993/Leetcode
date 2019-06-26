package Leetcode_1095_FindinMountainArray;

public class MountainArrayImpl implements MountainArray {
	int[] MountainArray;

	public MountainArrayImpl(int[] array) {
		MountainArray = array;
	}

	@Override
	public int get(int index) {
		// TODO Auto-generated method stub
		return MountainArray[index];
	}

	@Override
	public int length() {
		// TODO Auto-generated method stub
		return MountainArray.length;
	}

}
