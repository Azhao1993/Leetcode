package Leetcode_023_MergekSortedLists;

import java.util.Comparator;
import java.util.PriorityQueue;

import LinkedList.ListNode;
import LinkedList.ListNodeUtils;
import TreeNode.TreeNode;

/*
	合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
	
	示例:	
		输入:
			[
			  1->4->5,
			  1->3->4,
			  2->6
			]
		输出: 1->1->2->3->4->4->5->6

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class MergekSortedLists {
	public static void main(String[] args) {
		int[] arr = { -2, -1, -1, -1 };
		ListNode list1 = ListNodeUtils.creatNode(arr, arr.length);
		ListNode[] lists = new ListNode[2];
		lists[0] = list1;
		lists[1] = null;
		new MergekSortedLists().mergeKLists(lists);
	}

	// 23. 合并K个排序链表
	public ListNode mergeKLists(ListNode[] lists) {
		PriorityQueue<ListNode> queue = new PriorityQueue<>(new Comparator<ListNode>() {
			@Override
			public int compare(ListNode o1, ListNode o2) {
				return o1.val - o2.val;
			}
		});
		ListNode dummy = new ListNode(0);
		ListNode head = dummy;
		for (int i = 0; i < lists.length; i++) {
			ListNode curHead = lists[i];
			if (curHead != null) {
				queue.add(curHead);
			}
		}
		while (!queue.isEmpty()) {
			ListNode cur = queue.poll();
			head.next = cur;
			if (cur.next != null) {
				cur = cur.next;
				queue.add(cur);
			}
			head = head.next;
		}
		return dummy.next;
	}
}
