package Leetcode_019_RemoveNthNodeFromEndofList;

import LinkedList.ListNode;

/*
	给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
	
	示例：	
		给定一个链表: 1->2->3->4->5, 和 n = 2.
	
		当删除了倒数第二个节点后，链表变为 1->2->3->5.
	
	说明：	
		给定的 n 保证是有效的。
	
	进阶：	
		你能尝试使用一趟扫描实现吗？
 */
public class RemoveNthNodeFromEndofList {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		ListNode node1 = new ListNode(2);
		head.next = node1;
		int n = 1;
		RemoveNthNodeFromEndofList rnnfel = new RemoveNthNodeFromEndofList();
		rnnfel.removeNthFromEnd(head, n);
	}

	// 19. 删除链表的倒数第N个节点
	public ListNode removeNthFromEnd(ListNode head, int n) {
		ListNode slow = head;
		ListNode fast = head;
		int fastIndex = 0;
		for (int i = 0; i <= n && fast != null; i++) {
			fastIndex++;
			fast = fast.next;
		}
		while (fast != null) {
			slow = slow.next;
			fast = fast.next;
			fastIndex++;
		}
		// 删除节点
		if (fastIndex == n) {
			head = head.next;
		} else if (n == 1) {
			slow.next = null;
		} else {
			slow.next = slow.next.next;
		}

		return head;
	}

	// 7ms
	public ListNode removeNthFromEnd0(ListNode head, int n) {
		if (head == null || head.next == null)
			return null;

		ListNode slow = new ListNode(0);
		ListNode fast = new ListNode(0);
		slow.next = head;
		fast.next = head;

		for (int i = 0; i < n; i++) {
			fast = fast.next;
		}

		if (fast.next == null) {
			head = head.next;
			return head;
		}

		while (fast.next != null) {
			slow = slow.next;
			fast = fast.next;
		}

		slow.next = slow.next.next;

		return head;
	}
}
