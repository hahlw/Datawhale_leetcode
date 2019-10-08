class Solution {
public:
    int numSquares(int n) {
        /*
        数学方法：拉格朗日平方定理：任何一个整数都可以表示为不超过4个数的平方和
        推论：当且仅当n=4^a(8b+7)时，n恰好可以表示为4个数的平方和
        所以满足上式的结果为4
        */
        while(n % 4 == 0)
            n /= 4;
        if(n % 8 == 7)
            return 4;
        for(int i = 0 ; i * i < n; i++) {
            int j = pow(n - i * i, 0.5);//开平方根
            if(i * i + j * j == n)//若是可以开出整数，则证明两个平方根之和为n
                return !!i + !!j;
        }
        return 3;
    }
};

class Solution {
public:
    int numSquares(int n) {
        /*
        BFS：利用辅助队列，不断减去最大的值，剩余的存入队列
        */
        vector<int> Dob;
        //将小于等于n的完全平方数存入dou
        for(int i = 1; i * i <= n; i++) 
            Dob.push_back(i * i);
        int minLen = 0;
        queue<int> que;
        que.push(n);
        while(!que.empty()) {
            ++minLen;
            int wid = que.size();
            for(int i = 0; i < wid; i++){
                int temp = que.front();
                que.pop();
                for(int j = Dob.size() - 1; j >= 0; j--) { 
                    if(Dob[j] <= temp) {
                        if(Dob[j] == temp)
                            return minLen;
                        else
                            que.push(temp - Dob[j]);
                    }
                }
            }
        }
        return minLen;
    }
};
