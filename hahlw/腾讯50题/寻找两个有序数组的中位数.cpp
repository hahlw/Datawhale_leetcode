#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;
        if(total%2==1){
            return findK(nums1, 0, nums2, 0, total / 2 + 1);
        }
        else{
            return (findK(nums1, 0, nums2, 0, total / 2) + findK(nums1, 0, nums2, 0, total / 2 + 1))/2.0;
        }
    }
    int findK(vector<int>&nums1,int i,vector<int>&nums2,int j,int k){
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1-i>len2-j)
            return findK(nums2, j, nums1, i, k);
        if(len1-i==0)
            return nums2[j + k - 1];
        if(k==1)return min(nums1[i],nums2[j]);
        int left = min(len1 - i, k/2);
        int right = k-left;

        if(nums1[left+i-1]==nums2[right+j-1]){
            return nums1[left + i-1];
        }
        else if(nums1[left+i-1]>nums2[right+j-1]){
            return findK(nums1, i, nums2, j + right, k - right);
        }
        else
            return findK(nums1, i + left, nums2, j, k - left);
    }
};