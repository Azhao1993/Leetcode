package Leetcode_155_MinStack;

public class MinStackTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MinStack minStack = new MinStack();
		String[] input = { "push", "push", "push", "top", "pop", "getMin", "pop", "getMin", "pop", "push", "top",
				"getMin", "push", "top", "getMin", "pop", "getMin" };
		int[] value = { 2147483646, 2147483646, 2147483647, 0, 0, 0, 0, 0, 0, 2147483647, 0, 0, -2147483648, 0, 0, 0,
				0 };
		for (int i = 0; i < input.length; i++) {
			if (input[i].equals("push")) {
				System.out.println("push:" + value[i]);
				minStack.push(value[i]);
			} else if (input[i].equals("top")) {
				System.out.println("top:" + minStack.top());
			} else if (input[i].equals("pop")) {
				System.out.println("pop");
				minStack.pop();
			} else if (input[i].equals("getMin")) {
				System.out.println("getMin:" + minStack.getMin());
			}
		}
	}

}
