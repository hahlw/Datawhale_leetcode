//【方法1】——37ms！
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        for(int i=0; i< rotateArray.size() - 1; i++)
        {
            if(rotateArray[i] > rotateArray[i+1])
                return rotateArray[i+1];
        }
        //如果整体旋转了一遍相当于没旋转；
        return rotateArray[0];

    }
};
//【方法2】二分法
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
            return 0;
        int left = 0, right = rotateArray.size() - 1;
        int mid = 0;
        while(rotateArray[left] >= rotateArray[right]){
            if( right - left == 1){
                mid = right;
                break;
            }
            mid = left + (right -left) / 2; // 35ms
            // mid = (left + right) / 2; // 25ms;
            if(rotateArray[left] == rotateArray[right] &&　rotateArray[left] == rotateArray[mid]){
                return special_case(rotateArray, left, right);
            }
            if(rotateArray[mid] >= rotateArray[left]){
                left = mid;
            }else {
                right = mid;
            }
        }
        return rotateArray[mid];
    }
private:
    int special_case(vector<int> &nums, int left, int right){
        int result = nums[left];
        for(int i=left + 1; i<right; i++){
            if(nums[i] < result){
                result = nums[i];
            }
        }
        return result;
    }
};
