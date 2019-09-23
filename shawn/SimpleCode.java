class Solution {
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
    
    

}
