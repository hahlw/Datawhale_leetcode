class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, 0, "", res);
        return res;
    }
    
    void helper(int n, int l, int r, string cur, vector<string> &res){
        if( r == n){ // l:左括号的数，r:右括号的数
            res.push_back(cur);
            return;
        }
        if(l < n) helper(n, l + 1, r, cur + "(", res);
        if(r < l) helper(n, l, r + 1, cur + ")", res);
    }
};

//【递归】
// 然后主要就是递归的三个条件：
//（1）什么时候添加左括号"(" ?
// ----当左括号的数目小于n的时候
//（2）什么时候添加右括号")" ?
// ----当右括号的数目比左括号的数目小的时候
//（3）什么时候结束递归，添加到结果。
// ----由于递归是先添加左括号，再添加右括号，所以最后的终止条件就是把右括号的数目等于n，这个时候添加！

//才不管你生成的顺序，总之就是先左后右，具体怎么生成随意的~
