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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* merged = NULL;
        if(l1->val <= l2->val){
            merged = l1;
            merged->next = mergeTwoLists(l1->next, l2);
        }else{
            merged = l2;
            merged->next = mergeTwoLists(l1, l2->next);
        }
        return merged;
    }
};
//这个要用递归的思想
//比当前对应位置的大小，然后剩下的就依次递归好了！
