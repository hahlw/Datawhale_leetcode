/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//递归
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int res = 0;
        for(int i = 0; i < root->children.size(); i++) 
        {
            Node *node = root->children[i];
            res = max(res, maxDepth(node));
        }
        return res + 1;
    }
};

