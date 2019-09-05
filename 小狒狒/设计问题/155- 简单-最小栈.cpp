//投机取巧的，用两个栈来实现最小栈！
//对于push，首先压入data,如果这个时候压入元素比ministack栈顶元素小，那也压入ministack，不然不压；
//对于pop(),如果data的栈顶和ministack的栈顶相等的时候两个栈一起弹出，否则只弹出data的
//对于top，这个就直接是data的top
//对于返回最小值，那就是返回最下栈的top就好了！

class MinStack {
public:
    stack<int> data;
    stack<int> ministack;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if(ministack.empty() || x<=ministack.top()){
            ministack.push(x);
        }
        
    }
    
    void pop() {
        if(data.top() == ministack.top()){
            ministack.pop();
        }
        data.pop();
        
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return ministack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
