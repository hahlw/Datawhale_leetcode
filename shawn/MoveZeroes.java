class MoveZeroes {
    public void moveZeroes(int[] nums) {
        int i = 0;
        for(; i < nums.length; i++){
            if(nums[i] == 0) break;
        }
        int j = i + 1;
        while(j < nums.length){
            if(nums[j] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
            j++;
        }
    }
}
