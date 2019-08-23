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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL) return pHead;//排除空链表或者只有一个元素的链表
        //Step1:自己初始化一个辅助链表
        ListNode* head = new ListNode(-1);//初始化一个辅助链表
        head->next = pHead; //把已知节点拷贝过来
        //Step2:安排两个指针
        ListNode* pre = head; //pre指向当前不重复的节点
        ListNode* cur = pHead;//cur指向当前正在处理的节点
        //Step3:功能实现
        while(cur && cur->next){//当前指针指向的节点不为空且存在下一个节点！，那就继续！
            //存在重复元素就删了
            if(cur->val == cur->next->val){
                int val = cur->val;
                while(cur && val == cur->val)
                    cur = cur->next;
                pre->next = cur;
            }else{//不存在重复元素就往后走！
                pre = cur;
                cur = cur->next;
            }
        }
        return head->next;
    }
};
