#include <iostream>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        if(p==root||q==root)return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL)return root;
        else if(left!=NULL)return left;
        else return right;
        return NULL; 
    }
};

class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return root;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        TreeNode* cur1 = root;
        TreeNode* cur2 = root;
        TreeNode* prePop1 = root;
        TreeNode* prePop2 = root;
        s1.push(root);
        s2.push(root);
        while(cur1 != p){
            if(!cur1 -> left && !cur1 -> right){
                s1.pop();
                prePop1 = cur1;
                cur1 = s1.top();
                continue;
            } 
            if(prePop1 == cur1 -> right || (prePop1 == cur1 -> left && cur1 -> right == NULL)){
                s1.pop();
                prePop1 = cur1;
                cur1 = s1.top();
                continue;
            }  
            if(cur1 -> left == NULL || prePop1 == cur1 -> left){
                if(cur1 -> right){
                    s1.push(cur1 -> right);
                }
                else{
                    s1.pop();
                    prePop1 = cur1;
                }
                cur1 = s1.top();
                continue;
            }
            if(cur1 -> left){
                s1.push(cur1 -> left);
            }
            cur1 = s1.top();
        }

        while(cur2 != q){
            if(!cur2 -> left && !cur2 -> right){
                s2.pop();
                prePop2 = cur2;
                cur2 = s2.top();
                continue;
            }
            if(prePop2 == cur2 -> right || (prePop2 == cur2 -> left && cur2 -> right == NULL)){
                s2.pop();
                prePop2 = cur2;
                cur2 = s2.top();
                continue;
            }
            if(cur2 -> left == NULL || prePop2 == cur2 -> left){
                if(cur2 -> right){
                    s2.push(cur2 -> right);
                }
                else{
                    s2.pop();
                    prePop2 = cur2;
                }
                cur2 = s2.top();
                continue;
            }
            if(cur2 -> left){
                s2.push(cur2 -> left);
            }
            cur2 = s2.top();
        }      
        int l = s1.size() - s2.size();
        if(l > 0){
            while(l--){
                s1.pop();
            }
        }
        else{
            l = -l;
            while(l--){
                s2.pop();
            }
        }
        while(!s1.empty() && !s2.empty()){
            if(s1.top() == s2.top()){
                return s1.top();
            }
            else{
                s1.pop();
                s2.pop();
            }
        }
        return root;
    }
};

