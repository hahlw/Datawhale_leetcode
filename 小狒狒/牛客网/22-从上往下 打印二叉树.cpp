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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root = NULL) return res;
        quque<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            res.push_back(q.front()->val);
            
            if(q.front()->left != NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right != NULL){
                q.push(q.front()->right);
            }
            q.pop();//q是队列！加入完之后就要记得更新，删掉！弹出！
        }
        return res;
    }
};
