#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
        int n, p, k, i;
        scanf("%d%d%d", &n, &p, &k);
        if(p > k+1)
                cout << "<< ";
        i = max(p - k, 1);
        bool flag = false;
        for( ;i <= p+k; i++) {
                if(flag)
                        cout << " ";
                if(i == p)
                        printf("(%d)", p);
                else
                        cout << i;
                flag = true;
        }
        i--;
        if(i < n)
                cout << " >>" << endl;
        else
                cout << endl;
        return 0;
}
