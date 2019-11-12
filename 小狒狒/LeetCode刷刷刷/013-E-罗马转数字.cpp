class Solution {
public:
    int romanToInt(string s) {
        int res(0);
        map<char, int> luomab;
        luomab.insert(map<char, int>::value_type('I', 1));
        luomab.insert(map<char, int>::value_type('V', 5));
        luomab.insert(map<char, int>::value_type('X', 10));
        luomab.insert(map<char, int>::value_type('L', 50));
        luomab.insert(map<char, int>::value_type('C', 100));
        luomab.insert(map<char, int>::value_type('D', 500));
        luomab.insert(map<char, int>::value_type('M', 1000));

        for(int i=0; i<s.size(); i++){
            if(luomab[s[i]] >= luomab[s[i+1]]){
                res += luomab[s[i]];
            }else{
                res += (luomab[s[i+1]] - luomab[s[i]]);
                i++;
            }
        }
        return res;
    }
};
//这个题想说的其实主要就是map的应用，这里map的插入Insert的操作需要注意，luomab.insert(),直接在里面写是不行的，里面的格格式，value_type是不能少的！
//然后就是这个的循环，如果前一个比后一个大，那没啥问题直接加！
//!!!如果前一个比后一个小，那其实就是用后一个大的减去小的了，这里不能等着for循环自动去更新i的变化，应为两个字符构成了一个Int,所以应该手动继续++i操作！
//主要就是map！今天详细看一下啊！
