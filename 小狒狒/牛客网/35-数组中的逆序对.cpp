class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size()<=1) return 0;
        //初始化辅助数组，存放临时排序的结果，最后要将排序的结果复制到原数组中
        int* copy = new int[data.size()];
        for(unsigned int i=0; i< data.size(); i++)
            copy[i] = 0;//初始化为0
        int count = helperCore(data, copy, 0, data.size()-1);
        delete[] copy;//删除临时数组
        return count;
    }
    int helperCore(vector<int> &data, int* &copy, int start, int end){
        if(start == end){
            copy[start] = data[start];
                return 0;
        }
        //将数组拆分为前后两段，
        int length =(end-start)/2;
        //分别计算前后两部分的结果
        int left = helperCore(data, copy, start, start+length)%1000000007;
        int right = helperCore(data, copy, start+length+1, end)%1000000007;
        //进行逆序计算
        int i = start + length; //前一个数组的最后一个下标
        int j = end; //后一个数组的最后一个下标
        int index = end;//辅助数组下标，从最后一个开始；
        int count = 0;
        while(i>=start && j>=start+length+1){
            if(data[i] > data[j]){
                copy[index--] = data[i--];//把当前大的数存到辅助数组中去
                count += j-start - length;//小数组的长度就是需要加上的逆序对
                if(count>=1000000007)//数值过大就取余
                    count %= 1000000007;
            }else
                //如果第一个数组的数小于等于第二个数组中的数，第二段的数放入辅助数组并移动指针
                copy[index--] = data[j--];
        }
        for(; i>=start; --i){
            copy[index--] = data[i];
        }
        for(; j>=start+length+1; --j){
            copy[index--] = data[j];
        }
        //排序
        for(int i=start; i<=end; i++)
            data[i] = copy[i];
        return (count+left+right)%1000000007;
    }
};
