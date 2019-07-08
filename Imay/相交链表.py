# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
		#方法二：
        '''
        if headA==None or headB==None:
            return None
        p=headA
        count1=0
        while p:
            count1+=1
            p=p.next
        q=headB
        count2=0
        while q:
            count2+=1
            q=q.next
        if count1<count2:
            headA,headB=headB,headA
            count1,count2=count2,count1
        while count1>count2:
            headA=headA.next
            count1-=1
        #循环教短的链表
        while headA:
            if headA==headB:
                return headA
            else:
                headA,headB=headA.next,headB.next
        return None
        '''
        #方法二：
        if not headA or not headB:
            return None
        # 定义两个指针，第一轮让两个到达末尾的节点指向另一个链表的头部，最后如果想遇则为交点。
        # 两个指针等于移动了相同的距离, 有交点就返回, 无交点就是各走了两条指针的长度。
        pa, pb = headA, headB
        while pa != pb:
            pa = pa.next if pa else headB
            pb = pb.next if pb else headA
        return pa
    
    
        if not headA or not headB:
            return None
       