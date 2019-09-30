//值得注意的就是左子树调整完之后，头结点需要思考一下，也就是说左边做大的值要思考一下！
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;
        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL) return pRootOfTree;
        //翻转左子树并且返回左子树的头结点
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* p = left;
        //把左子树中最大的给左边链表的头部
        while( p != NULL && p->right != NULL){
            p = p->right;
        }
        //左边翻转好的和根链接在一起
        if(left!= NULL){
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        //翻转右边的然后连接起来！
        TreeNode* right = Convert(pRootOfTree->right);
        if(right != NULL){
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        return left != NULL ? left : pRootOfTree;
        
        
    }
};
