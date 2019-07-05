package Leetcode_234_PalindromeLinkedList;

import LinkedList.ListNode;
import LinkedList.ListNodeUtils;

/*
	请判断一个链表是否为回文链表。
	
	示例 1:	
		输入: 1->2
		输出: false
	
	示例 2:	
		输入: 1->2->2->1
		输出: true
	
	进阶：
		你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 */
public class PalindromeLinkedList {
	public static void main(String[] args) {
		int[] arr = { 1, 1, 1, 1, 1 };
		System.out.println("length:" + arr.length);

		ListNode head = ListNodeUtils.creatNode(arr, arr.length);
		ListNodeUtils.printList(head);
		PalindromeLinkedList pll = new PalindromeLinkedList();
		System.out.println(pll.isPalindrome(head));

	}

	// 234. 回文链表
	public boolean isPalindrome(ListNode head) {
		ListNode end = head;
		ListNode mid = head;
		// 找到中点
		int halfLength = 0;
		while (end != null && end.next != null) {
			halfLength++;
			mid = mid.next;
			end = end.next.next;
		}
		System.out.println("halfLength:" + halfLength);
		// 翻转后半段（mid为头结点）
		ListNode nextHead = reverseList(mid);
		ListNodeUtils.printList(nextHead);
		// 比较
		for (int i = 0; i < halfLength; i++) {
			if (head.val != nextHead.val) {
				return false;
			}
			head = head.next;
			nextHead = nextHead.next;
		}
		return true;
	}

	private ListNode reverseList(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}
		ListNode pre = null;
		while (head != null) {
			ListNode next = head.next;
			head.next = pre;

			pre = head;
			head = next;
		}
		return pre;
	}

}
