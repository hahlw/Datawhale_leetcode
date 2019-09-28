//这个思路是要由的啊！
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res = false;
        if(pRoot2 != NULL && pRoot1 != NULL){
            if(pRoot1->val == pRoot2->val)
                res = DoesTree1HasTree2(pRoot1, pRoot2);
            if(!res)
                res = DoesTree1HasTree2(pRoot1->left, pRoot2);
            if(!res)
                res = DoesTree1HasTree2(pRoot1->right, pRoot2);
        }
        return res;
    }
    bool DoesTree1HasTree2(TreeNode* root1, TreeNode* root2){
        if(root2 == NULL) return true;
        if(root1 == NULL) return false;
        if(root1->val != root2->val) return false;
        return DoesTree1HasTree2(root1->left, root2->left) && DoesTree1HasTree2(root1->right, root2->right);
    }
};
