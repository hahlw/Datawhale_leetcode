//【方法一】：非递归

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL) return pHead;
        ListNode* head = new ListNode(-2);
        head->next = pHead;
        ListNode* pre = head;
        ListNode* cur = pHead;
        while(cur && cur->next){
            //存在重复元素
            if(cur->val == cur->next->val){
                int val = cur->val;
                while(cur && val == cur->val)
                    cur = cur->next;
                pre->next = cur;
            }else{//不存在重复元素
                pre = cur;
                cur = cur->next;
            }
        }
        return head->next;
    }
};
