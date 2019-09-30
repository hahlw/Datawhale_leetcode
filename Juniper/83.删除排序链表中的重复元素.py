#
# @lc app=leetcode.cn id=83 lang=python3
#
# [83] 删除排序链表中的重复元素
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head
        dummy = head
        while head.next:
            if head.val == head.next.val:
                if head.next.next:
                    head.next = head.next.next
                else :
                    head.next = None
            else :
                head = head.next
        return dummy

        
# @lc code=end

