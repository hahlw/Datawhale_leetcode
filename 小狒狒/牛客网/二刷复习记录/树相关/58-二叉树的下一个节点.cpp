//这里要区分是不是当前节点是不是由右子树，分为两种情况！要画出来！
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL) return NULL;
        //当前节点有右子树
        if(pNode->right != NULL){
            pNode = pNode->right;
            while(pNode->left != NULL) pNode = pNode->left;
                return pNode;
        }
        
        //当前节点没有右子树的情况
        while(pNode->next != NULL){
            TreeLinkNode* pRoot = pNode->next;
            if(pRoot->left == pNode)
                return pRoot;
            pNode = pNode->next;
        }
        return NULL;
    }
};
