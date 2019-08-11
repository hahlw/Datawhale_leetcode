//【方法一】STL库
//看不太懂
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        auto resultPair = equal_range(data.begin(), data.end(),k);
        return resultPair.second - resultPair.first;
    }
};

//【方法二】常规二分,比较简单
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int number = 0;
        int first = getFirstIndex(data, k, 0, data.size()-1);
        int last = getLastIndex(data, k, 0, data.size()-1);
        if(first> -1 && last> -1)
            number = last - first + 1;
        return number;
    }
    int getFirstIndex(vector<int> &data, int k, int start, int end){
        if(start>end) return -1;
        int mid = start+(end-start)/2;
        if(data[mid] == k){
            if((mid == start)||(data[mid-1]!=k))//如果中间点的前一个元素不等于k，或者中点就是起点！那就找到了！
                return mid;
            else//否则再数组的前半段继续查找；
                end = mid - 1;
        }else{
            if(data[mid]>k)
                end = mid -1;
            else
                start = mid + 1;
        }
        return getFirstIndex(data, k, start, end);
    }
    
    int getLastIndex(vector<int> &data, int k, int start, int end){
        if(start>end) return -1;
        int mid = start + (end-start)/2;
        if(data[mid] == k){
            if(mid == end || data[mid+1] != k)
                return mid;
            else
                start = mid + 1;
        }else{
            if(data[mid]>k)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return getLastIndex(data, k, start, end);
    }
};
//【方法三】：巧妙插值方法，好俊俏的功夫！
////因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
//这两个数应该插入的位置，然后相减即可。
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return biSearch(data, k+0.5) - biSearch(data, k-0.5) ;
    }
private:
    int biSearch(const vector<int> & data, double num){
        int s = 0, e = data.size()-1;     
        while(s <= e){
            int mid = (e - s)/2 + s;
            if(data[mid] < num)
                s = mid + 1;
            else if(data[mid] > num)
                e = mid - 1;
        }
        return s;
    }
};
