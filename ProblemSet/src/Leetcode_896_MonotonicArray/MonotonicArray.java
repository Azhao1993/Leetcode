package Leetcode_896_MonotonicArray;

import java.util.Arrays;

/*
	如果数组是单调递增或单调递减的，那么它是单调的。
	如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 
	如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。
	
	当给定的数组 A 是单调数组时返回 true，否则返回 false。
	示例 1：
		输入：[1,2,2,3]
		输出：true
	示例 2：
		输入：[6,5,4,4]
		输出：true
	示例 3：
		输入：[1,3,2]
		输出：false
	示例 4：
		输入：[1,2,4,5]
		输出：true
	示例 5：
		输入：[1,1,1]
		输出：true
	提示：
		1 <= A.length <= 50000
		-100000 <= A[i] <= 100000
*/
public class MonotonicArray {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		MonotonicArray ma = new MonotonicArray();
		int[] A = {1,3,2};
		System.out.println(ma.isMonotonic(A));
	}
	//896.单调数列
    public boolean isMonotonic(int[] A) {
        //用i+1-i赋值给i
    	//用i和i+1相乘<0返回错误
    	int[] B = new int[A.length];
    	int index =0 ;
    	for(int i = 0;i<A.length-1;i++) {
    		A[i] = A[i+1]-A[i];
    		if(A[i]!=0) {
    			B[index] = A[i];    			
    			if(index>0) {
    				if(B[index-1]*B[index]<0) {
    					return false;
    				}
    			}
    			index++;
    		}
    		
    	}    	
    	return true;
    }

}
