/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
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
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        ListNode *head = new ListNode(0);
       
        ListNode *p = head;

        while(p1 != NULL && p2 != NULL)
        {
            if(p1->val <= p2->val)
            {
                p->next = p1;
                p1 = p1 ->next;

            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }

            p = p->next;
        
        }

        if(p1 == NULL) p->next = p2;
        else
        {
            p->next = p1;
        }
        
        ListNode *r = head->next;
        delete head;
        return r;
    }

};

