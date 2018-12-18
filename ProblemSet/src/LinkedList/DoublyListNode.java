package LinkedList;

//Definition for doubly-linked list.
public class DoublyListNode {
	// 成员变量
	// 当前节点的值
	public int val;
	// 后一个节点next
	// 前一个节点prev
	public DoublyListNode next, prev;

	// 构造函数
	public DoublyListNode(int x) {
		val = x;
	}
}
