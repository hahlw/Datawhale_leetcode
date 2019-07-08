# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #终止条件：链表只剩一个节点或者没节点了，没得交换了。返回的是已经处理好的链表
        '''
        if not head or not head.next:
            return head
        dummy,dummy.next=self,head #或者是self
        while dummy.next and dummy.next.next:
            a=dummy.next
            b=dummy.next.next
            dummy.next,b.next,a.next=b,a,b.next
            dummy=a
        return dummy.next
        '''
        if not head or not head.next:
            return head
        dummy=ListNode(0)
        dummy.next=head
        cur1=dummy
        cur2=head
        while cur2 and cur2.next:
            new_start=cur2.next.next
            cur1.next=cur2.next 
            cur2.next.next=cur2
            cur2.next=new_start
            cur1=cur2
            cur2=cur2.next
        return dummy.next
            
            
    
        '''
        if not head: return None
        if not head.next: return head
        ans = head.next
        #一共三个节点:head, ans, swapPairs(ans.next)
        #下面的任务便是交换这3个节点中的前两个节点
        head.next = self.swapPairs(ans.next)
        ans.next = head
        return ans
        '''