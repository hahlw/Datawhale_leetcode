#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char a[10000004];
int n;
int main()
{
    while(~scanf("%d%*c", &n))
    {
        int x = 0, y = 0, z = 0;
        long long cnt, ans = 1;
        int flag = 0;
        for(int p = 0; p < n; p++)
        {
            gets(a);
            if(flag == 1)
                continue;
            int m = strlen(a);
            for(int i = 0; i < m; i++)
            {
                if(a[i] == '{' && x == 0)
                {
                    x = 1;
                    cnt = 1;
                }
                else if(a[i] == '|' && x == 1)
                    cnt++;
                else if(a[i] == '}' && x == 1)
                {
                    x = 0;
                    ans *= cnt;
                    if(ans > 100000)
                    {
                        flag = 1;
                        break;
                    }
                }
                else if(a[i] == '$' && y == 0)
                    y = 1;
                else if(a[i] == '$' && y == 1)
                    y = 0;
                else if(a[i] == ' ' && y== 1)
                {
                    long long count = 1;
                    while(a[i] == ' ')
                        count++, i++;
                    ans *= count;
                    if(ans > 100000)
                    {
                        flag = 1;
                        break;
                    }
                    i--;
                }
            }
        }
        if(ans > 100000)
            printf("doge\n");
        else
            printf("%I64d\n",ans);
    }
    return 0;
}
