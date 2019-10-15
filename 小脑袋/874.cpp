//我表示没看懂题意，参考大佬解释
class Solution {
public:

/*
*题意说明
*1.障碍物数组是[[x1,y2],[x2,y2],...,[xn,yn],...]这样的结构，其中每个二元组代表一个障碍的x和y坐标
*2.机器人机器人在前进的过程中遇到障碍会原地踏步，直到转向。 
*3.要求的不是机器人执行完指令序后最终的位置到初始位置的欧式距离，而是整个过程中所达到最大欧式距离。
*/
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
         // 移动距离为9， 模拟即可。
        set<pair<int, int>> mySet;
        for(int i=0; i<obstacles.size(); i++){
            mySet.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }
        // 这里没有指明那个是x轴，那个是y轴。 这里任意指定0-x,1-y;反之也对
        // 记录四个方向 顺时针 up right down left
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int x = 0, y = 0;
        int ans = 0;
        int direct = 0;
        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == -2){
                // 左转
                direct = (direct + 4 - 1) % 4;
            }
            else if(commands[i]==-1) {
                // 右转
                direct = (direct + 1) % 4;
            }
            else{
                for(int j = 0; j < commands[i]; j++) {
                    auto tmp = make_pair(x + dx[direct], y + dy[direct]);
                    if(mySet.empty() || mySet.find(tmp) == mySet.end()){
                        x = tmp.first; y = tmp.second;
                        ans = max(ans, x*x+y*y);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
