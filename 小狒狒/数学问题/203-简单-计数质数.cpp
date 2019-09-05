//【暴力】
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i=2; i<n; i++){
            bool sign = true;
            for(int j=2; j<i; j++){
                if(i % j == 0){
                    sign = false;
                    break;
                }  
            }
            if(sign) count++;
        }
        return count;
    }
};

//这个题真的是烦死我了！
