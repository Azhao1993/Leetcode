package Leetcode_116_PopulatingNextRightPointersinEachNode;

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
		你可以假设它是一个完美二叉树（即所有叶子节点都在同一层，每个父节点都有两个子节点）。
	示例:	
		给定完美二叉树，		
					     1
					   /  \
					  2    3
					 / \  / \
					4  5  6  7
		调用你的函数后，该完美二叉树变为：		
					     1 -> NULL
					   /  \
					  2 -> 3 -> NULL
					 / \  / \
					4->5->6->7 -> NULL

 */
public class PopulatingNextRightPointersinEachNode {
	public static void main(String[] args) {
		TreeLinkNode root = new TreeLinkNode(1);
		TreeLinkNode node2 = new TreeLinkNode(2);
		TreeLinkNode node3 = new TreeLinkNode(3);
		TreeLinkNode node4 = new TreeLinkNode(4);
		TreeLinkNode node5 = new TreeLinkNode(5);
		TreeLinkNode node6 = new TreeLinkNode(6);
		TreeLinkNode node7 = new TreeLinkNode(7);

		root.left = node2;
		root.right = node3;

		node2.left = node4;
		node2.right = node5;

		node3.left = node6;
		node3.right = node7;

		PopulatingNextRightPointersinEachNode pnrpen = new PopulatingNextRightPointersinEachNode();
		pnrpen.connect(root);
	}
	// 116. 填充同一层的兄弟节点

	// 递归
	public void connect(TreeLinkNode root) {
		// 不存在右节点一定不存在左节点
		if (root == null || root.right == null)
			return;
		// 左子节点的next指向右子节点
		root.left.next = root.right;
		// root存在next节点一定是同层右节点
		if (root.next != null) {
			root.right.next = root.next.left;
		}
		// 递归root的左右子节点
		connect(root.left);
		connect(root.right);

	}
}
