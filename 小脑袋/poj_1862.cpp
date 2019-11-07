//提交不上。。对错明天再看

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

bool cmp(float a, float b) {
	return a > b;
}

float num[110];

int main()
{
	int N;
	float ans;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		std::cin >> num[i];
	std::sort(num, num + N, cmp);
	if(N >= 2) {
		ans = 2 * sqrt(num[0]*num[1]);
		for(int i = 2; i <= N - 1; i++) {
			std::sort(num, num + N, cmp);
			ans = 2 * sqrt(ans * num[i]);
		}
	}
	else
		ans = num[0];
	printf("%.3f\n", ans); 
	return 0;
} 
