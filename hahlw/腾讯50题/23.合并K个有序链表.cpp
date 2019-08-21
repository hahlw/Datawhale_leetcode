
 #include<iostream>
 #include<vector>
 using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }

    ListNode*merge(ListNode*l1,ListNode*l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        ListNode* node = new ListNode(-1);
        ListNode* head = node;
        while(l1&&l2){
            if (l1->val<=l2->val){
                ListNode* tmp = l1->next;
                node->next=l1;
                node=node->next;
                node->next = NULL;
                l1 = tmp;
            }
            else{
                ListNode* tmp = l2->next;
                node->next=l2;
                node = node->next;
                node->next = NULL;
                l2 = tmp;
            }
        }
        if(l1)
            node->next = l1;
        else if(l2){
            node->next = l2;
        }
        return head->next;
    }
};