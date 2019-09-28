class Solution {
public:
    bool helper(TreeNode* root, int &dep){//注意这里要取depth的地址！！！！
        if(root == NULL) return true;
        int left=0, right=0;
        if(helper(root->left, left) && helper(root->right, right)){
            int diff = left - right;
            if(diff>1 || diff <-1)
                return false;
            dep = (left>right?left:right) + 1;
            return true;
        }
        return false;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return helper(pRoot, depth);
    }
};

//还有一种比较容易接受的方法：
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int depthL = maxDepth(root->left);
        int depthR = maxDepth(root->right);
        int res = depthL - depthR;
        if (res <-1||res>1)
            return false;
        else 
            return isBalanced(root->left)&&isBalanced(root->right);
    }
    int maxDepth(TreeNode* node){
        int depth = 0;
        if(node == NULL){
            return 0;
        }else{
            depth = max(maxDepth(node->left), maxDepth(node->right));
        }
        return depth + 1;
    }
};
