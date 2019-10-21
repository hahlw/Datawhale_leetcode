class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0; i<length; i++){
            if(numbers[i] < 0 || numbers[i] > length -1 )
                return false;
        }
        
        map<int, int> m;
        for(int i=0; i<length; i++){
            m[numbers[i]]++;//挨个的给添加到map中去！
            if(m[numbers[i]] > 1){
                *duplication = numbers[i];//这里要注意把那个重复的给拿出来！
                return true;
            }
        }
        return false;
    }
};
