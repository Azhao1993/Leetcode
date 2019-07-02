package Leetcode_445_AddTwoNumbersII;

import java.util.Stack;
import java.util.Stack;

import LinkedList.ListNode;

/*
	给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。
	它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。 
	
	你可以假设除了数字 0 之外，这两个数字都不会以零开头。
	
	进阶:
		如果输入链表不能修改该如何处理？
		换句话说，你不能对列表中的节点进行翻转。
	
	示例:
		输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
		输出: 7 -> 8 -> 0 -> 7
	
	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/add-two-numbers-ii
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public class AddTwoNumbersII {
	// 445. 两数相加 II
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

		Stack<Integer> stack1 = new Stack<>();
		Stack<Integer> stack2 = new Stack<>();
		while (l1 != null) {
			stack1.push(l1.val);
			l1 = l1.next;
		}
		while (l2 != null) {
			stack2.push(l2.val);
			l2 = l2.next;
		}

		int flag = 0;
		ListNode head = null;
		while (!stack1.isEmpty() || !stack2.isEmpty() || flag != 0) {
			int a = stack1.isEmpty() ? 0 : stack1.pop();
			int b = stack2.isEmpty() ? 0 : stack2.pop();
			int sum = a + b + flag;
			ListNode temp = new ListNode(sum % 10);
			flag = sum / 10;
			temp.next = head;
			head = temp;
		}
		return head;
	}
}
