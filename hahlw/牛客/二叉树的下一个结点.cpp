#include<iostream>
using namespace std;
struct TreeLinkNode{
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode)return nullptr;
        TreeLinkNode* tmp = nullptr;
        if(pNode->right){
            tmp = pNode->right;
            while(tmp->left){
                tmp = tmp->left;
            }
            return tmp;
        }
        else if(pNode->next&&pNode->next->left==pNode){
            return pNode->next;
        }
        else if(pNode->next&&pNode->next->right==pNode){
            while(pNode->next){
                if(pNode->next->left==pNode)
                    return pNode->next;
                else
                {
                    pNode = pNode->next;
                }
            }
        }
        return nullptr;
    }
};