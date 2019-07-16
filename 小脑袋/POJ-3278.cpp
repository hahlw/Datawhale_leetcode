#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#define MAX  200050

using namespace std;

queue<int> que;
int cnt[MAX];

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k))
    {
        memset(cnt, 0, sizeof cnt);
        while(!que.empty()) que.pop();
        cnt[n] = 1;
        int x;
/*
队列演示：
5
10 4 6
20 9 11 8 3 5 12 5 7
（40 19 21）（18 8 10）（16 7 9 ）（6 2 4）（10 4 6）（24 11 13）（10 4 6）（14 6 8）
(80 39 41)(38 18 20)(42 20 22)(36 17 19)......
....17....
*/
        for(que.push(n); !que.empty(); que.pop())
        {
            x = que.front();//将队列中第一个数取出
            if(x == k)
                break;
            if(x * 2 <= MAX && !cnt[x * 2])
            {
                cnt[x * 2] = cnt[x] + 1;
                que.push(x * 2);
            }
            if(x - 1 >= 0 && !cnt[x - 1])
            {
                cnt[x - 1] = cnt[x] + 1;
                que.push(x - 1);
            }
            if(x + 1 <= MAX && !cnt[x + 1])
            {
                cnt[x + 1] = cnt[x] + 1;
                que.push(x + 1);
            }
        }
        printf("%d\n", cnt[x] - 1);
    }
    return 0;
}

/*
5 17
*/
