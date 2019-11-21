package Leetcode_141_LinkedListCycle;

import LinkedList.ListNode;

/*
	给定一个链表，判断链表中是否有环。	
	为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
	如果 pos 是 -1，则在该链表中没有环。	
			  	
	示例 1：	
		输入：head = [3,2,0,-4], pos = 1
		输出：true
		解释：链表中有一个环，其尾部连接到第二个节点。
				
		3-2-0-4
		  |---|
	
	示例 2：	
		输入：head = [1,2], pos = 0
		输出：true
		解释：链表中有一个环，其尾部连接到第一个节点。
		
		1-2
		|-|	
	
	示例 3：	
		输入：head = [1], pos = -1
		输出：false
		解释：链表中没有环。
		
		1
			
	进阶：	
		你能用 O(1)（即，常量）内存解决此问题吗？
 */
public class LinkedListCycle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode node0 = new ListNode(1);
		ListNode node1 = new ListNode(2);
		//ListNode node2 = new ListNode(0);
		//ListNode node3 = new ListNode(-4);
		node0.next = node1;
		//node1.next = node2;
		//node2.next = node3;
		//node3.next = node1;
		
		LinkedListCycle llc = new LinkedListCycle();
		System.out.println(llc.hasCycle(node0));
		
	}
	//141. 环形链表	
    public boolean hasCycle(ListNode head) {    	
    	if((head!=null)&&(head.next!=null)) {    		
    		ListNode fast = head.next;
        	ListNode slow = head.next;
        	while((fast!=null)&&(slow!=null)) {
        		if(slow.next!=null) {
        			slow = slow.next;
        		}else {
        			return false;
        		}
        		
        		if((fast.next!=null)&&(fast.next.next!=null)) {
        			fast = fast.next.next;
        		}else {
        			return false;
        		}
        		
        		if(fast==slow) {
        			return true;
        		}
        	}
        	return false;
    	}
    	return false;    	
    }
    
    //0ms
    public boolean hasCycle0(ListNode head) {
        ListNode fast = head;
		ListNode low = head;
		while (fast != null && fast.next != null) {
			low = low.next;
			fast = fast.next.next;
			if (fast == low) {
				return true;
			}
		}
		return false;
    }
}
