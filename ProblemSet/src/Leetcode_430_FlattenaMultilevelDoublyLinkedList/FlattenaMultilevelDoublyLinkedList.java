package Leetcode_430_FlattenaMultilevelDoublyLinkedList;

import java.awt.Point;
import java.util.ArrayList;
import java.util.List;

import LinkedList.Node;

/*
	您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。
	这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
	
	扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。	 
	
	示例:	
		输入:
			 1---2---3---4---5---6--NULL
			         |
			         7---8---9---10--NULL
			             |
			             11--12--NULL
		
		输出:
			1-2-3-7-8-11-12-9-10-4-5-6-NULL
		 
		
		以上示例的说明:
				
			给出以下多级双向链表:
				图片：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlist.png 			
			我们应该返回如下所示的扁平双向链表:
				图片：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/multilevellinkedlistflattened.png
		
		输入：
			3470--- 121--4724--4285---NULL
					 |     |
					 |    1753---NULL
				     |
				    917-- 721---NULL
		输出：
			3470-121-917-721-4724-1753-4285-NULL

 */
public class FlattenaMultilevelDoublyLinkedList {
	public static void main(String[] args) {
		Node head = new Node(1, null, null, null);
		Node node2 = new Node(2, head, null, null);
		Node node3 = new Node(3, node2, null, null);
		Node node4 = new Node(4, node3, null, null);
		Node node5 = new Node(5, node4, null, null);
		Node node6 = new Node(6, node5, null, null);

		Node node7 = new Node(7, null, null, null);
		Node node8 = new Node(8, node7, null, null);
		Node node9 = new Node(9, node8, null, null);
		Node node10 = new Node(10, node9, null, null);

		Node node11 = new Node(11, null, null, null);
		Node node12 = new Node(12, node11, null, null);

		head.next = node2;
		node2.next = node3;
		node3.next = node4;
		node3.child = node7;
		node4.next = node5;
		node5.next = node6;
		node7.next = node8;
		node8.next = node9;
		node8.child = node11;
		node9.next = node10;
		node11.next = node12;

		FlattenaMultilevelDoublyLinkedList fmdll = new FlattenaMultilevelDoublyLinkedList();
		fmdll.flatten(head);

	}

	// 430. 扁平化多级双向链表
	public Node flatten(Node head) {

	}

	// 递归
	public Node flatten3(Node head) {
		if (head == null) {
			return head;
		}
		Node points = head;
		Node next = null;
		while (points.next != null) {
			points.next.prev = points;
			// 将子节点设计为下一个节点
			if (points.child != null) {
				next = points.next;
				points.child.prev = points;
				points.next = flatten(points.child);
				points.child = null;
				points = points.next;
			} else {
				points = points.next;
			}
		}
		if (next != null) {
			points.next = flatten(next);
		}

		return head;

	}

	public Node flatten2(Node head) {
		if (head == null) {
			return head;
		}
		List<Node> nextlist = new ArrayList<Node>();
		// Node result = new Node(0,null,head,null);
		Node points = head;
		while (points.next != null) {
			// 将子节点设计为下一个节点
			if (points.child != null) {
				nextlist.add(points.next);
				points.next = points.child;
				points.child = null;
				points.next.prev = points;
				points = points.next;
			} else {
				points = points.next;
			}
		}
		//
		for (int i = nextlist.size() - 1; i >= 0; i--) {
			points.next = nextlist.get(i);
			points.next.prev = points;
			points = points.next;
			while (points.next != null) {
				points = points.next;
			}
		}
		return head;

	}

}
