#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int cnt(vector<int>&v,int b){
    int i = 0;
    for (; i < v.size();i++){
        if(b>=v[i])
            break;
    }
    int c = v.size()-i;
    if(i==v.size())
        return 0;
    
    while(i<v.size()){
        v[i]--;
        i++;
    }
    return c;
}
int main(){
    int v_n = 0, p_n = 0;
    cin >> v_n >> p_n;
    vector<int> v;
    while(v_n--){
        int a = 0;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    while(p_n--){
        int b=0;
        cin >> b;
        int c = cnt(v, b);
        cout << c << endl;
    }
    return 0;
}