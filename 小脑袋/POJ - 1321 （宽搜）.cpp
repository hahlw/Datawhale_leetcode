/*
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
Input
输入含有多组测试数据。 
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n 
当为-1 -1时表示输入结束。 
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。 
Output
对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
Sample Input
2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
Sample Output
2
1
*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k,cnt;
char c[102][102];
int fl[102];
int dfs(int x,int y,int num);
int main()
{
    while(cin >> n >> k && n != -1 && k != -1)
    {
        cnt = 0;
        memset(fl, 0, sizeof(fl));
        for(int i = 0; i < n; i++)
        {
            getchar();
            cin >> c[i];
         }
        dfs(0, 0, 1);
        cout << cnt << endl;
    }
    return 0;
}
int dfs(int x, int y, int num)
{
    if(num > k)
    {
        cnt++;
        return 0;
    }
    for(int i = x; i < n; i++)
    {
        for(int j = y; j < n; j++)
        {
            if(!fl[j] && c[i][j] == '#')
            {
                fl[j] = 1;
                dfs(i + 1, 0, num + 1);
                fl[j] = 0;
            }
        }
    }
}
