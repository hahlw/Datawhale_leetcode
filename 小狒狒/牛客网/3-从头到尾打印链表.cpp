//【方法1】——————库函数（链表>>>数组）——————4ms, 460k
//调用了insert函数
//思想很简单：把链表里的值，一个一个从前往后的取，每次插入到数组的第一个位置！
//
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
       //Step1：建立一个保存值的列表，这里是向量
       vector<int> value;
       //Step2：遍历给定的链表，用head是否为空来进行控制
       while(head)//意思就是只要head非空，就一直遍历到底，因为链表里最后一个是NULL指针
       {
          //这里主要就是每次都把下一个链表ListNode中的值插入到vector的最前面，这样最后一个连标志就是vector的第一个
          value.insert(value.begin(), head->value);
          //移动指针，指向下一个
          head = head -> next;
       }
       //Step3：返回结果
       return value;
    }
};

//【方法2】————————栈（链表>>>栈>>>数组）——————3ms, 484k
//利用栈**先入后出**的特点
//思想：倒腾就行了，链表>>>栈>>>数组
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> value;
        //Step1：准备工作, 建立空指针，用p来指向链表的指针用来移动，建立栈
        ListNode *p = NULL;
        p = head;
        stack<int> stk;
        //Step2：把链表先倒腾到栈里面，顺序导入
        while( p != NULL )
        {
            stk.push(p->val);
            p = p->next;
        }
        //Step3:把栈里的倒腾出来，放在value数组里面
        while( !stk.empty() )
        {
            value.push_back(stk.top());
            stk.pop();
        }
        //Step4:返回数组
        return value;
    }
};

//【方法3】———————翻转（链表>>>数组>>>翻转）——————4ms, 484k
//翻转数组的
//思想：链表>>>数组>>>翻转
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        //Step1:准备工作
        vector<int> value;
        ListNode *p = NULL;
        p = head;
        //Step2:倒腾      链表>>>数组
        while( p != NULL )
        {
            value.push_back(p->val);
            p = p->next;
        }
        //Step3:翻转数组
        //reverse(value.begin(), value.end());
        int temp = 0;
        int i = 0, j = value.size() - 1;
        while( i < j)
        {
            temp = value[i];
            value[i] = value[j];
            value[j] = temp;
            i++;
            j--;
        }
        return value;
    }
};
//【方法4】——递归这个我不懂——————3ms,484k
//思想：自己调用自己啊
class Solution {
public:
    vector<int> value;
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *p=NULL;
        p=head;
        if(p!=NULL){
            if(p->next!=NULL){
                printListFromTailToHead(p->next);
            }
            value.push_back(p->val);
        }
        return value;
    }
};
