class Solution {
public:
    //下一个丑数必定有数组中的某一个丑数A * 2， B * 3， C * 5 的中的最小值得来。
    //这样就避免了计算所有的非丑数，降低了时间复杂度！
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
        if(index == 1) return 1;
        //或者
        //if(index < 7) return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for(int i=1; i<index; i++){
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if(res[i] == res[t2] * 2) t2++;
            if(res[i] == res[t3] * 3) t3++;
            if(res[i] == res[t5] * 5) t5++;
        }
        return res[index-1];
    
    }
};
