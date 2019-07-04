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
        int depth = 9;
        if(node == NULL){
            return 0;
        }else{
            depth = max(maxDepth(node->left), maxDepth(node->right));
        }
        return depth + 1;
    }
};
/**思路：
*想要解答这道题，就要知道什么是平衡二叉树，题目中给出了二叉树的定义：
*那就是每个节点的两个子树的高度差不能大于1，所以这个就是判定条件，
* - 如果满足，那么就是平衡二叉树；
* - 如果不满足，就不是平衡二叉树；
*那么现在的问题就是变成了，给定第一个节点的左右 两个子树的深度的问题了，所以用递归的策略，不断的去调用自己然后获得两个子树的深度，这个思路来自于第104的一道题目：二叉树的最大深度：
*利用那道题的求解二叉树的深度的思想来计算各子树的深度，然后进行比较！
*当然也要注意边界检查，首先排除节点不为空的情况，自己忘记判断了第一次，代码怎么也过不了，差了一下报错原因才解决掉！
*
*/


