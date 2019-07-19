class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head
        
        prev = head
        prob = head.next
        while prob:
            while prob and prob.val == prev.val:
                prob = prob.next
            prev.next = prob
            prev = prev.next
            if prob:
                prob = prob.next
        
        return head

