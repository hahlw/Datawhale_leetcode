class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;
        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] % 2 == 1)
                res.push_back(array[i]);
        }
        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] % 2 == 0)
                res.push_back(array[i]);
        }
        //array.swap(res);
        array = res;
        
    }
};
//还有一种方法是类似于插入排序的，比较好~前偶后奇就换swap!
