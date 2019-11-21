package Leetcode_155_MinStack;

import java.util.Stack;

/*
	设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
	
	push(x) -- 将元素 x 推入栈中。
	pop() -- 删除栈顶的元素。
	top() -- 获取栈顶元素。
	getMin() -- 检索栈中的最小元素。
	
	示例:	
		MinStack minStack = new MinStack();
		minStack.push(-2);
		minStack.push(0);
		minStack.push(-3);
		minStack.getMin();   --> 返回 -3.
		minStack.pop();
		minStack.top();      --> 返回 0.
		minStack.getMin();   --> 返回 -2.
 */

//155. 最小栈
class MinStack {

	Stack<int[]> s;
	int min;

	/** initialize your data structure here. */
	public MinStack() {
		s = new Stack<int[]>();
	}

	public void push(int x) {
		if (s.isEmpty()) {
			min = x;
			s.push(new int[] { x, min });
		} else if (x < min) {
			min = x;
			s.push(new int[] { x, min });
		} else {
			s.push(new int[] { x, min });
		}
	}

	public void pop() {
		s.pop();
		if (!s.isEmpty()) {
			min = s.peek()[1];
		}

	}

	public int top() {
		return s.peek()[0];
	}

	public int getMin() {
		return s.peek()[1];
	}
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */