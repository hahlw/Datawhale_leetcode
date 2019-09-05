#include<iostream>
#include<string>
#include<stack>
using namespace std;
string expendstr(string str){
    stack<string> stk;
    stack<int> nums;
    string tmp = "";
   
    int num = 0;
    for (int i = 0; i < str.size();i++){     
        //处理单字符接数字情况，先将数字读出来，然后评估数字前一个字符不是’）‘
        if(str[i]>='0'&&str[i]<='9'){
            int start=i;//数字的前一位是不是字母
            while(i<str.size()&&str[i]>='0'&&str[i]<='9'){
                num = num * 10 + (str[i] - '0');
                i++;
            }
            for(int k=0;k<num-1;k++){
                tmp += str[start - 1];
            }
            num = 0;
            i--;
        }
        else if(str[i]=='('){
            stk.push(tmp);
            tmp = "";
        }
        else if(str[i]==')'){
            int j = i + 1;
            while(j<str.size()&&str[j]>='0'&&str[j]<='9'){
                num = num * 10 + (str[j] - '0');
                j++;
            }
            for (int k = 0;k<num;k++){
                stk.top() += tmp;
            }
            num = 0;
            tmp=stk.top();
            stk.pop();
            i = j - 1;
        }
        else {
            tmp += str[i];
        }
    }
    return tmp;
}

int main(){
    int cnt = 0;
    cin >> cnt;
    while(cnt--){
        string s;
        cin >> s;
        string res = expendstr(s);
        cout << res << endl;
    }
    system("pause");
    return 0;
}