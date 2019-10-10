//将每个单词排序，相同的存到res中
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto ite = mp.begin(); ite != mp.end(); ite++) 
            res.push_back(ite->second);
        return res;
    }
};
