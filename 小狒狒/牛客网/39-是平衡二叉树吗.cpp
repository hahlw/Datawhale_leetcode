//【方法一】最直接简单的，复杂度有点高啊！因为多次遍历了节点！
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL ) return true;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        int diff = left - right;
        if(diff<-1 || diff>1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

    }
    int TreeDepth(TreeNode* pRoot){
        if(pRoot == NULL) return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        
        return 1+(left>right?lef:right）;
    }
};
//【方法二】
//后续遍历二叉树，遍历过程中求子树高度，判断是否平衡
class Solution {
public:
    bool IsBalanced(TreeNode *root, int & dep){
        if(root == NULL){
            return true;
        }
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left,left) && IsBalanced(root->right, right)){
            int dif = left - right;
            if(dif<-1 || dif >1)
                return false;
            dep = (left > right ? left : right) + 1;
            return true;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot, dep);
    }
};
