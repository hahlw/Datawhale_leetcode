#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0 || m<1)return -1;
		if (m == 1)return n-1;
        vector<int>arr(n,1);
        int i = -1, step = 0, count = n;
        while(count>0){
            i++;
            if(i>=n)i = 0;
            if(arr[i]==-1)continue;
            step++;
            if(step==m){
                step=0;
                arr[i] = -1;
                count--;
            }
        }
        return i;
    }
};