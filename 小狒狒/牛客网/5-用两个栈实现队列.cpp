class Solution
{
public:
    //目的：用两个先进后出实现先进先出！
    //入对（在队列的尾部插入元素）
    void push(int node) {
        stack1.push(node);
    
    }
    //出队（在队列的头部删掉元素）
    int pop() {
        //如果栈2是空的，那就填上，不空就直接弹出；
        if(stack2.empty())
        {
            //空的情况下且栈1不是空的，才能填上！
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int a = stack2.top;
        stack2.pop();
        return a;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
