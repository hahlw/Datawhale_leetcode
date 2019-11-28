#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

/*
1 2 3 4 5 6 7 8 9 10
1 2 4 5 7 8 10  3 6 9
1 2 5 7 10  4 8
1 2 7 10  5
1 2 10  7
1 2  10
*/

int func(int n, int k) {
        if(n == k)
                return k;
        int kill = func(n - n/k, k);
        return kill + (kill - 1) / (k - 1);
}
int main() {
        int t, n, k;
        while(~scanf("%d", &t)) {
                for(int i = 0; i < t; i++) {
                        scanf("%d%d", &n, &k);
                        printf("%d\n", func(n, k));
                }
        }
        return 0;
}
