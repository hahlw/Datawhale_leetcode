//【方法一：递归】
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root == NULL) 
            return depth;
        else
            depth = max(maxDepth(root->left), maxDepth(root->right));
        return depth+1;     
    }
};
//【方法二：常规方法】借助了队列，这里我觉得还是第一种递归的方法好！简直就是很巧妙！
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            for(int i=0; i<q.size(); i++){
                TreeNode* cur = q.front();
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
                q.pop();
            }
            depth++;
        }
        return depth;
    }
};
