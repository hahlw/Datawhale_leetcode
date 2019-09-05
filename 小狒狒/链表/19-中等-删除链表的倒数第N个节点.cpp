/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//两个指针走起！注意这里最重要的就是辅助ListNode了！不然总是跑不通！
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pAsis = new ListNode(0);
        pAsis->next = head;
        ListNode* pAhead = pAsis;
        ListNode* pBehind = pAsis;
        
        for(int i=0; i<=n; i++){
            pAhead = pAhead->next;
        }
        
        while(pAhead){
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        pBehind ->next = pBehind->next->next;
        return pAsis->next;
    }
};
