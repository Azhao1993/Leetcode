package Leetcode_341_FlattenNestedListIterator;

import java.util.List;

public interface NestedInteger {

	// @return true 如果此NestedInteger包含单个整数，而不是嵌套列表。
	public boolean isInteger();

	// @return the single integer that this NestedInteger holds, if it holds a
	// single integer
	// Return null if this NestedInteger holds a nested list

	public Integer getInteger();

	// @return the nested list that this NestedInteger holds, if it holds a nested
	// list
	// Return null if this NestedInteger holds a single integer

	public List<NestedInteger> getList();
}
