package LinkedList;

public class ListNodeUtils {

	public static ListNode creatNode(int[] arr, int n) {
		if (n == 0) {
			return null;
		}
		ListNode head = new ListNode(arr[0]);
		ListNode cur = head;
		for (int i = 1; i < n; i++) {
			cur.next = new ListNode(arr[i]);
			cur = cur.next;
		}
		return head;
	}

	public static void printList(ListNode head) {
		while (head != null) {
			System.out.print(head.val + " -> ");
			head = head.next;
		}
		System.out.println("null");
	}
}
