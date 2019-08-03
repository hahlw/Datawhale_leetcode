class Solution {
public:
    //设计相应的比较规则，大数问题，一般转换成字符串来进行！防止溢出！
    static bool cmp( int a, int b){
        string A="";
        string B="";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);
        return A<B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i=0; i<numbers.size(); i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
};
