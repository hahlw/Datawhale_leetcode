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
            vector<vector<int>> res;  //结果变量
            if(pRoot == NULL) return res;
            queue<TreeNode*> q;       //初始化一个辅助队列
            q.push(pRoot);            //把pRoot压入到辅助队列中
            while(!q.empty()){//只要不为空就循环！
                int low = 0, high = q.size();      //设置俩变量，low是记录层的，q是总平面内
                vector<int> temp;                  //存放每行的变量
                while( low++ < high){
                    TreeNode* t = q.front();       //把队列中的第一个保存到t
                    q.pop();                       //把队列中的第一个删除
                    temp.push_back(t->val);        //把t中刚刚保存的队列中的第一个放到零时结果向量中
                    //如果当前节点有左右子节点，就把它放到q里面！
                    if(t->left) q.push(t->left);   
                    if(t->right) q.push(t->right);
                }
                res.push_back(temp);
            }
            return res;
        }
};
