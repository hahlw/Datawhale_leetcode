class Solution {
public:
    // 思想就是对两个字符串进行排序，然后对比，看每一位相等不，如果不相等，那就直接返回false！
    // 也不知道下面这个函数有什么用，基本上也是不影响的，如果用的话就是sort的最后面的参数
    // static bool cmp(const char&a, const char&b)
    //     {
    //         return a<b;
    //     }
    bool isAnagram(string s, string t) {
        if(s ==t) return true;
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for( int i=0; i< t.size(); i++)
        {
            if(s[i] != t[i])
                return false;
        }
        return true; 
    }
};
