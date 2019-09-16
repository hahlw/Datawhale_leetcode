
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();// 最后输出的结果
        int n = nums.length;
        if (n == 0)
            return ret;
        ret.add(new ArrayList<Integer>());// 初始化
        for (int i : nums) {
            List<Integer> tmp;//放第二层的list
            List<List<Integer>> ttmp = new ArrayList<>();//，第一层list，放之前的list加上新的之后的list
            for (List<Integer> j : ret) {
                tmp = new ArrayList<>(j);
                tmp.add(i);
                ttmp.add(tmp);
            }
            ret.addAll(ttmp);
        }
        return ret;

    }
  
    //递归方式
    public List<List<Integer>> subsets2(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(0, nums, res, new ArrayList<Integer>());
        return res;

    }

    private void backtrack(int i, int[] nums, List<List<Integer>> res, ArrayList<Integer> tmp) {
        res.add(new ArrayList<>(tmp));
        for (int j = i; j < nums.length; j++) {
            tmp.add(nums[j]);
            backtrack(j + 1, nums, res, tmp);
            tmp.remove(tmp.size() - 1);
        }
    }
}
