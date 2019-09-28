//交换，然后递归！
//当然也不能忘记边界条件！树为空或者树只有一个节点的时候！
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL)) return;
        
        TreeNode* pTemp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTemp;
        
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);
    }
};
