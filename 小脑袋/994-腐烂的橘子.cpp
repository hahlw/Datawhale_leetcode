class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        vector<pair<int,int>>open;
        int min(0),all(0);
        int len = grid.size();
        for(int i = 0; i<len; i++)
            for(int j = 0,len2 = grid[i].size(); j<len2; j++)
            {
                if(grid[i][j] == 2)
                    open.push_back(pair<int,int>(i,j));
                if(grid[i][j] == 1)
                    all++;
            }
            vector<pair<int,int>>::iterator it;
            int size;
        while(open.size() && all > 0)
        {
            size = open.size();
            for(int i = 0; i < size; i++)
            {
                it = open.begin();
                int y = (*it).first;
                int x = (*it).second;
                if(x - 1 >= 0 && grid[y][x-1] == 1)
                {
                    all--;
                    grid[y][x-1] = 2;
                    open.push_back(pair<int,int>(y,x-1));
                }
                if(x + 1 < grid[y].size() && grid[y][x+1] == 1)
                {
                    all--;
                    grid[y][x+1] = 2;
                    open.push_back(pair<int,int>(y,x+1));
                }
                if(y - 1 >= 0 && grid[y-1][x] == 1)
                {
                    all--;
                    grid[y-1][x] = 2;
                    open.push_back(pair<int,int>(y-1,x));
                }
                if(y + 1 < len && grid[y+1][x] == 1)
                {
                    all--;
                    grid[y+1][x] = 2;
                    open.push_back(pair<int,int>(y+1,x));
                } 
                open.erase(open.begin());
            }
            min++;
        }
            if(all == 0)
                return min;
            return -1;
    }
};
