#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>stk;
    stack<int>stk_min;
    MinStack() {}
    void push(int x) {
        stk.push(x);
        if(stk_min.empty()||x<=stk_min.top())
            stk_min.push(x);
    }
    
    void pop() {
        auto a=stk.top();
        if(a==stk_min.top())stk_min.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stk_min.top();
    }
};
