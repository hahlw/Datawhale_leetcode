/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()||board[0].empty())return false;
        if(word.size()==0)return true;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>mp(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(helper(board,mp,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board,vector<vector<bool>>&mp,string word,int start,int i,int j){
        if(start==word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||mp[i][j]||board[i][j]!=word[start])return false;
        mp[i][j]=true;
        bool res=helper(board,mp,word,start+1,i-1,j)||
                 helper(board,mp,word,start+1,i+1,j)||
                 helper(board,mp,word,start+1,i,j-1)||
                 helper(board,mp,word,start+1,i,j+1);
        mp[i][j]=false;
        return res;
    }
};

