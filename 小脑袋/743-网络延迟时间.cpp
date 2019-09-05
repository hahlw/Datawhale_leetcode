class Solution {
public:
    bool vis[101];
    int min_time[101];
    int map[101][101];
    int res;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        for(int i = 1; i <= N; i++)
            min_time[i] = INT_MAX;
        memset(map, -1, sizeof(map));
        for(auto it: times) 
            map[it[0]][it[1]] = it[2]; 
        dfs(K, 0, N);
        for(int i = 1; i <= N; i++) 
            if(!vis[i]) return -1;
        for(int i = 1; i <= N; i++) 
            res = max(res, min_time[i]);
        return res;
    }
    void dfs(int vex, int cost, int N) {
        if(!vis[vex]||cost<min_time[vex]) 
            min_time[vex] = cost;
        else return;
        vis[vex] = true;
        for(int i = 1; i <= N; i++) 
            if(i != vex && map[vex][i] != -1) 
                dfs(i, cost + map[vex][i], N);
    }
};
