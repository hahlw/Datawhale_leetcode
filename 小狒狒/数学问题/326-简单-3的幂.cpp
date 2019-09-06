class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        long m = 1;
        while(m<n){
            m *= 3;
            if(m == n) return true;
        }
        return false;
    }
};
