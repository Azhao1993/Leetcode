package Leetcode_203_RemoveLinkedListElements;

import LinkedList.ListNode;

/*
	删除链表中等于给定值 val的所有节点。
	
	示例:	
		输入: 1->2->6->3->4->5->6, val = 6
		输出: 1->2->3->4->5
 */
public class RemoveLinkedListElements {

	// 203. 移除链表元素
	public ListNode removeElements(ListNode head, int val) {
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
		return dummyHead.next;
	}
}
