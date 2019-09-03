#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<map>
using namespace std;
vector<int> k_min(vector<int>v){
    vector<int>res;
    res.push_back(*min_element(v.begin(), v.end()));
    for (int k = 1; k < v.size();k++){
        for (int i = 0; i < v.size()-k;i++){
            v[i] = max(v[i], v[i + 1]);
        }
        res.push_back(*min_element(v.begin(), v.end() - k));
    }
    return res;
}
int main(){
    int v_n = 0;
    cin >> v_n;
    vector<int> v;
    while(v_n--){
        int a = 0;
        cin >> a;
        v.push_back(a);
    }
    vector<int> res = k_min(v);
    for(auto n:res){
        cout << n << " ";
    }
    return 0;
}