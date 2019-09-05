#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int one_cnt(int num){
    int cnt=0;
    while(num){
        cnt++;
        num &= (num - 1);
    }
    return cnt;
}

int c_num(vector<int>nums){
    unordered_map<int, int> mp;
    for(auto num :nums){
        int cnt = one_cnt(num);
        mp[cnt]++;
    }
    int cs = 0;
    for(auto m:mp){
        cs++;
    }
    return cs;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int num_size;
        cin >> num_size;
        vector<int> nums;
        while(num_size--){
            int a;
            cin >> a;
            nums.push_back(a);
        }
        int res = c_num(nums);
        cout << res << endl;
    }
    //system("pause");
    return 0;
}