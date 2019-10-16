class Solution {
    //从数组中移走指定数字
    public int removeElement(int[] nums, int val) {
        int j = 0;
        for ( int i = 0; i < nums.length; i++) {
            if(nums[i] != val) {
                nums[j++] = nums[i];
            }
                
        }
        return j;
    }
    
    public int removeElement2(int[] nums, int val) {
        int i = 0;
        int n = nums.length;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
    
    //一个字符串在另外一个字符串中出现的位置
    int search(String pat, String txt) {
        int M = pat.length;
        int N = txt.length;
        for (int i = 0; i < N - M; i++) {
            int j;
            for (j = 0; j < M; j++) {
                if (pat[j] != txt[i+j])
                    break;
            }
            // pat 全都匹配了
            if (j == M) return i;
        }
        // txt 中不存在 pat 子串
        return -1;
    }

    public int romanToInt(String s) {
        if(s == null || s.length() ==0) return 0;
        Map<String, Integer> map = new HashMap<>();
        map.put("I", 1);
        map.put("IV", 4);
        map.put("V", 5);
        map.put("IX", 9);
        map.put("X", 10);
        map.put("XL", 40);
        map.put("L", 50);
        map.put("XC", 90);
        map.put("C", 100);
        map.put("CD", 400);
        map.put("D", 500);
        map.put("CM", 900);
        map.put("M", 1000);
        
        int sum = 0;
        // char[] arr = s.toCharArray();
        for(int i = 0; i<s.length();){
            if(i + 1 < s.length() && map.containsKey(s.substring(i, i+2))) {
                sum += map.get(s.substring(i, i+2));
                i += 2;
            } else {
                sum += map.get(s.substring(i, i+1));
                i ++;
            }
        }
               
        return sum;
    }
    
    public String intToRoman(int num) {
        // 把阿拉伯数字与罗马数字可能出现的所有情况和对应关系，放在两个数组中
        // 并且按照阿拉伯数字的大小降序排列，这是贪心选择思想
        int[] nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder stringBuilder = new StringBuilder();
        int index = 0;
        while (index < 13) {
            // 特别注意：这里是等号
            while (num >= nums[index]) {
                // 注意：这里是等于号，表示尽量使用大的"面值"
                stringBuilder.append(romans[index] );
                num -= nums[index];
            }
            index++;
        }
        return stringBuilder.toString();
    }

    //搜索插入位置
    public int searchInsert(int[] nums, int target) {
        
        if(nums.length == 0) return 0;
        
        int len = nums.length;
        int start = 0;
        int end = len - 1;
        while(start <= end){
            int mid = start + end >> 1 ;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid - 1;
            else start  = mid + 1;
        }
        
        return start;
    }

    //最大子序和
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        int sum = 0;
        for(int j = 1; j < nums.length; j++){
            
            if(sum < 0){
                sum = nums[j];
                if(sum > maxSum){
                    maxSum = sum;
                }
                continue;
            }
            sum += nums[j];
            if(sum > maxSum){
                maxSum = sum;
            }
        }
        
        return maxSum;
    }
    public int maxSubArray2(int[] nums) {
        int res = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (sum > 0)
                sum += num;
            else
                sum = num;
            res = Math.max(res, sum);
        }
        return res;
    }
    /*
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
         """
        for i in range(1, len(nums)):
            nums[i]= nums[i] + max(nums[i-1], 0)
        return max(nums)
    */
    
    //动态规划
    public int maxSubArray3(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int[] dp = new int[len];
        dp[0] = nums[0];

        for (int i = 1; i < len; i++) {
            if (dp[i - 1] >= 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
        }

        // 最后不要忘记全部看一遍求最大值
        int res = dp[0];
        for (int i = 1; i < len; i++) {
            res = Math.max(res, dp[i]);
        }
        return res;
    }

    //数组加1
    public int[] plusOne(int[] digits) {
        if(digits == null && digits.length == 0) return null;
        
        int toSum = 0;
        int len = digits.length;
        int one = 1;
        for(int i=digits.length-1; i>=0; i--){
            int s = digits[i]  + toSum + one;
            one = 0;
            if(s>=10){
                digits[i] = s % 10;
                toSum = 1;
            }else{
                digits[i] = s;
                toSum = 0;
                break;
            }
            
        }
        if(toSum > 0){
            int[] dig = new int[len+1];
            dig[0] = 1;
            for(int i =1 ;i<len+1; i++){
                dig[i] = digits[i-1];
            }
            return dig;
        }
        
        return digits;
    }

    
    
}
