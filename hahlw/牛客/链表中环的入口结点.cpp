#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead)return NULL;
        ListNode* lo = pHead;
        ListNode* fa = pHead;
        while(fa&&fa->next){
            fa = fa->next->next;
            lo = lo->next;
            if(lo==fa)
                break;
        }
        if(!fa||!fa->next)
            return nullptr;
        lo = pHead;
        while(lo&&fa){
            if(lo==fa)
                return lo;
            lo=lo->next;
            fa = fa->next;
        }
    }
};