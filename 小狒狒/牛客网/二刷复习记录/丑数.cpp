//常规方法，就是超时了，过不了的算法！
//很暴力，一个一个算，一直算到找到那几个位置！
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
        int number = 0;
        int uglyFound = 0;
        while(uglyFound < index){
            ++number;
            if(isUgly(number)){
                ++uglyFound;
            }
        }
        return uglyFound;
    }
    bool isUgly(int num){
        while( num % 2 == 0)
            num /= 2;
        while( num % 3 == 0)
            num /= 3;
        while( num % 5 == 0)
            num /= 5;
        
        return num == 1 ? true : false;
    }
};

//第二种方法，大佬的方法，我还不是很明白！真俊俏的功夫啊！
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
        if(index == 1) return 1;
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
