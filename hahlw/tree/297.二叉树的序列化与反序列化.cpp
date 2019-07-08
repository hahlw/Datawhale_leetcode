/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*>q;
        if(root)q.push(root);
        while(!q.empty()){
            TreeNode*t=q.front();q.pop();
            if(t){
                out<<t->val<<' ';
                q.push(t->left);
                q.push(t->right);
            }
            else{
                out<<"# ";
            }
        }
        cout<<out.str();
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        istringstream in(data);
        string val;
        queue<TreeNode*>q;
        in>>val;
        TreeNode* res=new TreeNode(stoi(val)),*cur=res;
        q.push(cur);
        while(!q.empty()){
            TreeNode*t=q.front();q.pop();
            if(!(in>>val))break;
            if(val!="#"){
                cur=new TreeNode(stoi(val));
                q.push(cur);
                t->left=cur;
            }
            if(!(in>>val)) break;
            if(val!="#"){
                cur=new TreeNode(stoi(val));
                q.push(cur);
                t->right=cur;
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

