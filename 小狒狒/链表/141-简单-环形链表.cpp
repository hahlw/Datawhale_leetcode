/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //利用set来解决，set和map都是基于红黑树构建的，所以容器中不会出现相同的元素！
 //所以本题的思路就是：遍历链表，
 //针对每一个节点，先检查是不是已经有了，有的话就说明有环，直接返回truw;
 //如果没有的话，那就把心的节点加入到set中！，然后用head= head->next来控制移动到下一个节点！
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode* > list;
        while( head != NULL){
            if(list.count(head))//count返回值就是1（有）或者0（没有）
                return true;
            else
                list.insert(head);//没有的话就给加进去，有的话就返回
            head = head->next;
        }
        return false;      
    }
};
//方法二：快慢指针，快指针一次走两步，慢指针一次走一步，如果连个相遇了！那就是有环的！
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
    bool hasCycle(ListNode *head) {
        if(NULL == head) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
        
    }
};
