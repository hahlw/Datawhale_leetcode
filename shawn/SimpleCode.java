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

    

}
