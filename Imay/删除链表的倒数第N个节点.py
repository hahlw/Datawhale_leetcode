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
添加虚拟头结点方便删除第一个节点
找到倒数第n个节点的前一个节点(也就是倒数n+1节点) 指向倒数第n个节点的下一个节点
快慢指针
         '''
        dummy=ListNode(0)
        dummy.next=head
        p,q=dummy,dummy
        
        for i in range(n+1): #快指针先走n步
            q=q.next
        while q:            #快慢指针同时走
            q=q.next        
            p=p.next
        p.next=p.next.next #直接把倒数第N个数去掉
        return dummy.next  #返回dummy的下一个数
    