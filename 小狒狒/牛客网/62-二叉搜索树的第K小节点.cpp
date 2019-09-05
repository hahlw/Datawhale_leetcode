/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    int index = 0; //计数器
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot != NULL){
            //在左边找
            TreeNode* node = KthNode(pRoot->left, k);
            if(node != NULL) return node;
            index++;
            //对比中间
            if(index == k) return pRoot;
            //在右边找
            node = KthNode(pRoot->right, k);
            if(node != NULL) return node;
        }
        return NULL;
    }
};
