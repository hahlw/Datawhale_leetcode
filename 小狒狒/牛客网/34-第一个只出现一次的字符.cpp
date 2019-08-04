//利用哈希表，两边遍历，第一遍存起来，第二次找！很简单！
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0) return -1;
        map<char, int> strMap;
        //第一次扫描，每扫到一个字符，就在哈希表的对应项中把次数+1
        for( int i=0; i<str.size(); i++){
            strMap[str[i]]++;//str[i]是第i个字符，对应的就是hash map中的char, 前面加上哈希表名就表示对应的次数
        }
        for( int i=0; i<str.size(); i++){
            if(strMap[str[i]] == 1)
                return i;//返回的是索引！
        }
        return -1;
    }
};
