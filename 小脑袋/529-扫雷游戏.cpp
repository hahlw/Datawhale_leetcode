class Solution {
public:
    int count(vector<vector<char>> &board, int x, int y, int n, int m){
        // 计算(x,y)附近的雷的个数
        int ans = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0) 
                    continue;
                int tx = x + i, ty = y + j;
                if(tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] == 'M'){  
                    ans++;
                }
            }
        }
        return ans;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size();
        
        int x = click[0], y = click[1];
        if(board[x][y] == 'M')
            board[x][y] = 'X';
        else
        {
            int c = count(board, x, y, n, m);
            if(c == 0)
            {
                set<pair<int,int>> visited;
                queue<pair<int,int>> myQue;
                myQue.push(make_pair(x,y)); //队列中存储的是待扩散节点
                visited.insert(pair(x,y));
                board[x][y] = 'B';
                while(!myQue.empty()){
                    auto val = myQue.front(); 
                    myQue.pop();
                    for(int i = -1; i <= 1; i++){
                        for(int j = -1; j <= 1; j++){
                            int tx = val.first + i, ty = val.second + j;
                            if(tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] != 'M' && visited.find(make_pair(tx,ty)) == visited.end()){
                                visited.insert(make_pair(tx,ty));
                                int c = count(board, tx, ty, n, m);
                                if(c == 0){
                                    board[tx][ty] = 'B';
                                    myQue.push(make_pair(tx,ty));
                                }
                                else
                                {
                                    board[tx][ty] = '0' + c;
                                }
                            }
                        }
                    }
                }
            }
            else
                board[x][y] = '0' + c;
        }
        return board;
    }
};
