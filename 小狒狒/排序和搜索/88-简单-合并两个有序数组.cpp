class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[i+j+1] = nums1[i];
                i--;
            }else{
                nums1[i+j+1] = nums2[j];
                j--;
            }
        }
        //这是针对那种第一个数组一直比第二个数组大的情况，nums1都排完了，nums2还有，那就挨过走！
        //也可以说是特殊情况，nums1的有效数字就没几个！比如零个的情况！那好说，直接就把nums2给安排进去就好了！这个理解最好！
        if(i<0){
            while(j>=0){
                nums1[j] = nums2[j];
                j--;
            }
        }
    }
};
