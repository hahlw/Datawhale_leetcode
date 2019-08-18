class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    //还是hash map的方法平易近人！我喜欢！
    bool duplicate(int numbers[], int length, int* duplication) {
        map<int, int> m;
        for(int i=0; i<length; i++){
            //挨个添加到hashmap中去！
            m[numbers[i]]++;
            if(m[numbers[i]] > 1){
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};
