/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
            return true;
        if(p!=NULL&&q!=NULL)
        {
            if(p->val!=q->val)
            {
                return false;
            }
            else
            {
                bool flag1 =  isSameTree(p->left,q->left);
                if(flag1== false)
                {
                    return false;
                }
                else
                {
                    return isSameTree(p->right,q->right);
                }
                
            }
            
        }
        else
        {
            return false;
        }
        

    }
};

