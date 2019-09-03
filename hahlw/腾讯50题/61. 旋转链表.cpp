#include<iostream>
using namespace std;
  
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tmp = head;
        if(!head||k==0)return head; 
        int cnt = 0;
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        k = k % cnt;
        ListNode *lo = head, *hi = head,*pre;
        while(k--){
            hi = hi->next;
        }
        while(hi->next){
            pre = hi;
            hi=hi->next;
            lo=lo->next;
        }
        hi->next = head;
        head=lo->next;
        lo->next = NULL;
        return head;
    }
};





















