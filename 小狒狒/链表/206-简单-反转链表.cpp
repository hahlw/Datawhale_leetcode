/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
【方法一：常规】，一次遍历，反转指针！注意要先保存指针后面的！然后更新！
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pReversedList = NULL;//要返回的已经反转好的链表
        ListNode* pNode = head;//当前正在操作的节点
        ListNode* pPrve = NULL;//之前的节点
        while(pNode != NULL){
            ListNode* pNext = pNode->next;
            
            if(pNext == NULL) pReversedList = pNode;
            pNode->next = pPrve;
            pPrve = pNode;
            pNode = pNext;
        }
        return pReversedList;
    }
};
三个指针的方法,pNext, pNode, pPrev!然后特别要注意每次要保存pNode之后的,防止断链!
