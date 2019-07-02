package Leetcode_024_SwapNodesinPairs;

import LinkedList.ListNode;

/*
	给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
	
	示例:	
		给定 1->2->3->4, 你应该返回 2->1->4->3.
	
	说明:	
		你的算法只能使用常数的额外空间。
		你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */
public class SwapNodesinPairs {
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

		SwapNodesinPairs snp = new SwapNodesinPairs();
		snp.swapPairs(head);

	}

	// 24. 两两交换链表中的节点

	// 递归
	public ListNode swapPairs(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}
		ListNode newHead = head.next;
		ListNode next = head.next.next;
		newHead.next = head;
		head.next = swapPairs(next);
		return newHead;
	}

	// 迭代
	public ListNode swapPairs2(ListNode head) {
		ListNode dummy = new ListNode(0);
		dummy.next = head;
		ListNode pre = dummy;
		while (pre.next != null && pre.next.next != null) {
			ListNode node1 = pre.next;
			ListNode node2 = node1.next;
			ListNode next = node2.next;

			pre.next = node2;
			node2.next = node1;
			node1.next = next;
			pre = node1;
		}
		return dummy.next;
	}
}
