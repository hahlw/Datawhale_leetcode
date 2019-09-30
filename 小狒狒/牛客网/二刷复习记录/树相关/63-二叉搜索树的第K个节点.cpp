//中序遍历，左子树找，如果找到了就返回，否则就是根节点，还不是就在右子树里面找，实在还没有那就返回NULL
class Solution {
public:
    int index = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot != NULL){
            TreeNode* node = KthNode(pRoot->left, k);
            if(node != NULL) return node;
            index++;
            if(index == k) return pRoot;
            node = KthNode(pRoot->right, k);
            if(node != NULL) return node;
        }
        return NULL;
    }
};
