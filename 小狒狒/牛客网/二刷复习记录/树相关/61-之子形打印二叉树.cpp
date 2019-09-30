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
        bool even = false;
        
        while(!q.empty()){
            vector<int> temp;
            int low = 0, high = q.size();
            while(low++<high){
                temp.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if(even)
                reverse(temp.begin(), temp.end());
            res.push_back(temp);
            even = !even;
        }
        return res;
    }
};
//上面的代码其实对把二叉树打印成多行的一种改进！
//最红给个reverse!下面的就是经典的做法了！经典方法的思路要明白哦！！！
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
        stack<TreeNode*> levels[2];   //levels[0]和levelsp[1]分别表示保存奇数偶数层的辅助站
        vector<int> curLevel;         //用来保存当前层所有的节点的值
        int current = 0;              //0表示当前遍历的是奇数层，1表示的当前遍历的是偶数层
        int next = 1;
        levels[current].push(pRoot);
        while(!levels[0].empty()|| !levels[1].empty()){
            TreeNode* pNode = levels[current].top();
            levels[current].pop();
            curLevel.push_back(pNode->val);
            if(current == 0){ //如果当前遍历的是奇数层，以此将其左子节点和右子节点保存在辅助栈level[1]中
                if(pNode->left != NULL)
                    levels[next].push(pNode->left);
                if(pNode->right != NULL)
                    levels[next].push(pNode->right);
            }else{            //如果便利的是偶数层，依次将其右子节点和右子节点保存在levels[0]中，
                if(pNode->right != NULL)
                    levels[next].push(pNode->right);
                if(pNode->left != NULL)
                    levels[next].push(pNode->left);
            }
            if(levels[current].empty()){
                current = 1 - current;
                next = 1- next;
                res.push_back(curLevel);
                curLevel.clear();//每次搞完都得清空一下不然就把整个的节点都保存到下一次的了
            }
        }
        return res;
    }
};
