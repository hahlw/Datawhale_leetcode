/*
先找到中间节点，然后将后半部分倒置，比较前后两部分
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //倒置
        ListNode* cur = slow;
        ListNode* post = cur->next;
        ListNode* pre = NULL;
        while(cur)
        {
            cur->next = pre;
            pre = cur;
            cur = post;
            post = post ? post->next : NULL;
        }
        //比较
        while(pre)
        {
            if(pre->val != head->val) 
                return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};
