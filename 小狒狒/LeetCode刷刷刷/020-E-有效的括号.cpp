class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;
        if(s.size() % 2 != 0) return false;
        stack<char> helper;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                helper.push(s[i]);
            }else{
                if(helper.size() == 0) 
                    return false;
                char match;
                if(s[i] == ')'){
                    match = '(';
                }else if(s[i] == ']'){
                    match = '[';
                }else if(s[i] == '}'){
                    match = '{';
                }
                char c = helper.top();
                helper.pop();
                if(match != c){
                    return false;
                }
                
            }
        }
        if(helper.size() != 0)
            return false;
        return true;
    }
};
//这个现在开来确实是很简单的，首先就是要对一些常识性的东西进行区别，比如最直接的是不是偶数这样的情况
//如果是空的情况等等
//接下来其实是算法方面的东西，这个就很常规的，这里我借用栈的方法，遇到左括号就压栈，遇到右括号就和栈顶元素对比！
//如果匹配的话，那就是一对！直接pop这个栈顶元素继续对比
//否则的话就直接返回false!
