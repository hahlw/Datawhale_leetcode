#include<cstdio>

/*
   dp[i] = dp[i+1]*p+dp[i-2]*q+1;
   令t[i] = dp[i+1]-dp[i]
   则t[i] = (t[i+1]*p+t[i-2]*q)
   所以t[i+1] = (t[i]-t[i-2]*q)/p
*/
int main()
{
	float p,sum,t[21],q;
	while(~scanf("%f",&p))
	{
		sum = 0;
		q = 1- p;
		t[0] = 1 / p;
		t[1] = t[0] / p;
		t[2] = t[1] / p;
		sum = t[0] + t[1] + t[2];
		for(int i = 3; i < 20; i++)
		{
			t[i] = (t[i-1] - t[i-3] * q) / p;
			sum += t[i];
		}
		printf("%.6f\n", sum * 2 - t[19]);
	}		
	return 0;
}
