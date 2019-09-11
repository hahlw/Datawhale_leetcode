
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
  
  
    
}
