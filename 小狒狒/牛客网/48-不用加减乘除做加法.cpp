class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2 != 0){//直到不产生进位来控制循环，否则一直执行前两部
            int sum = num1 ^ num2;//Step1:；两个数异或，相当于每一位相加不进位
            num2 = (num1 & num2) << 1;//Step2:两个数相与，并且左移一位，相当于求得进位
            //Step3：前面两个步骤的结果相加
            num1 = sum;
            //num2 = carry;
        }
        return num1;
    }
};
