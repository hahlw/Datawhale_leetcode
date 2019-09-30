//递归，左子树的左子树和右子树的右子树相同，左子树的右子树和右子树的左子树相同就可以！
//大概就是这么个思路！
//加油！
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return helper(pRoot, pRoot);
    }
    bool helper(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;
        return helper(root1->left, root2->right) && helper(root1->right, root2->left);
    }

};
