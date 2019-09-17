#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int t = sqrt(c);
        //cout<<t<<endl;
        int lo = 0, hi = t;
        while(lo<=hi){
            long long n = c - lo * lo;
            double res=sqrt(n);
            if(res==int(res))return true;
            if(res>double(hi))lo++;
            else if(res<double(hi))
                hi--;
        }
        return false;
    }
};
