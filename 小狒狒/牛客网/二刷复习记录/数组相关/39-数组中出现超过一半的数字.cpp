//先找到是哪个数，然后统计次数是否满足提议！
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if( numbers.size() == 0) return 0;
        //Step1
        int num = numbers[0], count = 1;
        for(int i=1; i<numbers.size(); i++){
            if(numbers[i] == num)
                count++;
            else 
                count--;
            if(count==0){
                num = numbers[i];
                count=1;
            }
        }
        //Step2:
        int counts = 0;
        for(int i=0; i<numbers.size(); i++){
            if(numbers[i] == num){
                counts++;
            }
        }
        return counts>numbers.size()/2 ? num : 0;
    }
};
