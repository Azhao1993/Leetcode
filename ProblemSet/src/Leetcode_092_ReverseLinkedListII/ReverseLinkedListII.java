package Leetcode_092_ReverseLinkedListII;

import LinkedList.ListNode;

/*
	反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
	
	说明:
		1 ≤ m ≤ n ≤ 链表长度。
	
	示例:	
		输入: 1->2->3->4->5->NULL, m = 2, n = 4
		输出: 1->4->3->2->5->NULL
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//92. 反转链表 II
public class ReverseLinkedListII {
	public ListNode reverseBetween(ListNode head, int m, int n) {
		if (head == null) {
			return null;
		}
		ListNode preHead = new ListNode(0);
		preHead.next = head;
		ListNode pre = preHead;
		// 找到要反转的前一个位置,第m-1个节点
		for (int i = 0; i < m - 1; i++) {
			pre = pre.next;
		}
		// start为要反转的第一个节点
		ListNode start = pre.next;
		ListNode next = start.next;
		for (int i = 0; i < n - m; i++) {
			start.next = next.next;
			next.next = pre.next;
			pre.next = next;
			next = start.next;
		}
		return preHead.next;
	}
}
