class Solution {
public:
    int Fibonacci(int n) {
        if( n == 0) return 0;
        if( n == 1) return 1;
        
        int FibMinusOne = 1;
        int FibMinusTwo = 0;
        int FibN = 0;
        for( int i = 2; i <= n; i++){
            FibN = FibMinusOne +　FibMinusTwo;
            FibMinusTwo = FibMinusOne;
            FibMinusOne = FibN;
        }
        return FibN;
    }
};
