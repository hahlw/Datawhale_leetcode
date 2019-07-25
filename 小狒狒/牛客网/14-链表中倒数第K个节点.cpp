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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//【思路】想象一下：就是找一把长度为K的尺子，把尺子划过链表
// 当尺子头部抵达链表尾巴的时候，尺子的尾巴就是倒数第K的节点！

        //Step1:边界考察，如果给的链表本来就是空的或者给的K是<=0的，那就直接返回空指针就好了！
        if(pListHead == nullptr || k <=0 ) return nullptr; 
        
        //Step2:初始化两个指针，一快一慢，快的在前面，Ahead,慢的再后面Behind
        ListNode *pAhead = pListHead;
        ListNode *pBehind = nullptr;
        
        //Step3:先让快指针，前面的指针先走到第K的位置
        for( unsigned int i=0; i<k-1; i++){
            if(pAhead->next != nullptr){
                pAhead = pAhead->next;
            }else{
                return nullptr;
            }
        }
        //Step4:快指针已经到位了，轮到慢指针走了！一直到快指针走到头！当下慢指针的位置就是倒数第K个
        pBehind = pListHead;      
        while(pAhead->next == NULL){
            pAhead = pAhead->next;
            pBehind =pBehind->next;
        }
        return pBehind;
    }
};
