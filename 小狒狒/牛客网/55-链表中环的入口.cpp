/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //【边界检查】，链表为空或者链表只有一个节点，直接return NULL
        if(pHead == NULL || pHead->next == NULL) return NULL;
        //【判断是否有环】设置快慢指针，快指针每次走两步，慢指针每次走一步
        ListNode* pFast = pHead;
        ListNode* pSlow = pHead;
        while( pFast != NULL && pFast->next != NULL){//只要快指针不为空，那就说明可能有环，一直走
            pFast = pFast->next->next;               //换过来说，如果遇到null了说明到头了，那自动结束，就说明没有环
            pSlow = pSlow->next;
            //直到快慢指针相遇，那就说明真的有环！直接结束！
            if(pFast == pSlow) break;
        }
        //【没有环】那就return NULL
        if(pFast!= pSlow) return NULL;
        //【有环】
        pSlow = pHead;//慢指针从链表头出发
        while(pFast != pSlow){//快指针从相遇点出发，此时快慢指针速度一样！
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};
