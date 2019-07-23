package Leetcode_077_Combinations;

import java.util.ArrayList;
import java.util.List;

/*
	给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
	
	示例:	
		输入: n = 4, k = 2
		输出:
		[
		  [2,4],
		  [3,4],
		  [2,3],
		  [1,2],
		  [1,3],
		  [1,4],
		]
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/combinations
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//77. 组合
public class Combinations {
	List<List<Integer>> res = new ArrayList<>();

	public List<List<Integer>> combine(int n, int k) {
		if (n <= 0 || k <= 0 || k > n) {
			return res;
		}
		generateCombine(1, n, k, new ArrayList<Integer>());
		return res;
	}

	// 75 ms 51.1 MB
	// 剪枝优化后：8 ms 51.5 MB
	private void generateCombine(int start, int n, int k, ArrayList<Integer> list) {
		if (k == 0) {
			res.add(new ArrayList<Integer>(list));
			return;
		}
		if (n - start + 1 < k) {
			return;
		}
		for (int i = start; i <= n; i++) {
			list.add(i);
			generateCombine(i + 1, n, k - 1, list);
			list.remove(list.size() - 1);
		}

	}
}
