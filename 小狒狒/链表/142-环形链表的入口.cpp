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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* pFast = head;
        ListNode* pSlow = head;
        bool hasCircle = false;
        while(pFast != NULL && pFast->next != NULL){
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if(pFast == pSlow){
                hasCircle = true;
                break;
            }
        }
        if(hasCircle){
            pFast = head;
            while(pFast!= pSlow){
                pFast = pFast->next;
                pSlow = pSlow->next;
            }
            return pFast;
        }else
            return NULL;
    }
};
