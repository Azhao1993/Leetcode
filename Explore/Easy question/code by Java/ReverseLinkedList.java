package Leetcode_206_ReverseLinkedList;

import LinkedList.ListNode;

/*
	反转一个单链表。
	
	示例:	
		输入: 1->2->3->4->5->NULL
		输出: 5->4->3->2->1->NULL
	进阶:
		你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 */
public class ReverseLinkedList {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(3);
		ListNode node4 = new ListNode(4);
		ListNode node5 = new ListNode(5);
		head.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node5;
		ReverseLinkedList rll = new ReverseLinkedList();
		rll.reverseList1(head);
	}

	// 206. 反转链表

	// 递归
	public ListNode reverseList1(ListNode head) {
		// 没有节点或者只有一个节点
		if (head == null || head.next == null) {
			return head;
		}
		//
		ListNode newHead = reverseList1(head.next);
		head.next.next = head;
		head.next = null;
		return newHead;
	}

	// 迭代
	public ListNode reverseList2(ListNode head) {
		// 新表尾pre
		ListNode pre = null;
		// 新表头
		ListNode next = null;
		while (head != null) {
			// 新表头
			next = head.next;
			// 旧表头指向新表尾
			head.next = pre;

			pre = head;
			head = next;
		}
		return pre;
	}
}
