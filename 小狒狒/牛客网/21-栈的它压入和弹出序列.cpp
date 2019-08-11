class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        //思想，就是借助一个辅助栈，把压入序列依次压进去，每次栈顶元素都和弹出序列对比，如果相等就弹出，然后弹出序列下一个，一直到遍历完
        if(pushV.empty() || popV.empty() || pushV.size() != popV.size())
            return false;
        
        stack<int> s; //辅助栈
        int j=0;
        for(int i=0; i<pushV.size(); i++){
            s.push(pushV.top());
            while( !s.empty() && s.top() == popV[j]){
                s.pop()
                j++
            }
        }
        if(s.empty())
            return true;
        return false;
    }
};
