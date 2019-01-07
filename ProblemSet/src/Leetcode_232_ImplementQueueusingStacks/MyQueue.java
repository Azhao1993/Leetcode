package Leetcode_232_ImplementQueueusingStacks;

import java.util.Stack;

/*
	使用栈实现队列的下列操作：	
		push(x) -- 将一个元素放入队列的尾部。
		pop() -- 从队列首部移除元素。
		peek() -- 返回队列首部的元素。
		empty() -- 返回队列是否为空。
	
	示例:	
		MyQueue queue = new MyQueue();
		
		queue.push(1);
		queue.push(2);  
		queue.peek();  // 返回 1
		queue.pop();   // 返回 1
		queue.empty(); // 返回 false
	
	说明:	
		你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
		你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
		假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
 */
//232. 用栈实现队列
class MyQueue {

	Stack<Integer> stack;
	Stack<Integer> stack2;

	/** Initialize your data structure here. */
	public MyQueue() {
		stack = new Stack<Integer>();
		stack2 = new Stack<Integer>();
	}

	/** Push element x to the back of queue. */
	public void push(int x) {
		stack.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	public int pop() {
		while (stack.size() > 1) {
			stack2.push(stack.pop());
		}
		int pop = stack.pop();
		while (!stack2.isEmpty()) {
			stack.push(stack2.pop());
		}
		return pop;
	}

	/** Get the front element. */
	public int peek() {
		while (stack.size() > 1) {
			stack2.push(stack.pop());
		}
		int pop = stack.pop();
		stack.push(pop);
		while (!stack2.isEmpty()) {
			stack.push(stack2.pop());
		}
		return pop;
	}

	/** Returns whether the queue is empty. */
	public boolean empty() {
		return stack.isEmpty();
	}
}