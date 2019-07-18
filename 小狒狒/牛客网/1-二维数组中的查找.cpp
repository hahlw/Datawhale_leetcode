//在一个二维数组中（每个一维数组的长度相同），
//每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//一定要理解，脑子里要把整个过程顺下来，我真的还是太菜了!
//然后还要多读《剑指Offer》,以及不停的夯实自己C++的基础
//加油加油！

/*
*1. 二维数组的特点，递增！
*2. 直接挨个找就显得很蠢
*3. 那就从边边角角来找，这里是从右上角来找的！挨个比，一直到比到一样大！
class Solution{
public:
    bool Find(int target, vector<vector<int>> arary){
    int rows = array.size();
    int cols = array[0].size();
    
    if( !array.empty() && rows > 0 && cols > 0;){
        int row = 0;
        int col = cols.size() - 1;
        while( row < rows && col >=0){
            if(array[row][col] == target)
                return true;
            else if(array[row][col] < target)
                row++;
            else
                col--;
        }
    }
    return false;
    }
}
