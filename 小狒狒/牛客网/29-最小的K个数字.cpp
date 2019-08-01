【方法一】：nlogn
排序，输出

【方法二】：
不会！大致思路是清晰的，利用红黑树nlogk
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        if(len<=0||k>len) return vector<int>();
        //构建前K个数的容器，从大到小排列
        multiset<int, greater<int>> leastNums;
        vector<int>::iterator vec_it = input.begin();
        for(; vec_it != input.end(); vec_it++){
            //将前K个元素插入集合，如果还不够K个，那就一直用迭代器插满，
            if(leastNums.size()<k){
                leastNums.insert(*vec_it);
            }
            //如果已经插满K个了，那就要用后面的来和当前K个比较，如果比最大的小，就把这个替换掉！
            else{
                //第一个元素是最大值
                multiset<int, greater<int>>::iterator greatest_it = leastNums.begin();
                //如果后续元素小于第一个元素，删除第一个，加入当前元素
                if(*vec_it < *(leastNums.begin())){
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }
        //返回结果！只能背代码了吗难道？？？
        return vector<int>(leastNums.begin(), leastNums.end());
        
    }
};
