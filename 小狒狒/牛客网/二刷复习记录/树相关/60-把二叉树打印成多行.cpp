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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if(pRoot == NULL) return res;
            queue<TreeNode*> q;
            q.push(pRoot);
            
            while(!q.empty()){
                int low=0, high = q.size();//这里与层序打印二叉树的唯一区别应该就是这里了把！
                vector<int> temp;
                while(low++<high){
                    temp.push_back(q.front()->val);
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            res.push_back(temp);
            }
            return res;
        }
};
