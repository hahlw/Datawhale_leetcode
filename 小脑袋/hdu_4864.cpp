#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
//价格=500*x+2*y,y<=100,所以y最大的影响就是200，比500*x影响小很多，所以可以主要考虑xi的最大
const int N = 10000001;

struct work{
	int x, y;
}marr[N], tarr[N];

bool cmp(work a, work b) {
	if(a.x == b.x)
		return a.y > b.y;
	return a.x > b.x;
}

int main()
{
	int n, m;
	int arr[N];
	while(~scanf("%d%d", &n, &m)) {
		memset(arr, 0, sizeof arr);
		for(int i = 0; i < n; i++) 
			scanf("%d%d", &marr[i].x, &marr[i].y);
		for(int i = 0; i < m; i++)
			scanf("%d%d", &tarr[i].x, &tarr[i].y);
		sort(marr, marr + n, cmp);
		sort(tarr, tarr + m, cmp);
		int ans = 0;
		int num = 0;
		int l = 1;
		for(int i = 0; i < m; i++) {
			while(l <= n && marr[l].x >= tarr[i].x) {
				arr[marr[l].y]++;
				l++;
			}
			for(int j = tarr[i].y; j <= 100; j++) {
				if(arr[j]) {
					num++;
					ans += 500 * tarr[i].x + 2 * tarr[i].y;
					arr[j]--;
					break;
				}
			}
			printf("%d %d\n", num, ans);
		}
	}
	return 0;
}
