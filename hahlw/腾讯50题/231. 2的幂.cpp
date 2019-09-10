#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while( n ){
            if(n&1==1){
                n=n>>1;
                if(n==0)return true;
                else return false;
            }
            n>>=1;
        }
        return false;
    }
};