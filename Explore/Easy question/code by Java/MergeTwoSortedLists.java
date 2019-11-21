package Leetcode_021_MergeTwoSortedLists;

import LinkedList.ListNode;

/*
	将两个有序链表合并为一个新的有序链表并返回。
	新链表是通过拼接给定的两个链表的所有节点组成的。 
	
	示例：	
		输入：1->2->4, 1->3->4
		输出：1->1->2->3->4->4
 */
public class MergeTwoSortedLists {
	public static void main(String[] args) {
		ListNode l1 = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(4);
		l1.next = node2;
		node2.next = node3;
		ListNode l2 = new ListNode(1);
		ListNode node4 = new ListNode(3);
		ListNode node5 = new ListNode(4);
		l2.next = node4;
		node4.next = node5;

		MergeTwoSortedLists mtsl = new MergeTwoSortedLists();
		mtsl.mergeTwoLists(l1, l2);
	}

	// 21. 合并两个有序链表
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		// 其中一个为空
		if (l1 == null) {
			return l2;
		} else if (l2 == null) {
			return l1;
		}

		// 比较l1和l2的值
		// 保证l1小l2大，返回l1,l1不能动
		if (l1.val > l2.val) {
			return mergeTwoLists(l2, l1);
		}

		//
		ListNode min = l1;
		ListNode max = l1.next;
		// l2;
		ListNode next = l2;
		while ((max != null) && (l2 != null)) {
			if (l2.val < max.val) {
				min.next = l2;
				next = l2.next;
				l2.next = max;
				l2 = next;
				min = min.next;
			} else {
				min = max;
				max = max.next;
			}
		}
		if (max == null) {
			min.next = l2;
		}
		return l1;
	}

	// 7ms
	public ListNode mergeTwoLists0(ListNode l1, ListNode l2) {
		// 新开一个节点
		ListNode result = new ListNode(0);
		ListNode tmp = result;
		while (l1 != null && l2 != null) {
			// 谁小挂谁
			if (l1.val < l2.val) {
				tmp.next = l1;
				l1 = l1.next;
				tmp = tmp.next;
			} else {
				tmp.next = l2;
				l2 = l2.next;
				tmp = tmp.next;
			}
		}
		if (l1 == null) {
			tmp.next = l2;
		}
		if (l2 == null) {
			tmp.next = l1;
		}
		return result.next;
	}
}
