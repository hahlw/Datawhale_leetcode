#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int max_step = 0;

int mstep(vector<vector<int>>& v,int i,int j ,int K,int step){
    int left = 0, right = 0, up = 0, down = 0;
    int n=v.size();
    int m = v[0].size();
    if(i>0){
        if(v[i][j]<v[i-1][j])
            left = mstep(v, i - 1, j, K, step + 1);
        else {
            if(K>0)
                left=mstep(v, i - 1, j, K-1, step + 1);
            else
                return step;
        }
    }
    if(i<n-1){
        if(v[i][j]<v[i+1][j])
            right = mstep(v, i +1, j, K, step + 1);
        else {
            if(K>0)
                right=mstep(v, i +1, j, K-1, step + 1);
            else
                return step;
        }
    }
    if(j>0){
        if(v[i][j]<v[i][j-1])
            up = mstep(v, i, j-1, K, step + 1);
        else {
            if(K>0)
                up=mstep(v, i, j-1, K-1, step + 1);
            else
                return step;
        }
    }
    if(j<m-1){
        if(v[i][j]<v[i][j+1])
            down = mstep(v, i, j+1, K, step + 1);
        else {
            if(K>0)
                down=mstep(v, i, j+1, K-1, step + 1);
            else
                return step;
        }
    }

    return max(max(left, right), max(up, down));

} 
int main()
{

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> mp(N, vector<int>(M));
    int a;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++){
            cin >> a;
            mp[i][j] = a;
        }
    }
    int step = mstep(mp, 0, 0, K, 1);
    cout << step;
    return 0;
}