// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
//其实就是二分查找！！！
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid = n;
        while(low<high){
            mid = low + (high-low) / 2; //这种形式的二分就是为了防止溢出！
            if(isBadVersion(mid))//有问题
                high = mid;
            else //没问题
                low = mid+1;
        }
        return high;//因为有问题的时候high = mid，所以最终返回的是high!
    }
};
