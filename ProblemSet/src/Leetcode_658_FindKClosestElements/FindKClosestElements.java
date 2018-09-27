package Leetcode_658_FindKClosestElements;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.stream.Collectors;

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
		int[] arr = { 1,2,3,4,5 };
		int k = 4;
		int x = -1;
		//System.out.println(Arrays.toString(fce.findClosestElements(arr, k, x)));
		List<Integer> list = fce.findClosestElements(arr,k,x);
		for(int i = 0;i<list.size();i++) {
			System.out.print(list.get(i)+",");
		}
	}

	// 658. 找到 K 个最接近的元素
	public List<Integer> findClosestElements(int[] arr, int k, int x) {
		if(k==arr.length) {
			return arrToList(arr);
		}
		if(x<=arr[0]) {
			List<Integer> result = new ArrayList();
			for(int i = 0;i<k;i++) {
				result.add(arr[i]);
			}
			return result;
		}
		if(x>=arr[arr.length-1]) {
			List<Integer> result = new ArrayList();
			for(int i = arr.length-k;i<arr.length;i++) {
				result.add(arr[i]);
			}
			return result;
		}
		int left = 0;
		int right = arr.length-1;
		//找到x的范围
		while(left+1<right) {
			int mid = left+(right-left)/2;
			if(arr[mid]>x) {
				right=mid;
			}else if(arr[mid]<x) {
				left = mid;
			}else {
				left=mid;
				right =mid;
				break;
			}
		}
		//从范围开始找到k个数
		int[] result = new int[k];
		int count = 0;
		while(count<k) {
			int temp = Math.abs(arr[left]-x);
			int temp2 = Math.abs(arr[right]-x);
			if(temp<=temp2) {
				result[count++] = arr[left--];
			}else {
				result[count++] = arr[right++];
			}
		}
		Arrays.sort(result);
		return arrToList(result);
		
	}
	
	//arr to list
	public List<Integer> arrToList(int[] arr) {
		List<Integer> result = new ArrayList();
		for(int i = 0;i<arr.length;i++) {
			result.add(arr[i]);
		}
		return result;
	}

}
