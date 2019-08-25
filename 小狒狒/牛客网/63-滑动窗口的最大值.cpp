class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;
        for(unsigned int i=0; i<num.size(); i++){
            //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            while(s.size() && num[s.back()] <= num[i]) s.pop_back();
            //当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
            while(s.size() && i-s.front()+1>size) s.pop_front();
            s.push_back(i); // 把每次滑动的num下标加入到队列
            //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
            if(size&&i+1>=size) res.push_back(num[s.front()]);
        }
        return res;
    }
};
