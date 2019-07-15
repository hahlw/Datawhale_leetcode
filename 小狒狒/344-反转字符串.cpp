class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0; 
        int j = s.size() - 1;
        while(i < j)
        {
            swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
};

//双指针正方向同时进行，交换！while控制
