#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    /*
    奇数时在小顶堆上取，偶数时在两个堆顶点去平均。
     */
    void Insert(int num)
    {
        if(cnt%2==0){//当前是偶数
            /*
            先插入小顶堆
             */
            if(num>=pmax.top()){
                pmin.push(num);
            }
            else{
                int tmp=pmax.top(); pmax.pop();
                pmax.push(num);
                pmin.push(tmp);
            }
        }
        else{//当前是奇数，插入大顶堆
            if(num<pmin.top()){
                pmax.push(num);
            }
            else{
                int tmp=pmin.top(); pmin.pop();
                pmin.push(num);
                pmax.push(tmp);
            }
        }
        cnt++;
    }

    double GetMedian()
    { 
        if(cnt%2 == 0){
            return (pmax.top() + pmin.top()) / 2.0;
        }
        else{
            return pmin.top();
        }
        
    }
private:
    priority_queue<int, vector<int>, greater<int>> pmin;
    priority_queue<int, vector<int>, less<int>> pmax;
    int cnt=0;

};