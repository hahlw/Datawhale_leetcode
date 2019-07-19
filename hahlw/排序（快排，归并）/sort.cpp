#include <iostream>
#include<vector>
using namespace std;
/*

quicksort
*/

int part(vector<int>&src,int lo,int hi){
    int flag=src[lo];
    while(lo<hi){
        while(flag<=src[hi]&&lo<hi)
            hi--;
        src[lo]=src[hi];
        while(flag>=src[lo]&&lo<hi)
            lo++;
        src[hi]=src[lo];
    }
    src[hi]=flag;
    return hi;
}
void quick_sort(vector<int>&src,int lo,int hi){
    if(lo>=hi)return ;
    int part_p=part(src,lo,hi);
    quick_sort(src,lo,part_p-1);
    quick_sort(src,part_p+1,hi);
}
/*
merge sort
 */
void merge(vector<int>&res,int left,int mid,int right,vector<int>&tmp){
    int i=left;
    int j=mid+1;
    int t=0;
    while(i<=mid&&j<=right){
        if(res[i]<=res[j]){
            tmp[t++]=res[i++];
        }
        else{
            tmp[t++]=res[j++];
        }
    }
    while(i<=mid){
        tmp[t++]=res[i++];
    }
    while(j<=right){
        tmp[t++]=res[j++];
    }
    t=0;
    while(left<=right){
        res[left++]=tmp[t++];
    }
}

void merge_sort(vector<int>&res,vector<int>&tmp,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(res,tmp,left,mid);
        merge_sort(res,tmp,mid+1,right);
        merge(res,left,mid,right,tmp);
    }
}

void sort(vector<int>&res){
    int len=res.size();
    vector<int>tmp(len,0);
    merge_sort(res,tmp,0,len-1);
}


int main(){
    vector<int>un_sort={5,7,0,9,3,4};
    //quick_sort(un_sort,0,un_sort.size()-1);
    sort(un_sort);
    for(auto i :un_sort){
        cout<<i<<endl;
    }
    //system("pause");
    return 0; 
}