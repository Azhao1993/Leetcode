package Leetcode_430_FlattenaMultilevelDoublyLinkedList;

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


 */
public class FlattenaMultilevelDoublyLinkedList {
	public static void main(String[] args) {
		Node node1 = new Node();
		Node node2 = new Node();
		Node node3 = new Node();
		Node node4 = new Node();
		Node node5 = new Node();
		Node node6 = new Node();
		Node node7 = new Node();
		Node node8 = new Node();
		Node node9 = new Node();
		Node node10 = new Node();
		Node node11 = new Node();
		Node node12 = new Node();
		node1 = new Node(1, null, node2, null);
		node2 = new Node(2, node1, node3, null);
		node3 = new Node(3, node2, node4, node7);
		node4 = new Node(4, node3, node5, null);
		node5 = new Node(5, node4, node6, null);
		node6 = new Node(6, node5, null, null);

		node7 = new Node(7, null, node8, null);
		node8 = new Node(8, node7, node9, node11);
		node9 = new Node(9, node8, node10, null);
		node10 = new Node(10, node9, null, null);

		node11 = new Node(11, null, node12, null);
		node12 = new Node(12, node11, null, null);

	}

	// 430. 扁平化多级双向链表
	public Node flatten(Node head) {
		List<Node> list = new ArrayList<Node>();
		while ((head != null) && (head.next != null) && (head.child != null)) {
			
		}
	}

}
