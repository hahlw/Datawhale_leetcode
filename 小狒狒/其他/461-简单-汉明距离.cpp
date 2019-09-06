class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int count = 0;
        while(n){
            count++;
            n = n&(n-1);
        }
        return count;
    }
};
