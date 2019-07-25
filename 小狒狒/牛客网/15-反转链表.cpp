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
    ListNode* ReverseList(ListNode* pHead) {
        // Step1：边界检查一，排除空指针
        if(pHead == nullptr)  return NULL;
        // Step2:设置三个指针
        ListNode *pNode = pHead;
        ListNode *pPre  = nullptr; //用来存放上一个的
        ListNode *pReversedHead = nullptr //用来存放翻转后的
        
        //Step3: 进行翻转
        while( pNode != NULL){ //控制循环，直到遍历完整个链表
            ListNode *pNext = pNode->next; //零时的链表，用来保存当前节点之后的链表，防止断了链表
            //排除只有一个节点的非空链表
            if(pNext == NULL){
                pReversedHead = pNode;
            }
            //多个节点的正常翻转，要理解天道好轮回啊！！！
            pNode->next = pPre; //把当前节点的上一个设置为当前节点的下一个
            pPre = pNode; //当前节点自己则伦为下一次进行处理的上一个节点
            pNode = pNext; // 下一次将要处理的节点则为此刻的下一个节点
        }
        return pReversedHead;
        
    }
};
