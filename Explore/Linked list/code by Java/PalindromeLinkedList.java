package Leetcode_234_PalindromeLinkedList;

import LinkedList.ListNode;

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
		ListNode head = new ListNode(1);
		ListNode node2 = new ListNode(2);
		ListNode node3 = new ListNode(3);
		ListNode node4 = new ListNode(4);
		ListNode node5 = new ListNode(4);
		ListNode node6 = new ListNode(3);
		ListNode node7 = new ListNode(2);
		ListNode node8 = new ListNode(1);
		head.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node5;
		node5.next = node6;
		node6.next = node7;
		node7.next = node8;

		PalindromeLinkedList pll = new PalindromeLinkedList();
		pll.isPalindrome(head);
	}

	// 234. 回文链表
	public boolean isPalindrome(ListNode head) {
		// 空节点或者只有一个节点
		if ((head == null) || (head.next == null)) {
			return true;
		}
		// 找到中间节点
		// 偶数个节点 slow.next 是后半段的head
		// 奇数个节点 slow是中间节点
		ListNode fast = head;
		ListNode slow = head;
		while ((fast.next != null) && (fast.next.next != null)) {
			fast = fast.next.next;
			slow = slow.next;
		}

		// 对链表后半段进行反转
		ListNode midNode = slow;
		ListNode firNode = slow.next;// 后半段链表的第一个节点
		ListNode cur = firNode.next;// 插入节点从第一个节点后面一个开始
		firNode.next = null;// 第一个节点最后会变最后一个节点
		while (cur != null) {
			ListNode nextNode = cur.next;// 保存下次遍历的节点
			cur.next = midNode.next;
			midNode.next = cur;
			cur = nextNode;
		}

		// 反转之后对前后半段进行比较
		slow = head;
		fast = midNode.next;
		while (fast != null) {
			if (fast.val != slow.val) {
				return false;
			}
			slow = slow.next;
			fast = fast.next;
		}
		return true;

	}

	// 0ms
	public boolean isPalindrome0(ListNode head) {
		if (head == null || head.next == null) {
			return true;
		}

		if (head.next.next == null) {
			return head.val == head.next.val;
		}

		ListNode fast = head.next;
		ListNode slow = head;

		while (fast.next != null) {
			// 不停的从slow的后一个开始遍历，知道找到值相同的节点
			// 一次完成后，再移动到原节点的下一个节点开始，继续重复上面的步骤
			if (fast.next.val == slow.val) {
				if (fast.next.next != null) {
					return false;
				}
				fast.next = null;
				slow = slow.next;
				fast = slow.next;
				if (fast == null || fast.val == slow.val) {
					return true;
				}
			} else {
				fast = fast.next;
			}
		}
		return false;
	}
}
