//还是一样的这样的题一定要了解集中便利的特点！
//后续便利，那就是倒数第一个就是根节点，然后再依次便利，如果比这个小，那就是左子树，反之右子树，当然这里是结合了搜索二叉树的特点！
//然后在递归！
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.empty()) return false;
         
        int root = sequence[sequence.size()-1]; // 找到根节点
         
        // 在二叉搜索树中左子树的结点小于根节点
        vector<int> leftSequence;
        int i = 0;
        for(i = 0;i<sequence.size()-1;i++){
            if(sequence[i] < root)
                leftSequence.push_back(sequence[i]);
            else
                break;
        }
         
        // 在二叉搜索树中右子树的结点大于根节点
        vector<int> rightSequence;
        for(int j = i;j<sequence.size()-1;j++){
            if(sequence[j] > root)
                rightSequence.push_back(sequence[j]);
            else
                return false;
        }
         
        // 如果左子树不为空，则判断左子树是否满足
        bool left = true;
        if(!leftSequence.empty())
            left = VerifySquenceOfBST(leftSequence);
        // 如果右子树不为空，则判断右子树是否满足
        bool right = true;
        if(!rightSequence.empty())
            right = VerifySquenceOfBST(rightSequence);
         
        return (left&&right);       
    }
};
