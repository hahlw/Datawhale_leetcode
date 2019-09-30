//类似于括号匹配
class Solution {
public:
    string decodeString(string s) {
        int nums = 0;
        stack<int> numsst;
        stack<string> strst;
        string cur = "";
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9')
                nums = 10 * nums + s[i] - '0';
            else if(s[i] == '[') {
                numsst.push(nums);
                strst.push(cur);
                cur.clear();
            }
            else if(s[i] >= 'a' && s[i] <= 'z' || (s[i] >= 'A' && s[i] <= 'Z'))
                cur += s[i];
            else if(s[i] == ']') {
                int tp = numsst.top();
                numsst.pop();
                for(int j = 0; j < tp; j++)
                    strst.top() += cur;
                cur = strst.top();
                strst.pop();
            }
            res = res + cur;
            return res;
        }
    }
};
