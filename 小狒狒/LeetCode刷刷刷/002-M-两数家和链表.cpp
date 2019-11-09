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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);//存放结果的链表
        ListNode* h = head;//移动的指针
        int sum = 0; //当前位对应的总和
        bool carry = false;//是否进位
        //如果不为空就进行操作
        while(l1 != NULL || l2 != NULL){
            sum = 0;
            //如果l1不空那就加当前位的，
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            //然后如果l2不为空就再加l2位的
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            //如果还有上一次的进位，再继续加！
            if(carry)
                sum++;
            h->next = new ListNode(sum % 10);// 个位的值应该是sum对10取余的结果！
            h = h->next;                     // 然后走到十位
            carry = sum>=10?true:false;      // 把进位的考虑到！
        }
        //如果到了最高位还有进位，那就要再进一位！
        if(carry){
            h->next = new ListNode(1);
        }
        //虽然是对h进行了操作，但是h = head的！所以最后就返回head!就好啦！
        return head->next;
    }
};
