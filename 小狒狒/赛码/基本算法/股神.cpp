#include<iostream>
using namespace std;

int Solution( int n)
{
		int i= 0;//记录下跌的次数；
        int j = 2; // 记录每段的天数
        int k = n; //用来控制循环结束
        while( k > j){  //入股最后剩下的一段不足以撑到真实的每段，就结束！
        		i++;
                k -= j;
                j++;
        }
        return n - 2 * i;
}

int main()
{
		int n;
		while(cin >> n){
        	cout<<Solution(n)<<endl;
        }
        return 0;
}


//终于基本上学会了输入输入啊！不容易不容易！
