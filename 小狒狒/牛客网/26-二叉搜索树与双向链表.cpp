/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        if(pRootOfTree->left == nullptr &&pRootOfTree->right == nullptr)
            return pRootOfTree;
        //1.将左子树构造成双链表，并返回链表的头结点
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* p = left;
        //2.定位到左子树双链表的最后一个节点
        while(p != nullptr && p->right != nullptr){
            p = p->right;
        }
        //3.如果左子树链表不为空的话，将当前root追加到左子树的链表中
        if(left!=nullptr){
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        //4.将右子树构造成双链表，并返回链表头结点
        TreeNode* right = Convert(pRootOfTree->right);
        //5.如果右子树不为空的话，就把右子树的链表追加到root节点之后
        if(right!=nullptr){
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        return left!=nullptr?left:pRootOfTree;

    }
};
