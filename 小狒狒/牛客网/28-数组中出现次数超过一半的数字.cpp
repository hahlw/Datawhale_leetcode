//【方法一】
//常规，先排序，然后遍历！时间复杂度高nlogn
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        //排序
        sort(numbers.begin(), numbers.end());
        //一个数组中如果存在这样的数，那么一定出现在这个数组的中间！
        int middle = numbers[numbers.size()/2];
        
        //验证一下这个数满足不
        int count = 0;
        for(int i=0; i<numbers.size(); i++){
            if(numbers[i] == middle){
                count++;
            }
        }
        return (count>numbers.size()/2)?middle:0;
    
    }
};

//【方法二：】
//根据数组的特点！时间复杂度O(n)
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) return 0;
        //从第一数开始，遇到想同的计数器+1，如果不相同计数器1；
        //当计数器变成零那就把当前的这个数开始统计，最后一次处罚重置计数器的那个数就肯定是中位数了
        //因为其他所有数的和加起来都没他多,完全 不够减的！
        int num = numbers[0], count = 1;
        for(int i=1; i<numbers.size(); i++){
            if(numbers[i] == num)
                count++;
            else 
                count--;
            if(count==0){
                num = numbers[i];
                count = 1;
            }
        }
        
        //验证
        int counts = 0;
        for(int i=0; i<numbers.size(); i++){
            if(numbers[i] == num) 
                counts++;
        }
        return (counts>numbers.size()/2) ? num : 0;
    }
};
