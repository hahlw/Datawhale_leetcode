#include<iostream>
#include<vector>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* node = pHead;
        while(node){
            RandomListNode* tmp = node->next;
            node->next = new RandomListNode(node->label);
            node->next->next = tmp;
            node = node->next->next;
        }
        node = pHead;
        while(node){
            RandomListNode* tmp = node->random;
            if(tmp)
                node->next->random = tmp->next;
            node = node->next->next;
        }
        RandomListNode* newNode=pHead->next;
        node = pHead;
        RandomListNode* tmp;
        while(node){
            tmp=node->next;
            node->next = tmp->next;
            tmp->next = tmp->next != NULL ? tmp->next->next : NULL;
            node = node->next;
        }
        return newNode;
    }
};