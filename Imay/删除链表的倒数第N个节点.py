# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        '''
        l=[]
        cur=head
        while cur:
            l.append(cur)
            cur=cur.next
        if n==len(l):
            head=head.next
        else:
            l[-n-1].next = l[-n-1].next.next
        return head
            
        
        
        '''
        '''
�������ͷ��㷽��ɾ����һ���ڵ�
�ҵ�������n���ڵ��ǰһ���ڵ�(Ҳ���ǵ���n+1�ڵ�) ָ������n���ڵ����һ���ڵ�
����ָ��
         '''
        dummy=ListNode(0)
        dummy.next=head
        p,q=dummy,dummy
        
        for i in range(n+1): #��ָ������n��
            q=q.next
        while q:            #����ָ��ͬʱ��
            q=q.next        
            p=p.next
        p.next=p.next.next #ֱ�Ӱѵ�����N����ȥ��
        return dummy.next  #����dummy����һ����
    