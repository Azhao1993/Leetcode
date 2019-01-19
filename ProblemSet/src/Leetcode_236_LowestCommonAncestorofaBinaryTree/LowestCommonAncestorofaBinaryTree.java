package Leetcode_236_LowestCommonAncestorofaBinaryTree;

import TreeNode.TreeNode;

/*
	给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。	
	百度百科中最近公共祖先的定义为：
		“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
		满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
	
	例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
	
	图片：https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/binarytree.png	 
	
	示例 1:	
		输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
		输出: 3
		解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
	
	示例 2:	
		输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
		输出: 5
		解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
	
	说明:	
		所有节点的值都是唯一的。
		p、q 为不同节点且均存在于给定的二叉树中。
 */
public class LowestCommonAncestorofaBinaryTree {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(3);
		TreeNode node5 = new TreeNode(5);
		TreeNode node1 = new TreeNode(1);
		TreeNode node6 = new TreeNode(6);
		TreeNode node2 = new TreeNode(2);
		TreeNode node0 = new TreeNode(0);
		TreeNode node8 = new TreeNode(8);
		TreeNode node7 = new TreeNode(7);
		TreeNode node4 = new TreeNode(4);
		root.left = node5;
		root.right = node1;
		node5.left = node6;
		node5.right = node2;
		node1.left = node0;
		node1.right = node8;
		node2.left = node7;
		node2.right = node4;
		LowestCommonAncestorofaBinaryTree lcabt = new LowestCommonAncestorofaBinaryTree();
		lcabt.lowestCommonAncestor(root, node7, node4);
	}

	// 236. 二叉树的最近公共祖先
	/*
	 * 先从上往下遍历，再从下往上回溯
	 */
	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		// 其中一个为root
		if (root == null || root.val == p.val || root.val == q.val) {
			return root;
		}
		//
		TreeNode leftN = lowestCommonAncestor(root.left, p, q);
		TreeNode rightN = lowestCommonAncestor(root.right, p, q);
		if (leftN != null && rightN != null) {
			return root;
		}
		if (leftN == null) {
			return rightN;
		}
		return leftN;
	}
	
	//7ms
    private TreeNode ans;
    public LowestCommonAncestorofaBinaryTree(){
        this.ans = null;
    }
    public boolean recurseTree(TreeNode curr,TreeNode p,TreeNode q){
        if(curr!=null){
            int left = this.recurseTree(curr.left,p,q)?1:0;
            int right = this.recurseTree(curr.right,p,q)?1:0;
            int mid = (curr==p)||(curr==q)?1:0;
            if((left+right+mid) >=2){
                this.ans = curr;
            }
          return (mid + left + right > 0);

        }else
            return false;
    }
    public TreeNode lowestCommonAncestor0(TreeNode root, TreeNode p, TreeNode q) {
        this.recurseTree(root,p,q);
        return this.ans;
    }
}
