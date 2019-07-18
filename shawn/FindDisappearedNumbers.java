class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        if(nums.length <= 0) return res;
        
        for(int i=0; i<nums.length; i++){
            
            int now = Math.abs(nums[i]) -1;
            nums[now] = nums[now] > 0 ? -1*nums[now] : nums[now];
        }
        
        
        for(int i=0; i<nums.length; i++){
            if(nums[i] > 0){
                res.add(i+1);
            }
        }
        
        return res;
    }
}
