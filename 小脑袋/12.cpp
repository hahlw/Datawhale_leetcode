class Solution {
public:
    string intToRoman(int num) {
        int values[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string change[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string res;
        for(int i = 0; i < 13; i++) {
            while(num >= values[i]) {
                num -= values[i];
                res += change[i];
            }
        }
        return res;
    }
};


class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mapRom = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},                                              {400,"CD"},{500,"D"},{900,"CM"}, {1000,"M"} };
        map<int, string>::reverse_iterator  r_iter;
        string ret;
        r_iter = mapRom.rbegin();
        while(r_iter != mapRom.rend())
        {
            if(num >= r_iter->first)
            {
                ret += r_iter->second;
                num-= r_iter->first;
            }
            else
                r_iter++;
        }
        return ret;
    }
};
