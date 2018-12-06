package Leetcode_454_FourSum2;

import java.util.HashMap;
import java.util.Map;

/*
	给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
	
	为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 231 - 1 。
	
	例如:	
		输入:
			A = [ 1, 2]
			B = [-2,-1]
			C = [-1, 2]
			D = [ 0, 2]	
		输出:
			2	
		解释:
			两个元组如下:
			1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
			2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 */
public class FourSum2 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] A = { 1, 2 };
		int[] B = { -2, -1 };
		int[] C = { -1, 2 };
		int[] D = { 0, 2 };
		new FourSum2().fourSumCount(A, B, C, D);
	}

	// 454. 四数相加 II
	
	//超时
	public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
		Map<Integer, Integer> mapa = arrToMap(A);
		Map<Integer, Integer> mapb = arrToMap(B);
		Map<Integer, Integer> mapc = arrToMap(C);
		Map<Integer, Integer> mapd = arrToMap(D);
		int count = 0;
		for (Integer a : mapa.keySet()) {
			for (Integer b : mapb.keySet()) {
				for (Integer c : mapc.keySet()) {
					for (Integer d : mapd.keySet()) {
						if (a + b + c + d == 0) {
							count += mapa.get(a) * mapb.get(b) * mapc.get(c) * mapd.get(d);
						}
					}
				}
			}
		}
		return count;
	}

	// 将数组存入map
	public Map<Integer, Integer> arrToMap(int[] arr) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < arr.length; i++) {
			if (map.containsKey(arr[i])) {
				int value = map.get(arr[i]) + 1;
				map.put(arr[i], value);
			} else {
				map.put(arr[i], 1);
			}
		}
		return map;
	}

}
