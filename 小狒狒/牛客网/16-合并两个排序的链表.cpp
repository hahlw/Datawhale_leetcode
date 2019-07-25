/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        //Step1: 边界检查，考虑特殊情况,这里也包含了两种情况：
        //       case1:某一个是空链表，那就返回另外一个；
        //       case2:两个都是空链表，那就只能返回空链表咯
        if(pHead1 == nullptr){
            return pHead2;
        }else if(pHead2 == nullptr){
            return pHead1;
        }
        
        //Step2:调用递归来处理！
        ListNode *pMergedHead = nullptr;
        
        if(pHead1->vale < pHead2->val){
            pMergedHead = pHead1;
            pMergedHead->next = Merge(pHead1->next, pHead2);
        }else{
            pMergedHead = pHead2;
            pMergedHead->next = Merge(pHead1, pHead2->next);
        }
        return pMergedHead;
    }
};
