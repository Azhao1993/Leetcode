package Leetcode_599_MinimumIndexSumofTwoLists;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
	假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。	
	你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。
	
	示例 1:	
		输入:
			["Shogun", "Tapioca Express", "Burger King", "KFC"]
			["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
		输出: ["Shogun"]
		解释: 他们唯一共同喜爱的餐厅是“Shogun”。
	示例 2:	
		输入:
			["Shogun", "Tapioca Express", "Burger King", "KFC"]
			["KFC", "Shogun", "Burger King"]
		输出: ["Shogun"]
		解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
	提示:	
		1.两个列表的长度范围都在 [1, 1000]内。
		2.两个列表中的字符串的长度将在[1，30]的范围内。
		3.下标从0开始，到列表的长度减1。
		4.两个列表都没有重复的元素。
 */
public class MinimumIndexSumofTwoLists {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 599. 两个列表的最小索引总和
	public String[] findRestaurant(String[] list1, String[] list2) {
		Map<String, Integer> map = new HashMap<String, Integer>();
		Map<String, Integer> resmap = new HashMap<String, Integer>();
		for (int i = 0; i < list1.length; i++) {
			map.put(list1[i], i);
		}
		int minIndex = Integer.MAX_VALUE;
		int count = 0;
		for (int i = 0; i < list2.length; i++) {
			if (map.containsKey(list2[i])) {
				resmap.put(list2[i], map.get(list2[i]) + i);
				if (minIndex > map.get(list2[i]) + i) {
					count = 1;
					minIndex = map.get(list2[i]) + i;
				} else if (minIndex == map.get(list2[i]) + i) {
					count++;
				}
			}
		}
		String[] result = new String[count];
		int i = 0;
		for (String x : resmap.keySet()) {
			if (resmap.get(x) == minIndex) {
				result[i++] = x;
			}
		}
		return result;
	}

	// 16ms
	public String[] findRestaurant2(String[] list1, String[] list2) {
		List<String> result = new ArrayList<>();
		Map<String, Integer> map = new HashMap<>();
		int index = 2000;
		for (int i = 0; i < list1.length; i++) {
			map.put(list1[i], i);
		}
		for (int i = 0; i < list2.length && i <= index; i++) {
			if (map.containsKey(list2[i])) {
				int tempIndex = map.get(list2[i]) + i;
				if (tempIndex < index) {
					result.clear();
					result.add(list2[i]);
					index = tempIndex;
				} else if (tempIndex == index) {
					result.add(list2[i]);
				}
			}
		}
		return result.toArray(new String[result.size()]);
	}

}
