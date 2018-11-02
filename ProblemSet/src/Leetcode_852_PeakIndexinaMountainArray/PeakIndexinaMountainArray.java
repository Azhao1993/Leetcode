package Leetcode_852_PeakIndexinaMountainArray;
/*
	我们把符合下列属性的数组 A 称作山脉：
	
	A.length >= 3
	存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
	给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1] 的 i 的值。
		
	示例 1：	
		输入：[0,1,0]
		输出：1
	示例 2：	
		输入：[0,2,1,0]
		输出：1
	 
	提示：	
		3 <= A.length <= 10000
		0 <= A[i] <= 10^6
		A 是如上定义的山脉
*/
public class PeakIndexinaMountainArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	//852. 山脉数组的峰顶索引
	//二分查找
	public int peakIndexInMountainArray(int[] A) {
		int left = 1;
		int right = A.length-1;
		while(left<right) {
			int mid = left+(right-left)/2;
			if((A[mid]>A[mid-1])&&(A[mid]>A[mid+1])) {
				return mid;
			}else if((A[mid]>A[mid-1])&&(A[mid]<A[mid+1])){
				//mid-1<mid<mid+1,在右边
				left = mid;				
			}else {
				right = mid;
			}
		}
		return left;
	}
	//直接搜索
    public int peakIndexInMountainArray2(int[] A) {
    	
        //直接搜索最大值
    	int maxindex = 0;
    	for(int i = 1;i<A.length;i++) {
    		if(A[maxindex]<A[i]) {
    			maxindex = i;
    		}
    	}
    	return maxindex;
    }

}
