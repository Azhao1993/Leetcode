package Leetcode_658_FindKClosestElements;

import java.util.Arrays;

/*
	给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。
	返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
	
	示例 1:	
		输入: [1,2,3,4,5], k=4, x=3
		输出: [1,2,3,4]	 
	
	示例 2:	
		输入: [1,2,3,4,5], k=4, x=-1
		输出: [1,2,3,4]	 
	
	说明:	
		k 的值为正数，且总是小于给定排序数组的长度。
		数组不为空，且长度不超过 10^4
		数组里的每个元素与 x 的绝对值不超过 10^4
*/
public class FindKClosestElements {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FindKClosestElements fce = new FindKClosestElements();
		int[] arr = {1,2,3,4,5};
		int k = 4;
		int x = 5;
		System.out.println(Arrays.toString(fce.findClosestElements(arr, k, x)));
	}

	// 658. 找到 K 个最接近的元素
	public int[] findClosestElements(int[] arr, int k, int x) {
		int[] result = new int[k];
		int count = 0;
		int left = 0;
		int right = arr.length - 1;	
		int mid = 0;
		
		while (left +1 < right) {
			mid = left + (right - left) / 2;
			//x在mid右边
			if(arr[mid]<x) {
				left = mid;
			}else if(arr[mid]>x) {
				right = mid;
			}else {
				result[count++] = arr[mid];
				break;
			}
		}
		
		
		//找到了x
		if(arr[mid]==x) {
			left=mid-1;
			right = mid+1;
			while(count<k) {
				int temp1 = Math.abs(arr[left]-x);
				int temp2 = Math.abs(arr[right]-x);
				if(temp1>temp2) {
					result[count++] = arr[right++];
				}else {
					result[count++] = arr[left--];
				}
				
			}
			Arrays.sort(result);
			return result;
		}
		//没找到x,找了left x right
		while(count<k) {
			if(left==0) {
				for(int i = 0;i<k;i++) {
					result[i] = arr[i];
				}
				return result;
			}
			if(right ==arr.length-1) {
				for(int i = k-1;i>-1;i--) {
					result[i] = arr[i];
				}
				return result;
			}
			int temp1 = Math.abs(arr[left]-x);
			int temp2 = Math.abs(arr[right]-x);
			if(temp1>temp2) {
				result[count++] = arr[right++];
			}else {
				result[count++] = arr[left--];
			}
			
		}
		Arrays.sort(result);
		return result;
	}

}
