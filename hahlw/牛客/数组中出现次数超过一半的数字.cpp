#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        int cnt = 1;
        int num = numbers[0];
        for (int i = 1; i < n;i++){
            if(num==numbers[i]){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    num = numbers[i];
                    cnt = 1;
                }
            }
        }
        if(cnt<1){
            return 0;
        }
        cnt = 0;
        for(auto nu:numbers){
            if(nu==num)
                cnt++;
        }
        return cnt > n / 2 ? num : 0;
    }
};