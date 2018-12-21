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
		
	}
	// 24. 两两交换链表中的节点
	public ListNode swapPairs(ListNode head) {
		// <=1个节点
		if ((head == null) || (head.next == null)) {
			return head;
		}
		// >=2节点
		ListNode newHead = new ListNode(0);		
		ListNode cur = head;
		newHead.next = cur.next;
		ListNode slow;
		ListNode fast;
		while ((cur != null) && (cur.next != null)) {
			slow = cur;
			fast = cur.next;
			cur = fast.next;
			fast.next = slow;
			slow.next = cur;
		}
		return newHead.next;

	}
}
