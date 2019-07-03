package Leetcode_061_RotateList;

import LinkedList.ListNode;
import LinkedList.ListNodeUtils;

/*
	给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
	
	示例 1:	
		输入: 1->2->3->4->5->NULL, k = 2
		输出: 4->5->1->2->3->NULL
	解释:
		向右旋转 1 步: 5->1->2->3->4->NULL
		向右旋转 2 步: 4->5->1->2->3->NULL
	
	示例 2:	
		输入: 0->1->2->NULL, k = 4
		输出: 2->0->1->NULL
	解释:
		向右旋转 1 步: 2->0->1->NULL
		向右旋转 2 步: 1->2->0->NULL
		向右旋转 3 步: 0->1->2->NULL
		向右旋转 4 步: 2->0->1->NULL
 */
public class RotateList {
	public static void main(String[] args) {
		ListNode head = ListNodeUtils.creatNode(new int[] { 1 }, 1);
		ListNodeUtils.printList(head);
		head = new RotateList().rotateRight(head, 0);
		ListNodeUtils.printList(head);

	}

	// 61. 旋转链表
	public ListNode rotateRight(ListNode head, int k) {
		if (head == null || head.next == null) {
			return head;
		}

		ListNode p = head;

		int length = 0;
		while (p != null) {
			++length;
			p = p.next;
		}
		k %= length;
		if (k == 0) {
			return head;
		}

		ListNode dummy = new ListNode(0);
		dummy.next = head;

		p = dummy;
		ListNode q = dummy;

		for (int i = 0; i < k; i++) {
			q = q.next;
		}

		while (q.next != null) {
			p = p.next;
			q = q.next;
		}

		dummy.next = p.next;
		p.next = null;
		q.next = head;

		return dummy.next;
	}
}
