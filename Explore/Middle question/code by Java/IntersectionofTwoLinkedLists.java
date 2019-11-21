package Leetcode_160_IntersectionofTwoLinkedLists;

import LinkedList.ListNode;

/*
	编写一个程序，找到两个单链表相交的起始节点。
	
	如下面的两个链表：
		A:   a1-a2-
					c1-c2-c3
		B:b1-b2-b3-	
		在节点 c1 开始相交。
	
	示例 1：
		A:     4 - 1 -
					   8- 4 -5
		B: 5 - 0 - 1 -		
	输入：
		intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
	输出：
		Reference of the node with value = 8
	输入解释：
		相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。
		从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
		在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。	 
	
	示例 2：
		A:0-9-1-
				2-4
		B:    3-	
	输入：
		intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
	输出：
		Reference of the node with value = 2
	输入解释：
		相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。
		从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
		在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。	 
	
	示例 3：
		A:2-6-4
				
		B: 1-5	
	输入：
		intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
	输出：
		null
	输入解释：
		从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
		由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
	解释：
		这两个链表不相交，因此返回 null。 
	
	注意：	
		如果两个链表没有交点，返回 null.
		在返回结果后，两个链表仍须保持原有的结构。
		可假定整个链表结构中没有循环。
		程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 */
public class IntersectionofTwoLinkedLists {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	// 160. 相交链表
	public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
		for (; headA != null; headA = headA.next) {
			ListNode temp = headB;
			while (temp != null) {
				if (temp == headA) {
					return headA;
				} else if (temp.next != null) {
					temp = temp.next;
				} else {
					break;
				}
			}
			if (headA.next == null) {
				return null;
			}
		}
		return null;
	}

	// 1ms
	public ListNode getIntersectionNode0(ListNode headA, ListNode headB) {
		if (headA == null || headB == null)
			return null;
		ListNode h1 = headA;
		ListNode h2 = headB;
		// lenA为A链表的长度，初始值为1
		int lenA = 1;
		int lenB = 1;
		while (h1.next != null) {
			lenA++;
			h1 = h1.next;
		}
		while (h2.next != null) {
			lenB++;
			h2 = h2.next;
		}
		// 若A与B尾结点不同，则肯定没有相交。
		if (h1 != h2)
			return null;
		else {
			int count = Math.abs(lenA - lenB);
			// h1指向链表长的头结点。
			if (lenA >= lenB) {
				h1 = headA;
				h2 = headB;
			} else {
				h1 = headB;
				h2 = headA;
			}
			for (int i = 0; i < count; i++)
				h1 = h1.next;
			while (h1 != null && h2 != null && h1 != h2) {
				h1 = h1.next;
				h2 = h2.next;
			}
		}
		// 若没有交点，则h1 为null
		return h1;

	}

}
