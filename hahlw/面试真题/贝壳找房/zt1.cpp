#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool is_ss(vector<int>v){
    bool is_up = true;
    for (int i = 0; i < v.size();i++){
        if(i>0&&v[i]<v[i-1])
        {
            is_up = false;
            break;
        }
    }
    if(is_up)
        return true;
    bool isdown = true;
    for (int i = 0; i < v.size();i++){
        if(i>0&&v[i]>v[i-1])
        {
            isdown = false;
            break;
        }
    }
    if(isdown)return true;
    return false;
}
bool is_g(vector<int>v){
    
}

int main(){
    unordered_map<int, int> mp;
    int num;
    cin >> num;
    while(num--){
        int n;
        cin >> n;
        vector<int> g;
        while(n--){
            int a;
            cin >> a;
            g.push_back(a);
        }
        bool res = is_ss(g);
        if(res)
            cout << "Yes" << endl;
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}