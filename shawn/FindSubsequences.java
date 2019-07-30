class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> res = new HashSet<>();
        helper(nums, 0, new ArrayList<>(), res);
        return new ArrayList<>(res);
    }

    // 确定一个在[cur,nums.length-1]范围内的数字, 如果找到这个数字, 那么就要递归的向下搜索
    private void helper(int[] nums, int cur, List<Integer> list, Set<List<Integer>> res) {
        if(list.size() >= 2) {
            List<Integer> newList = new ArrayList<>(list); // 由于list是由引用传递的，所以我们需要深拷贝一个新的List
            res.add(newList);
        }
        if(cur == nums.length)
            return;
        for(int i = cur; i < nums.length; i++) {
            if(list.size() == 0 || nums[i] >= list.get(list.size()-1)) {
                list.add(nums[i]);
                helper(nums, i+1, list, res);
                list.remove(list.size()-1);    //注意要回到初始的情况，保持递归的语义
            }
        }
    }
}
