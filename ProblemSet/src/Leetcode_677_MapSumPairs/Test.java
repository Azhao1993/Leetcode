package Leetcode_677_MapSumPairs;

public class Test {
	public static void main(String[] args) {
		MapSum ms = new MapSum();
		ms.insert("apple", 3);
		//输入: insert("apple", 3), 输出: Null
		System.out.println(ms.sum("apple"));
		//输入: sum("ap"), 输出: 3
		ms.insert("app", 2);
		//输入: insert("app", 2), 输出: Null
		System.out.println(ms.sum("ap"));
		//输入: sum("ap"), 输出: 5
	}
}
