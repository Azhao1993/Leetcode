package Leetcode_082_RemoveDuplicatesfromSortedListII;

import LinkedList.ListNode;

/*
	给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
	
	示例 1:
		输入: 1->2->3->3->4->4->5
		输出: 1->2->5
	示例 2:
		输入: 1->1->1->2->3
		输出: 2->3
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class RemoveDuplicatesfromSortedListII {
	// 82. 删除排序链表中的重复元素 II
	public ListNode deleteDuplicates(ListNode head) {
		ListNode dummyHead = new ListNode(0);
		dummyHead.next = head;
		ListNode pre = dummyHead;

		while (head != null && head.next != null) {
			ListNode next = head.next;
			if (head.val != next.val) {
				pre = pre.next;
				head = head.next;
			} else {
				while (next != null && next.val == head.val) {
					next = next.next;
				}
				pre.next = next;
				head = next;
			}
		}
		head = dummyHead.next;
		dummyHead.next = null;
		return head;
	}
}
