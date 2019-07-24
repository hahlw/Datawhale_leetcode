class Solution {
public:
    double Power(double base, int exponent) {
        double res = 1.0;
        int m = abs(exponent);
        if(base == 0) cout<<"Wrong Base!!!"<<endl;
        if(exponent ==0 ) return 1;
        for(int i=1; i<=m; i++){
            res *= base;
        }
        if(exponent < 0){
            res = 1 / res;
        }
        return res;
    }
};
