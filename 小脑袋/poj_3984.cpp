#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#define MAX  105

using namespace std;

struct NOD
{
    int x, y;
} nod, nod1;

NOD uparr[MAX][MAX];
int mp[6][6];
queue<NOD> que;
//方向数组
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
stack<NOD> st;

void bfs()
{
    nod.x = 0;
    nod.y = 0;
    que.push(nod);//将初始位置放入队列
    while(!que.empty())
    {
        nod = que.front();//将队列第一个取出然后删除
        que.pop();
        mp[nod.x][nod.y] = 1;//将这个位置记为1，防止再次回到这个位置
        if(nod.x == 4 && nod.y == 4)
            break;//防止数组越界
        for(int i = 0; i < 4; i++)//四个方向循环
        {
            int tx = nod.x + dx[i];
            int ty = nod.y + dy[i];
            if(tx >= 0 && ty >= 0 && tx < 5 && ty < 5 && !mp[tx][ty])
            {
                nod1.x = tx;
                nod1.y = ty;
                uparr[tx][ty] = nod;//记录符合条件的
                que.push(nod1);//将符合条件的放入队列中
            }
        }
    }
}
void solve()
{
    bfs();
    while(!(nod.x == 0 && nod.y == 0))
    {
        st.push(nod);//将符合条件的坐标压入栈
        nod = uparr[nod.x][nod.y];
    }
    printf("(0, 0)");
    while(!st.empty())
    {
        nod = st.top();
        st.pop();
        printf("\n(%d, %d)", nod.x, nod.y);
    }
}
int main()
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> mp[i][j];
    solve();
    return 0;
}

/*
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/
