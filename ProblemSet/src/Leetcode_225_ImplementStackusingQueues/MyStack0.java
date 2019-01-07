package Leetcode_225_ImplementStackusingQueues;

import java.util.LinkedList;
import java.util.Queue;

//61ms
class MyStack0 {

	Queue<Integer> queue1 = null;
	Queue<Integer> queue2 = null;

	/** Initialize your data structure here. */
	public MyStack0() {
		queue1 = new LinkedList<Integer>();
		queue2 = new LinkedList<Integer>();
	}

	/** Push element x onto stack. */
	public void push(int x) {
		if (queue1.isEmpty()) {
			queue1.offer(x);
			while (!queue2.isEmpty()) {
				queue1.offer(queue2.poll());
			}
		} else if (queue2.isEmpty()) {
			queue2.offer(x);
			while (!queue1.isEmpty()) {
				queue2.offer(queue1.poll());
			}
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	public int pop() {
		if (!queue1.isEmpty()) {
			return queue1.poll();
		} else if (!queue2.isEmpty()) {
			return queue2.poll();
		}
		return 0;
	}

	/** Get the top element. */
	public int top() {
		if (!queue1.isEmpty()) {
			return queue1.peek();
		} else if (!queue2.isEmpty()) {
			return queue2.peek();
		}
		return 0;
	}

	/** Returns whether the stack is empty. */
	public boolean empty() {
		return queue1.isEmpty() && queue2.isEmpty();
	}
}

