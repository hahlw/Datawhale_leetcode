class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.empty()) return false;
        // 找到二叉搜索树的根节点
        int root = sequence[sequence.size()-1];
        
        //在找到给定序列中二叉搜索树的左子树
        vector<int> leftSequence;
        int i=0;
        for(;i<sequence.size()-1; i++){
            if(sequence[i]<root){
                leftSequence.push_back(sequence[i]);
            }else
                break;
        }
        //找到二叉搜索树的右子树；
        vector<int> rightSequence;
        for(int j=i; j<sequence.size()-1; j++){
            if(sequence[i]>root){
                rightSequence.push_back(sequence[j]);
            }else
                return false;
        }
        // 如果左子树不为空，则判断左子树是否满足
        bool left = true;
        if(!leftSequence.empty()){
            left = VerifySquenceOfBST(leftSequence);
        }
        // 如果右子树不为空，则判断右子树是否满足
        bool right = true;
        if(!rightSequence.empty()){
            right = VerifySquenceOfBST(rightSequence);
        }
        return (left&&right);
    }
};
