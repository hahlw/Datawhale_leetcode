/**
 * 删除链表的倒数第N个节点
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode h = new ListNode(0);
        h.next = head;
        
        ListNode fast = h;
        ListNode slow = h;
        for(int i=0;i<=n; i++){
            if(fast == null) return null;
            fast = fast.next;
        }
        while(fast != null){
            fast = fast.next;
            slow = slow.next;
        }
        
        if(slow.next != null)
            slow.next = slow.next.next;
        else 
            slow.next = null;
            
        return h.next;
    }
}
