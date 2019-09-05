/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = NULL;
        //找到中点
        while(fast){
            slow = slow->next;
            fast = fast->next ? fast->next->next: fast->next;//
            //fast = fast->next->next;
        }
        while(slow){//翻转
            ListNode* next = slow->next;//保存后面的,防止断链
            slow->next = prev;//翻转指针
            prev = slow;//更新！
            slow = next;//重新连接上
        }
        while(head&&prev){
            if(head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
