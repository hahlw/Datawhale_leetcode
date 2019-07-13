#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#define MAX  1200

using namespace std;
/*
注意点：
1、要把走过的坐标记录下来，便于之后输出，记录在nod[MAX]里面
2、走完所有的格子就能结束，用cnt来记录
3、不明错因，妈的！！！！！凭啥我不用bool就不对，妈的，明明意思还是一样的的
*/
int N, M, cnt, flag;
int dx[] = {-1,  1, -2,  2, -2, 2, -1, 1};
int dy[] = {-2, -2, -1, -1,  1, 1,  2, 2};
char ch = 'A';
int already[MAX][MAX];

struct NOD
{
    int x, y;
} nod[MAX];

void dfs(int x, int y, int cnt)
{
    nod[cnt].x = x;
    nod[cnt].y = y;
    if(cnt == M * N)
    {
        flag = 1;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx > 0 && ty > 0 && tx <= N && ty <= M && !already[tx][ty] && !flag)
        {
            already[tx][ty] = 1;
            dfs(tx, ty, cnt + 1);
            already[tx][ty] = 0;//回溯
        }
    }
}

int main()
{
    int n;
    memset(already, 0, sizeof already);
    while(~scanf("%d", &n))
    {
        int Case = 1;
        while(n--)
        {
            cnt = 1;
            scanf("%d%d", &N, &M);
            already[1][1] = 1;
            flag = 0;
            dfs(1, 1, 1);
            printf("Scenario #%d:\n", Case++);
            if(flag)
            {
                for(int i = 1; i <= M * N; i++)
                    printf("%c%d", ch + nod[i].y - 1, nod[i]. x);
                printf("\n");
            }
            else
                printf("impossible\n");
            if(n)
                printf("\n");
        }
    }
    return 0;
}

/*
3
1 1
2 3
4 3
*/
