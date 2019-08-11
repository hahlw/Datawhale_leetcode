#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long cnt;
    void merge(vector<int>& data, vector<int>& tmp, int lo, int mid, int hi){
        int right = hi, left = mid;
        while(left>=lo&&hi>mid){
            if(data[left]>data[hi]){
                cnt += hi - mid;
                tmp[right--] = data[left];
                left--;
            }
            else{
                tmp[right--] = data[hi];
                hi--;
            }
        }
        while(left>=lo){
            tmp[right--] = data[left--];
        }
        while(hi>mid){
            tmp[right--] = data[hi--];
        }
    }
    void mergeSort(vector<int>&data,vector<int>&tmp,int lo,int hi){
        if(lo<hi){
            int mid = lo + (hi - lo) / 2;
            mergeSort(data, tmp, lo, mid);
            mergeSort(data, tmp, mid + 1, hi);
            merge(data, tmp, lo, mid, hi);
            for (int i = lo; i <= hi;i++){
                data[i] = tmp[i];
            }
        }
    }
    int InversePairs(vector<int> data) {
        int n = data.size();
		if (n == 0 || n == 1)return 0;
        vector<int> tmp(n);
        mergeSort(data, tmp, 0, n-1);
        return cnt%1000000007;
    }
};