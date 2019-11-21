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
		ListNode result = new ListNode(0);
		ListNode temp = result;
		int count = 0;
		int num1 = 0;
		int num2 = 0;
		int sum = 0;
		do {

			if (l1 == null) {
				num1 = 0;
			} else {
				num1 = l1.val;
				l1 = l1.next;
			}

			if (l2 == null) {
				num2 = 0;
			} else {
				num2 = l2.val;
				l2 = l2.next;
			}

			sum = num1 + num2 + count;
			if (sum >= 10) {
				temp.next = new ListNode(sum - 10);
				count = 1;
			} else {
				temp.next = new ListNode(sum);
				count = 0;
			}

			temp = temp.next;

		} while (l1 != null || l2 != null || count != 0);
		return result.next;
	}

	// 21ms
	public ListNode addTwoNumbers0(ListNode l1, ListNode l2) {
		ListNode dummyHead = new ListNode(0);
		ListNode p = l1, q = l2, curr = dummyHead;
		int carry = 0;
		while (p != null && q != null) {
			int sum = carry + p.val + q.val;
			carry = sum / 10;
			curr.next = new ListNode(sum % 10);
			curr = curr.next;
			if (p != null)
				p = p.next;
			if (q != null)
				q = q.next;
		}

		if (p == null) {
			while (q != null) {
				int sum = carry + q.val;
				carry = sum / 10;
				if (carry > 0) {
					curr.next = new ListNode(sum % 10);
					curr = curr.next;
					q = q.next;
				} else {
					ListNode m = new ListNode(sum);
					m.next = q.next;
					curr.next = m;
					break;
				}
			}
		} else if (q == null) {
			while (p != null) {
				int sum = carry + p.val;
				carry = sum / 10;
				if (carry > 0) {
					curr.next = new ListNode(sum % 10);
					curr = curr.next;
					p = p.next;
				} else {
					ListNode m = new ListNode(sum);
					m.next = p.next;
					curr.next = m;
					break;
				}
			}
		}
		if (carry > 0) {
			curr.next = new ListNode(carry);
		}

		return dummyHead.next;
	}
}
