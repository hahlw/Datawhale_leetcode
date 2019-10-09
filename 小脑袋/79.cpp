class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();//行
        int n = board[0].size();//列
        vector<vector<bool>> vis(m, vector<bool>(n));//记录是否被使用过
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(i, j, 0, board, word, vis))
                    return true;
            }
        }
        return false;
    }
    //xy表示坐标，index表示单词中字母位置
    bool dfs(int x, int y, int index, vector<vector<char>>& board, string &word,vector<vector<bool>>& vis) {
        int m = board.size();//行
        int n = board[0].size();//列
        if(index == word.size() - 1) //单词遍历结束
            return word[index] == board[x][y];
        if(word[index] == board[x][y]) {
            vis[x][y] == true;//表示使用过
            for(int i = 0; i < 4; i++) {
                //四个方向
                int nx = x + dx[i];
                int ny = y + dy[i];
                //不越界且未使用过
                if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !vis[nx][ny])
                    if(dfs(nx, ny, index + 1, board, word, vis))
                        return true;
            }
            vis[x][y] = false;
        }
        return false;
    }
};




class Solution {
public:
    int dir[4][4]={{-1,0},{1,0},{0,-1},{0,1}};
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();//几行
        int n=board[0].size();//几列
        vector<vector<bool>> visited(m,vector<bool>(n));//是否被访问过              
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,board,word,visited))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(int x,int y,int index,vector<vector<char>>& board,string &word,vector<vector<bool>>& visited){
        if(index==word.size()-1){
            return word[index]==board[x][y];
        }
        
        if(word[index]==board[x][y]){
            visited[x][y]=true;
            for(int i=0;i<4;i++){
                int new_x=x+dir[i][0];
                int new_y=y+dir[i][1];
                
                if(new_x>=0&&new_x<board.size()&&new_y>=0&&new_y<board[0].size()&&!visited[new_x][new_y])
                    if(dfs(new_x,new_y,index+1,board,word,visited))
                        return true;
            }
            visited[x][y]=false;
            
        }
        return false;
    }
};
