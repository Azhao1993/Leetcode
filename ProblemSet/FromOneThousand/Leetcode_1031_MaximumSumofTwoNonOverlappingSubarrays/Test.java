package Leetcode_1031_MaximumSumofTwoNonOverlappingSubarrays;

public class Test {

	public static void main(String[] args) {
		MaximumSumofTwoNonOverlappingSubarrays mstnos = new MaximumSumofTwoNonOverlappingSubarrays();
		int[] A = {0,6,5,2,2,5,1,9,4};
		int L=1;
		int M=2;
		System.out.println(mstnos.maxSumTwoNoOverlap(A, L, M));
	}

}
