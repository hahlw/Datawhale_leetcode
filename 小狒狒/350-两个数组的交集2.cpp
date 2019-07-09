class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int>::iterator it;//用了迭代器，不是太懂太明白！
        for(int i=0; i<nums1.size(); i++)
        {
            it = find(nums2.begin(), nums2.end(), nums1[i]);
            if(it != nums2.end()){ //如果找到了
                res.push_back(*it);
                nums2.erase(it);   //删除找到的这个元素
            }
        }
        return res;
    }
};
