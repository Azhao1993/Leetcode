package Leetcode_138_CopyListwithRandomPointer;

/*
	给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
	
	要求返回这个链表的深度拷贝。
	
	 深拷贝与浅拷贝：
	 	将一个对象的引用复制给另外一个对象，一共有三种方式。
	 	第一种方式是直接赋值，第二种方式是浅拷贝，第三种是深拷贝。
	 	
	 	直接赋值：
	 		
	 	浅拷贝：
	 		创建一个新对象，然后将当前对象的非静态字段复制到该新对象，如果字段是值类型的，那么对该字段执行复制；
	 		如果该字段是引用类型的话，则复制引用但不复制引用的对象。因此，原始对象及其副本引用同一个对象。
	 	深拷贝：
	 		1、 基本类型：拷贝其值，比如int、float等。
      		2、 对象：拷贝其地址引用，也就是说此时新对象与原来对象是公用该实例变量。
      		3、 String字符串，其地址引用。但是在修改时，它会从字符串池中重新生成一个新的字符串，原有字符串对象保持不变。
	 	
 */
/**
 * Definition for singly-linked list with a random pointer.
 * 
 */

public class CopyListwithRandomPointer {

	// 138. 复制带随机指针的链表
	// 0ms
	public RandomListNode copyRandomList(RandomListNode head) {
		RandomListNode dummyHead = new RandomListNode(0);
		RandomListNode pre = dummyHead;
		RandomListNode current = head;
		while (current != null) {
			pre.next = deepCopy(current);
			current = current.next;
			pre = pre.next;
		}

		return dummyHead.next;
	}

	private RandomListNode deepCopy(RandomListNode current) {
		RandomListNode newnode = new RandomListNode(current.label);
		if (current.random != null)
			newnode.random = new RandomListNode(current.random.label);
		return newnode;
	}
}
