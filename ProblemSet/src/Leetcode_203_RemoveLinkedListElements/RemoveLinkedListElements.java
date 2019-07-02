package Leetcode_203_RemoveLinkedListElements;

import LinkedList.ListNode;

/*
	删除链表中等于给定值 val 的所有节点。
	
	示例:	
		输入: 1->2->6->3->4->5->6, val = 6
		输出: 1->2->3->4->5
 */
public class RemoveLinkedListElements {
	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(2);
		ListNode node4 = new ListNode(1);
		// ListNode node5 = new ListNode(4);
		// ListNode node6 = new ListNode(5);
		// ListNode node7 = new ListNode(6);
		head.next = node2;
		node2.next = node3;
		node3.next = node4;
		// node4.next = node5;
		// node5.next = node6;
		// node6.next = node7;

		RemoveLinkedListElements rlle = new RemoveLinkedListElements();
		rlle.removeElements(head, 6);
	}

	// 203. 移除链表元素
	// 假头
	public ListNode removeElements2(ListNode head, int val) {
		ListNode dummyHead = new ListNode(0);// 假头
		dummyHead.next = head;
		ListNode cur = dummyHead;

		while (cur.next != null) {
			if (cur.next.val == val) {
				ListNode delNode = cur.next;
				cur.next = delNode.next;
				delNode.next = null;
			} else {
				cur = cur.next;
			}
		}
		head = dummyHead.next;
		dummyHead.next = null;// 还原原本的结构
		return head;
	}

}
