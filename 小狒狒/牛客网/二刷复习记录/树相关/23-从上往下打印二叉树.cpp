//主要的还是要理解    队列
//面矿视的时候就是之字形打印！这个时候就要求一个栈一个队列了！
//拿到题一定要自己先想几分钟！有个思路再动手！
//I am what I am!
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        //Step1:初始化一个保存结果的数组
        vector<int> res;
        //Step2:边界检查，
        if(root == NULL) return res;
        //Step3:初始化一个树队列q
        queue<TreeNode*> q;
        q.push(root);//把树第一个元素放进到队里里面
        //队列不为空是取第一个放入到结果中
        while(!q.empty()){   //用队列是否是空的来控制循环
            res.push_back(q.front()->val);
            //将下一层元素加入到队尾
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            //弹出第一个
            q.pop();
        }
        return res;
    }
};
