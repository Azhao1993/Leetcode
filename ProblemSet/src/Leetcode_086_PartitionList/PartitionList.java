package Leetcode_086_PartitionList;

import LinkedList.ListNode;

/*
	给定一个链表和一个特定值 x，对链表进行分隔，
	使得所有小于 x 的节点都在大于或等于 x 的节点之前。
	
	你应当保留两个分区中每个节点的初始相对位置。
	
	示例:	
		输入: head = 1->4->3->2->5->2, x = 3
		输出: 1->2->2->4->3->5
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/partition-list
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//86. 分隔链表 注意切断尾巴
public class PartitionList {
	public ListNode partition(ListNode head, int x) {
		if (head == null || head.next == null) {
			return head;
		}

		ListNode before_head = new ListNode(0);
		ListNode before = before_head;
		ListNode after_head = new ListNode(0);
		ListNode after = after_head;

		while (head != null) {
			if (head.val < x) {
				before.next = head;
				before = before.next;
			} else {
				after.next = head;
				after = after.next;
			}
			head = head.next;
		}
		// 防止后面还有小于x的节点
		after.next = null;

		before.next = after_head.next;
		return before_head.next;

	}
}
