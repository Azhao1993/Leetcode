package Leetcode_147_InsertionSortList;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

import LinkedList.ListNode;
import LinkedList.ListNodeUtils;

/*
	对链表进行插入排序。
	
	https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif
	
	插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
	每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。 
	
	插入排序算法：
		插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
		每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
		重复直到所有输入数据插入完为止。 
	
	示例 1：
		输入: 4->2->1->3
		输出: 1->2->3->4
	示例 2：
		输入: -1->5->3->4->0
		输出: -1->0->3->4->5
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/insertion-sort-list
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class InsertionSortList {

	public static void main(String[] args) {
		int[] arr = { 6, 5, 3, 1, 8, 7, 2, 4 };
		ListNode head = ListNodeUtils.creatNode(arr, arr.length);
		ListNodeUtils.printList(head);
		head = new InsertionSortList().insertionSortList2(head);
		ListNodeUtils.printList(head);
	}

	// 147. 对链表进行插入排序
	public ListNode insertionSortList(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}

		ListNode dummy = new ListNode(0);
		dummy.next = head;
		// 有序的最后一个节点
		ListNode end = dummy;

		while (end.next != null) {
			// pre->插入在此位置
			ListNode pre = dummy;
			// 待排序的节点
			ListNode cur = end.next;
			while (pre.next != cur && cur.val > pre.next.val) {
				pre = pre.next;
			}

			end.next = cur.next;// 拿出cur
			cur.next = pre.next;
			pre.next = cur;

			if (end.next == cur) {
				end = end.next;
			}
		}
		return dummy.next;
	}

	// 额外空间
	public ListNode insertionSortList2(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}
		PriorityQueue<ListNode> queue = new PriorityQueue<>(new Comparator<ListNode>() {
			@Override
			public int compare(ListNode o1, ListNode o2) {
				return o1.val - o2.val;
			}
		});

		while (head != null) {
			queue.add(head);
			head = head.next;
		}

		head = queue.poll();
		ListNode cur = head;

		while (!queue.isEmpty()) {
			cur.next = queue.poll();
			cur = cur.next;
		}
		cur.next = null;

		return head;

	}

}
