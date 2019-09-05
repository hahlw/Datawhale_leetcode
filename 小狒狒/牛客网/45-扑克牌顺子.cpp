class Solution {
public:
    //前提：
    //（1）顺子必须是5张牌；
    //（2）顺子必须不能有对子；
    //（3）顺子最大值最小值只差绝对是4；
    //（4）题目中大小王最多只有4张；
    bool IsContinuous( vector<int> numbers ) {
        int len = numbers.size();
        //（1）不是五张牌肯定就不是顺子
        if(len != 5) return false;
        //给扑克点数排序
        sort(numbers.begin(), numbers.end());
        //统计大小王的数量
        int jokers = 0;
        for(int i=0; i<5&&numbers[i]==0; i++){
            jokers++;
        }
        if(jokers>4) return false;
        //对子的判断肯定在大小王之后，因为大小王是0，所以在它后面的那些数里进行判断！
        for(int i=jokers+1; i<5; i++){
            if(numbers[i] == numbers[i-1])
                return false;
        }
        //保证王的个数能够塞满空的位数！使其连续起来！
        int dis = numbers[4] - numbers[jokers];
        if(dis <= 4) return true;
        return false;
    }
};
