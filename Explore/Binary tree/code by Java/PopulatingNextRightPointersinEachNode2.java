package Leetcode_117_PopulatingNextRightPointersinEachNode2;

import TreeLinkNode.TreeLinkNode;

/*
	给定一个二叉树
	
	struct TreeLinkNode {
		TreeLinkNode *left;
	  	TreeLinkNode *right;
	  	TreeLinkNode *next;
	}
	
	填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
	如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
	
	初始状态下，所有 next 指针都被设置为 NULL。
	
	说明:	
		你只能使用额外常数空间。
		使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
	示例:	
		给定二叉树，		
		     1
		   /  \
		  2    3
		 / \    \
		4   5    7
		
		调用你的函数后，该二叉树变为：		
		     1 -> NULL
		   /  \
		  2 -> 3 -> NULL
		 / \    \
		4-> 5 -> 7 -> NULL

 */
public class PopulatingNextRightPointersinEachNode2 {
	public static void main(String[] args) {
		TreeLinkNode root = new TreeLinkNode(1);
		TreeLinkNode node2 = new TreeLinkNode(2);
		TreeLinkNode node3 = new TreeLinkNode(3);
		TreeLinkNode node4 = new TreeLinkNode(4);
		TreeLinkNode node5 = new TreeLinkNode(5);
		TreeLinkNode node6 = new TreeLinkNode(6);
		TreeLinkNode node7 = new TreeLinkNode(7);
		TreeLinkNode node8 = new TreeLinkNode(8);

		root.left = node2;
		root.right = node3;

		node2.left = node4;
		node2.right = node5;

		node3.right = node6;

		node4.left = node7;
		node6.right = node8;

		PopulatingNextRightPointersinEachNode2 pnroen2 = new PopulatingNextRightPointersinEachNode2();
		pnroen2.connect(root);
	}

	// 117. 填充同一层的兄弟节点 II

	// 可以将树结构看成金字塔的房间，每层的房间与下面一间或者两间通电，
	// 现在要给每层的房间都通电
	public void connect(TreeLinkNode root) {
		// dummy相当于梯子，负责运输root 和 cur 两个工人
		// root 负责上层，cur 负责下层
		TreeLinkNode dummy = new TreeLinkNode(0);
		TreeLinkNode cur = dummy;
		// root工人在房间里
		while (root != null) {
			// root下层有没有left房间
			if (root.left != null) {
				// cur在云梯dummy上将电线从left房间传入，云梯的next是下层最left的房间
				cur.next = root.left;
				// cur进入left房间
				cur = cur.next;
			}
			// root下层有没有right房间
			if (root.right != null) {
				// root告诉cur有，cur将电线穿入right房间并进入
				cur.next = root.right;
				cur = cur.next;
			}
			// root去本层的下一个房间
			root = root.next;
			// 本层结束
			if (root == null) {
				// root工人通过云梯到下层的最left的房间
				root = dummy.next;

				// cur工人回到云梯
				cur = dummy;
				// 云梯离开根据cur的指示到root的下层最left的房间
				dummy.next = null;
			}
		}
	}

	// 0ms
	public void connect0(TreeLinkNode root) {
		helper(root);
	}

	void helper(TreeLinkNode node) {
		if (node == null)
			return;
		TreeLinkNode next = null;
		if (node.left != null) {
			if (node.right != null) {
				node.left.next = node.right;
			} else {
				next = node.next;
				while (next != null) {
					if (next.left != null) {
						node.left.next = next.left;
						break;
					} else if (next.right != null) {
						node.left.next = next.right;
						break;
					}
					next = next.next;
				}
			}
		}
		if (node.right != null) {
			next = node.next;
			while (next != null) {
				if (next.left != null) {
					node.right.next = next.left;
					break;
				} else if (next.right != null) {
					node.right.next = next.right;
					break;
				}
				next = next.next;
			}
		}
		helper(node.right);
		helper(node.left);
	}
}
