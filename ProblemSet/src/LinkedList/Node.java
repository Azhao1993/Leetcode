package LinkedList;

//Definition for a Node.
public class Node {
	public int val;
	public Node prev;
	public Node next;
	public Node child;

	public Node() {
	}

	public Node(int val, Node prev, Node next, Node child) {
		this.val = val;
		this.prev = prev;
		this.next = next;
		this.child = child;
	}
}
