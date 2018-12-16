package Leetcode_707_DesignLinkedList;

import java.util.ArrayList;
import java.util.List;

/*
	设计链表的实现。您可以选择使用单链表或双链表。
	单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。
	如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
	
	在链表类中实现这些功能：	
		get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
		addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
		addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
		addAtIndex(index,val)：
			在链表中的第 index 个节点之前添加值为 val  的节点。
			如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。
		deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。	 
	
	示例：	
		MyLinkedList linkedList = new MyLinkedList();
		linkedList.addAtHead(1);
		linkedList.addAtTail(3);
		linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
		linkedList.get(1);            //返回2
		linkedList.deleteAtIndex(1);  //现在链表是1-> 3
		linkedList.get(1);            //返回3	 
	
	提示：	
		所有值都在 [1, 1000] 之内。
		操作次数将在  [1, 1000] 之内。
		请不要使用内置的 LinkedList 库。
 */

//707. 设计链表
class MyLinkedList {
	//用ArrayList 实现LinkedList
	List<Integer> list;	

    /** Initialize your data structure here. */
    public MyLinkedList() {
    	list = new ArrayList<Integer>();
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) { 
    	if((index<0)||(index>=list.size())) {
    		return -1;
    	}
        return list.get(index);
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        list.add(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
    	list.add(list.size(), val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. 
     * If index equals to the length of linked list, the node will be appended to the end of linked list. 
     * If index is greater than the length, the node will not be inserted. 
     * 
     */
    public void addAtIndex(int index, int val) {
    	if((index<0)||(index>list.size())){
    		return;
    	}
        list.add(index, val);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
    	if((index<0)||(index>=list.size())) {
    		return;
    	}
        list.remove(index);
    }
}

//72ms
class MyLinkedList0 {

    DoublyListNode head;
    DoublyListNode tail;

    /**
     * Initialize your data structure here.
     */
    public MyLinkedList0() {
        head = new DoublyListNode(0);
        tail = new DoublyListNode(0);
        head.next = tail;
        tail.pre = head;
    }

    /**
     * Get the value of the index-th node in the linked list. If the index is invalid, return -1.
     */
    public int get(int index) {
        DoublyListNode node = getNodeAtIndex(index);
        return (node == null || node == tail) ? -1 : node.val;
    }

    /**
     * 自定义一个辅助方法：很重要
     */
    public DoublyListNode getNodeAtIndex(int index) {
        if (index < 0) return null;
        DoublyListNode temp = head;
        for (int i = 0; i <= index; i++) {
            temp = temp.next;
            if (temp == null) return null;
        }
        return temp;//包括了len+1对应tail
    }

    /**
     * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
     */
    public void addAtHead(int val) {
        DoublyListNode node = new DoublyListNode(val);
        head.next.pre = node;
        node.next = head.next;
        head.next = node;
        node.pre = head;
    }

    /**
     * Append a node of value val to the last element of the linked list.
     */
    public void addAtTail(int val) {
        DoublyListNode node = new DoublyListNode(val);
        tail.pre.next = node;
        node.pre = tail.pre;
        node.next = tail;
        tail.pre = node;
    }

    /**
     * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
     */
    public void addAtIndex(int index, int val) {
        DoublyListNode node = getNodeAtIndex(index);
        if (node == null) return;
        if (node == tail) {
            addAtTail(val);
            return;
        }
        DoublyListNode newNode = new DoublyListNode(val);
        node.pre.next = newNode;
        newNode.pre = node.pre;
        newNode.next = node;
        node.pre = newNode;
    }

    /**
     * Delete the index-th node in the linked list, if the index is valid.
     */
    public void deleteAtIndex(int index) {
        DoublyListNode node = getNodeAtIndex(index);
        if (node == null || node == tail) return;
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }

    /**
     * 共用的链表结构ListNode
     */
    private class DoublyListNode {
        int val;
        DoublyListNode pre;
        DoublyListNode next;

        DoublyListNode(int val) {
            this.val = val;
        }
    }

    /**
     * 打印链表
     */
    public void printLinkedList() {
        DoublyListNode headTemp = head.next;
        StringBuilder sb = new StringBuilder();
        while (headTemp != tail) {
            sb.append(headTemp.val).append("-->");
            headTemp = headTemp.next;
        }
        String r = sb.toString();
        System.out.println(r.substring(0, sb.length() - 3));
    }

}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
