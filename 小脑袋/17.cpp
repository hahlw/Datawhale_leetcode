class Solution {
public:
    vector<string> res;
    vector<string> nums = {"abc" ,"def" ,"ghi" ,"jkl" ,"mno" ,"pqrs","tuv" ,"wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;
        helper("", digits, 0);
        return res;
    }
    void helper(string s, string d, int index) {
        if(index >= d.size()) {
            res.push_back(s);
            return ;
        }
        for(int i = 0; i < nums[d[index] - '2'].size(); i++) 
            helper(s + nums[d[index] - '2'][i], d, index);
    }
};

class Solution {
public:
    vector<string> res;
    vector<string> keys = {"abc" ,"def" ,"ghi" ,"jkl" ,"mno" ,"pqrs","tuv" ,"wxyz"};
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return res;
		helper("", digits, 0);
		return res;
	}
	void helper(string s, string d, int index) {
		if (index >= d.size()) {
			res.push_back(s);
			return;
		}
		for (int i = 0; i < keys[d[index]-'2'].size(); ++i)
			helper(s + keys[d[index]-'2'][i], d, index + 1);
	}
    
};
