package Leetcode_025_ReverseNodesinkGroup;

import LinkedList.ListNode;

/*
	给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。	
	k 是一个正整数，它的值小于或等于链表的长度。	
	如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
	
	示例 :	
		给定这个链表：1->2->3->4->5	
		当 k = 2 时，应当返回: 2->1->4->3->5	
		当 k = 3 时，应当返回: 3->2->1->4->5
	
	说明 :	
		你的算法只能使用常数的额外空间。
		你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//25. K 个一组翻转链表
public class ReverseNodesinkGroup {
	public static void main(String[] args) {
		int[] arr = { 1, 2, 3, 4, 5 };
		int n = arr.length;
		ReverseNodesinkGroup rnkg = new ReverseNodesinkGroup();
		ListNode head = rnkg.creatNode(arr, n);
		rnkg.printList(head);
		head = rnkg.reverseKGroup(head, 3);
		rnkg.printList(head);
	}

	public ListNode creatNode(int[] arr, int n) {
		if (n == 0) {
			return null;
		}
		ListNode head = new ListNode(arr[0]);
		ListNode cur = head;
		for (int i = 1; i < n; i++) {
			cur.next = new ListNode(arr[i]);
			cur = cur.next;
		}
		return head;
	}

	public void printList(ListNode head) {
		while (head != null) {
			System.out.print(head.val + " -> ");
			head = head.next;
		}
		System.out.println("null");
	}

	public ListNode reverseKGroup(ListNode head, int k) {
		ListNode dummy = new ListNode(0);
		dummy.next = head;
		ListNode hail = head;
		for (int i = 1; i < k && hail != null; i++) {
			hail = hail.next;
		}
		if (hail == null) {
			return head;
		}

		ListNode next = head.next;
		ListNode nextHead = hail.next;
		for (int i = 1; i < k; i++) {
			dummy.next = next;
			hail.next = head;
			head.next = nextHead;
			hail = hail.next;
			head = next;
			next = head.next;
		}

		hail.next = reverseKGroup(nextHead, k);
		head = dummy.next;
		dummy.next = null;
		return head;

	}
}
