class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;  //一共的位数，也是下标！
        int tag = 0;//记录当前位加一后的结果
        //开始遍历
        while(n>=0)  //判断是否遍历完成
        {
            tag = digits[n] + 1;
            digits[n--] = tag % 10; //下一位，高位取余数，如果小于10，商零余数是自己，如果是10，就余0！
            if( tag < 10) break; //用当前位加一后的结果是否超过10来控制循环，如果比10小，提前结束，直接break!,不然一直进位到最高位！
        }
        if( tag >= 10) digits.insert(digits.begin(), 1);
        return digits;
    }
};

//就是倒着遍历！
