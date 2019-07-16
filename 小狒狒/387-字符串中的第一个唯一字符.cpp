class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> strmap;   //建立一个char——int这样键值对的map,现在是空的， char是这个字符， int是出现的次数
        // 进行遍历的方法，
        for( auto i : s)
        {
            if(strmap.count(i)) strmap[i] += 1; // 遍历过程中如果找到了和当前的字符i一样的,那么就给当前字符对应的int类型加上1；
            else strmap[i] = 1;                 // 否则，没有找到的话，那么当前字符就是第一次出现，把它出现的次数记为1；
        }
        // 对建立好的hashmap进行遍历，从头开始，到尾巴结束, \0表示的就是字符串的结束
        for (int j=0; s[j] != '\0'; ++j)
        {
            if( strmap[s[j]] == 1)     // 如果第j个字符对应的出现的次数等于1，因为是遍历，所以只要是1，那就直接返回！
                return j;
        }
        return -1;
        
    }
};
