class Solution {
public:
    int StrToInt(string str) {
        //如果是空的，那就直接返回0
        if(str.empty()) return 0;
        int res = 0;
        //i是用来遍历的
        int i = 0;
        //考虑包含正负号的情况，i就直接从1开始！
        if(str[0] == '+' || str[0] == '-')
            i = 1;
        //一个一个转换！
        for(i; i<str.size(); i++){
            //如果合法，那就转换！
            if(str[i]>='0'&&str[i]<='9')
                res = res*10+(str[i]-'0');
            //若是非法，直接返回零
            else
                return 0;
        }
        //最后如果是有负号并且合法的话，返回负int值！
        if(str[0] == '-')
            return -res;
        else
            return res;
    }
};
