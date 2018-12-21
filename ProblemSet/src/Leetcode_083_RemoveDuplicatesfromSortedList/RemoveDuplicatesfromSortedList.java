package Leetcode_083_RemoveDuplicatesfromSortedList;

import LinkedList.ListNode;

/*
	给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。	
	
	示例 1:	
		输入: 1->1->2
		输出: 1->2
		
	示例 2:	
		输入: 1->1->2->3->3
		输出: 1->2->3
 */
public class RemoveDuplicatesfromSortedList {
	// 83. 删除排序链表中的重复元素
	public ListNode deleteDuplicates(ListNode head) {
		if ((head == null) || (head.next == null)) {
			return head;
		}
		ListNode cur = head;
		ListNode next = cur.next;
		while (next != null) {
			if (next.val != cur.val) {
				next = next.next;
				cur = cur.next;
			} else {
				cur.next = next.next;
				 next = cur.next;
			}
		}
		return head;
	}
	
	//0ms
    public ListNode deleteDuplicates0(ListNode head) {
        check(head);
        return head;
    }
    
    public void check(ListNode current){
        if(current == null || current.next == null){
            return;
        }
        ListNode next = current.next;
        //当前节点和下一个节点是否相等
        if(current.val == next.val){
        	//删除next节点
            current.next = next.next;
            //继续检查当前节点
            check(current);
        }else{
            check(next);
        }
    }
}
