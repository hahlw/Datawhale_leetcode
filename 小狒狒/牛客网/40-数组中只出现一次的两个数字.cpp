class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        //Step1:所有数异或
        int num = 0;
        for(int i=0; i<data.size(); i++){
            num ^= data[i]  //  ^=  连续异或的意思！
        }
        //Step2：找到num中第一个出现1的位置，也就是两个树的
        //不一样的地方
        int count = 0;
        for(; count<data.size(); count++){
            //这里count就是标志位，
            if((num & (1<<count)) != 0)   //& 与的意思，<<左移count位数0，1，2，3，4，5，6！
                break;
        }
        //Step3:对单独的两个数组进行寻找
        for(int i=0; i<data.size(); i++){
            if((data[i] & (1<<count) == 0) //标志位为0的一组！
                num1[0] ^= data[i];
            else//志位为1的一组！
                num2[0] ^= data[i];
        }
    }
};
