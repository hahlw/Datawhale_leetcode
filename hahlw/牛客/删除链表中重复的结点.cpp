#include<iostream>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead)return NULL;
        if(!pHead->next)return pHead;
        ListNode*node=new ListNode(0);
        node->next=pHead;
        ListNode*cur=pHead;
        ListNode*pre=node;
        while(cur&&cur->next){
            if(cur->val==cur->next->val){
                while(cur->next&&cur->next->val==cur->val){
                    cur = cur->next;
                }
                pre->next=cur->next;
                cur = cur->next;
            }
            else{
                pre=pre->next;
                cur = cur->next;
            }
        }
        return node->next;
    }
};