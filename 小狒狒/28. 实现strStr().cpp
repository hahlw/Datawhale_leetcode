class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(needle.empty()) return 0;
        // int pos = haystack.find(needle);
        // return pos;
       if(needle.size == 0) return 0;
       for(int i=0; i<haystack.size(); i++)
       {
           //排除needle比剩下的还要长的情况
           if(i+needle.size() -1 >= haystack.size())
               return -1;
           int flag = 1
           for(int j=0; j< needle.size(); j++)
           {
               // 从i起寻找相同吗，相同的话就直到照完，不同的话就直接把flag变为0，然后继续遍历！
               if(haystack(i+j) == needle(j))
                   continue;
               flag = 0;
           }
       }
       if(flag == 1)
           return i;
        
    }
    return -1;
};
