class Solution {
    /*
    输入: 4, 14, 2
    输出: 6

    解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
    所以答案为：
    HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
    */
    public int totalHammingDistance(int[] nums) {
        int res = 0;
        int len = nums.length;
        for(int i = 0; i < 32; i++){
            int oneCount = 0;
            int temp = 0;
            for(int j = 0; j < len; j++){
                oneCount += nums[j] & 1;
                nums[j] >>= 1;
                temp += nums[j] == 0 ? 1 : 0;
            }
            res += oneCount * (len - oneCount);
            if(temp == len)break;
        }
        return res;
    }
