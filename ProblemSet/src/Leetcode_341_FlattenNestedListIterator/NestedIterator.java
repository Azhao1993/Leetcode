
package Leetcode_341_FlattenNestedListIterator;

import java.util.Iterator;
import java.util.List;
import java.util.Stack;

/*
	给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。	
	列表中的项或者为一个整数，或者是另一个列表。	
	示例 1:	
		输入: [[1,1],2,[1,1]]
		输出: [1,1,2,1,1]
		解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
	示例 2:	
		输入: [1,[4,[6]]]
		输出: [1,4,6]
		解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。
 */

//341. 扁平化嵌套列表迭代器
public class NestedIterator implements Iterator<Integer> {

	Stack<NestedInteger> stack = new Stack<>();

	public NestedIterator(List<NestedInteger> nestedList) {
		for (int i = nestedList.size() - 1; i >= 0; i--) {
			stack.push(nestedList.get(i));
		}
	}

	@Override
	public Integer next() {
		return stack.pop().getInteger();
	}

	@Override
	public boolean hasNext() {
		while (!stack.isEmpty()) {
			NestedInteger curr = stack.peek();
			if (curr.isInteger()) {
				return true;
			}
			stack.pop();
			for (int i = curr.getList().size() - 1; i >= 0; i--) {
				stack.push(curr.getList().get(i));
			}
		}
		return false;
	}

}

//这是允许创建嵌套列表的接口。
//你不应该实现它，或推测它的实现
