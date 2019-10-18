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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if(lenA - lenB < 0){
            ListNode* temp = headA;
            headA = headB;
            headB = temp;
        }
        int gap = abs(lenA - lenB);
        while(gap>0){
            headA = headA->next;
            gap--;
        }
        while( headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;   
    }
    
    int getLength(ListNode* head){
        ListNode* cur = head;
        int length = 0;
        while(cur != NULL){
            length++;
            cur = cur->next;
        }
        return length;
    }
};
