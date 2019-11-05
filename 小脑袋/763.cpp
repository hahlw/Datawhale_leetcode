class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        if(S.empty()) return res;
        int index = 0;
        vector<int> last(26,-1);
        for(int i = S.size()-1; i >= 0; --i){
            if(last[S[i]-'a'] == -1){
                last[S[i]-'a'] = i;
            }
        }
        
        while(index < S.size()){
            int end = last[S[index]-'a'];
            for(int i = 1; i <= end; ++i){
                end = max(end,last[S[i]-'a']);
            }
            res.push_back(end-index+1);
            index = end+1;
        }
        return res;
    }
};
