package Leetcode_002_AddTwoNumbers;

import LinkedList.ListNode;

/*
	给出两个 非空 的链表用来表示两个非负的整数。
	其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。	
	如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。	
	您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
	
	示例：	
		输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
		输出：7 -> 0 -> 8
		原因：342 + 465 = 807
 */
public class AddTwoNumbers {
	public static void main(String[] args) {
		ListNode l1 = new ListNode(2);
		ListNode node1 = new ListNode(4);
		ListNode node2 = new ListNode(3);
		// ListNode node3 = new ListNode(8);
		l1.next = node1;
		node1.next = node2;
		// node2.next = node3;
		ListNode l2 = new ListNode(5);
		ListNode node4 = new ListNode(6);
		ListNode node5 = new ListNode(4);
		l2.next = node4;
		node4.next = node5;
		AddTwoNumbers atn = new AddTwoNumbers();
		atn.addTwoNumbers(l1, l2);
	}

	// 2. 两数相加
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int flag = 0;// 进位标志服
		ListNode preHead = new ListNode(0);// 假头
		ListNode curNode = preHead;
		while (l1 != null || l2 != null || flag != 0) {
			int a = l1 == null ? 0 : l1.val;
			l1 = l1 == null ? null : l1.next;

			int b = l2 == null ? 0 : l2.val;
			l2 = l2 == null ? null : l2.next;

			int val = a + b + flag;

			curNode.next = new ListNode(val % 10);
			curNode = curNode.next;

			flag = val / 10;
		}
		return preHead.next;
	}

}
