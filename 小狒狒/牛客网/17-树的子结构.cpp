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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //Step1:设置一个标识
        bool res = false;
        //Step2:遍历二叉树，寻找A树中与B树头结点相等的节点！在遇到相等节点时候就判断是否具有子结构（1）！
        if(pRoot1 != nullptr && pRoot2 != nullptr){
            //(1)遇到相等节点就判断A是否具有B的子结构——递归终止条件
            if(Equal(pRoot1->val, pRoot2->val)){
                res = DoesTree1HasTree2(pRoot1, pRoot2);
            }
            //(2)如果当前节点不行，那就递归找A树的当前节点的左孩子来比
            if(!res){
                res = HasSubtree(pRoot1->left, pRoot2);
            }
            //(3)如果当前节点本身和左孩子都不相等，那就递归找右孩子来比
            if(!res){
                res = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return res;
    }
    //Step3:判断的具体过程：
    bool DoesTree1HasTree2(TreeNode *pRoot1, TreeNode *pRoot2){
        //(1)相等的时候如果B树是空树，那肯定是A树的子树——递归的终止条件；
        if(pRoot2 == nullptr)
            return true;
        //(2)相等的时候如果A树本身是空树，那就凉凉——递归的终止条件
        if(pRoot1 == nullptr)
            return false;
        //(3)迭代过程中如果发生值不相等，那也就没了——判断的终止条件
        if(!Equal(pRoot1->val, pRoot2->val)){
            return false;
        }
        //(4)否则如果也不是空的，而且值也相等，那就看看子树是不是相等！只有比到B树为空才能为止（1）！比到A树为空（2）那就不行。
        return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
    }
    bool Equal(double num1, double num2){
        if((num1 - num2 > -0.0000001) && (num1-num2 < 0.0000001))
            return true;
        else{
            return false;
        }
    }
};
