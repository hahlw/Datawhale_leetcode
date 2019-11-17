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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* pFast = head;
        ListNode* pSlow = head;
        for(int i=0; i<n; i++){
            if(pFast->next){
                pFast = pFast->next;
            }else
                return head->next;
        }
        pSlow = head;
        while(pFast->next){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        pSlow->next = pSlow->next->next;
        return head;
    }
};
//思路，双指针一快一慢，
//注意点：如果删除的就是第一个元素，那就直接return head->next;
//其他就是没有了！主要就是注意边界！
//链表的相关的东西要注意画出来
