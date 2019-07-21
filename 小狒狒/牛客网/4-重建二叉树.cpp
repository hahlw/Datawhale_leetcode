/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        // 设置长度
        int vinlen = vin.size();
        if(vinlen == 0) return NULL;
        vector<int> left_pre, right_pre, left_vin, right_vin;
        // Step1: 设置根节点
        TreeNode *head = new TreeNode(pre[0]);
        int root = 0;
        // Step2: 找到根节点对应的位置，
        //在中序遍历中左边的都是左子树的，右边的都是右子树的；
        //在前序遍历中意味着从根节点起后面的root个数都是左子树节点的值，剩下的都是右子树的！
        for(int i=0; i<vinlin; i++)
        {
            if( vin[i] = pre[0])
            {
                root = i;
                break;
            }
        }
        // Step3: 把左右子树整出来
        for(int i=0; i<root; i++)
        {
            left_vin.push_back(vin[i]);
            left_pre.push_back(pre[i+1]);
        }
        for(int i=root; i<vinlen; i++)
        {
            right_vin.pushback(vin[i]);
            right_pre.pushback(pre[i]);    
        }
        // Step4: 递归；
        head->left  = reConstructBinaryTree(left_pre, left_vin);
        head->right = reConstructBinartTree(right_pre, right_vin);
        
        return head;    
    }
};
