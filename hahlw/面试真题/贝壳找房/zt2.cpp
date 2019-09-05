#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long  v_sum(vector<int>v){
    long long  cur = 0;
    for(auto num:v)
        cur += num;
    return cur;
}
long long  jc(int n){
    if (n==0)
        return 1;
    long long  tmp=1;
    for (int i = 1;i<=n;i++){
        tmp *= i;
    }
    return tmp;
}
long long  GetResult(int K){
    vector<int> tmp{ 2, 1 };
    long long  n = 2;
    long long  jcn = jc(2);
    long long  cur = v_sum(tmp);
    long long k = (long long)K;
    while(cur<=k*jcn){
        n++;
        cur *= n;
        cur += jcn;
        cur /= 10.0;
        jcn *= n;
        jcn /= 10.0;

    }
    return n;
}
int main(){
    long long res;
    int _K;
    while(cin>> _K)
    {res=GetResult(_K);
    cout << res << endl;
    }return 0;
}