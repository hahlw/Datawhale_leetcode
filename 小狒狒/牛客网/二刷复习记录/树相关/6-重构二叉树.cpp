//递归，分成小问题，这里就是左右子树，怎么分的话就是要熟悉先序和中序的特点，然后新建变量，要能塞进去！
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int vinLen = vin.size();
        if(vinLen == 0) return NULL;
        vector<int> left_pre, right_pre, left_vin, right_vin;
        TreeNode* resTree = new TreeNode(pre[0]);
        int root = 0;
        for(int i=0; i<vinLen; i++){
            if(vin[i] == pre[0]){
                root = i;
                break;
            }
        }
        for(int i=0; i<root; i++){
            left_vin.push_back(vin[i]);
            left_pre.push_back(pre[i+1]);//这里需要注意！是从i+1开始的！因为把第i个元素给根节点了！
        }
        for(int i=root+1; i<vinLen; i++){
            right_vin.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }
        resTree->left = reConstructBinaryTree(left_pre, left_vin);
        resTree->right = reConstructBinaryTree(right_pre, right_vin);
        return resTree;
    }
};
