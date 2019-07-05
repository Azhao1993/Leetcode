package Leetcode_148_SortList;

import LinkedList.ListNode;
import LinkedList.ListNodeUtils;

/*
	在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
	
	示例 1:	
		输入: 4->2->1->3
		输出: 1->2->3->4
	示例 2:	
		输入: -1->5->3->4->0
		输出: -1->0->3->4->5
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/sort-list
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//148. 排序链表
public class SortList {

	public static void main(String[] args) {
		int[] arr = { 1 };
		ListNode head = ListNodeUtils.creatNode(arr, arr.length);
		ListNodeUtils.printList(head);
		head = new SortList().sortList(head);
		ListNodeUtils.printList(head);

	}

	// 归并 自顶向下
	public ListNode sortList(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}

		ListNode dummy = new ListNode(0);
		dummy.next = head;

		ListNode p = head;
		int length = 0;
		while (p != null) {
			++length;
			p = p.next;
		}

		for (int size = 1; size < length; size <<= 1) {
			ListNode cur = dummy.next;
			ListNode tail = dummy;

			while (cur != null) {
				ListNode left = cur;
				ListNode right = cut(left, size);// 切断
				cur = cut(right, size);// 切断

				tail.next = merge(left, right);
				while (tail.next != null) {
					tail = tail.next;
				}
			}
		}
		return dummy.next;

	}

	private ListNode merge(ListNode left, ListNode right) {
		ListNode dummy = new ListNode(0);
		ListNode head = dummy;
		while (left != null && right != null) {
			if (left.val <= right.val) {
				head.next = left;
				left = left.next;
			} else {
				head.next = right;
				right = right.next;
			}

			head = head.next;
		}

		head.next = left == null ? right : left;
		return dummy.next;
	}

	private ListNode cut(ListNode head, int n) {

		ListNode p = head;
		while (--n != 0 && p != null) {
			p = p.next;
		}

		if (p == null)
			return null;

		ListNode next = p.next;
		p.next = null;
		return next;

	}

}
