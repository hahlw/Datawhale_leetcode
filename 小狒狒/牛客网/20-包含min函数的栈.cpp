class Solution {
public:

    stack<int> stack1, stack2;
    void push(int value) {
        stack1.push(value);
        if(stacl2.empty()) stack2.push(value);
        else if(value<=stack2.top()){
            stack2.push(value);
        }
    }
    
    void pop() {
        if(stack1.top() == stack2.top()){
            stack2.pop(top);
        }
        stack1.pop()
       
    }
    int top() {
        return stack1.top()
    }
    int min() {
        return stack2.top()
    }
};
