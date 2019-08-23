/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL) return NULL;
        //当前节点有右子树大情况
        if(pNode->right != NULL){
            pNode = pNode->right;
            while(pNode->left != NULL) pNode = pNode->left;
                return pNode;
        }
        //对应当前节点没有右子树的大情况
        while(pNode->next != NULL){//大前提是父节点不为空
            TreeLinkNode* proot = pNode->next;
            //代码刚开始看着难受，可以背下来！
            if(proot->left == pNode)//如果没有右子树且是父节点的右节点，麻烦！下一个节点是proot，是当前节点的父节点的左节点的节点
                return proot;
            pNode=pNode->next;//没有右子树且是父节点的左节点，那下一个节点就是父节点！
        }
        return NULL;
    }
};
