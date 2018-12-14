package Leetcode_142_LinkedListCycle2;

import java.util.ArrayList;
import java.util.List;

import LinkedList.ListNode;

/*
	给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。	
	为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
		
	说明：不允许修改给定的链表。	 
	
	示例 1：	
		输入：head = [3,2,0,-4], pos = 1
		输出：tail connects to node index 1
		解释：链表中有一个环，其尾部连接到第二个节点。	
	
	示例 2：	
		输入：head = [1,2], pos = 0
		输出：tail connects to node index 0
		解释：链表中有一个环，其尾部连接到第一个节点。	
	
	示例 3：	
		输入：head = [1], pos = -1
		输出：no cycle
		解释：链表中没有环。	 
	
	进阶：
		你是否可以不用额外空间解决此题？
 */
public class LinkedListCycle2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//建立链表
		ListNode head = new ListNode(3);
		ListNode node1 = new ListNode(2);
		ListNode node2 = new ListNode(0);
		ListNode node3 = new ListNode(1);
		ListNode node4 = new ListNode(-4);
		head.next = node1;
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = node1;
		
		LinkedListCycle2 llc2 = new LinkedListCycle2();
		System.out.println(llc2.detectCycle0(head).val);
		
	}
	//142. 环形链表 II
    public ListNode detectCycle(ListNode head) {
    	if(head==null) {
    		return head;
    	}
    	//list
    	List<ListNode> list = new ArrayList<ListNode>();
    	while(true) {
    		if(list.contains(head)) {
    			return head;
    		}else if(head.next!=null){
    			list.add(head);
    			head = head.next;
    		}else {
    			break;
    		}
    	}
    	return null;    	
    }
    
    //0ms
    public ListNode detectCycle0(ListNode head) {
    	//慢指针
        ListNode slow = head;
        //快指针
        ListNode fast = head;
        //判断是否是循环
        while (fast!=null && fast.next!=null){
        	//快指针是否空节点或者下一节点为空
            fast = fast.next.next;
            slow = slow.next;
            //快指针追上慢指针，存在环
            if (fast == slow){
            	//?
                ListNode slow2 = head; 
                while (slow2 != slow){
                    slow = slow.next;
                    slow2 = slow2.next;
                }
                return slow;
            }
        }
        return null;
    }

}
