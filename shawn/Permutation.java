//全排列
class Permutation {
    //每一次的dfs都从头到尾去循环
    //使用一个数组来判断这个值是否为选过
    List<List<Integer>>list;
    int[]nums;
    public List<List<Integer>> permute(int[] nums) {
        this.nums=nums;
        boolean[]flag=new boolean[nums.length];
        list=new ArrayList<>();
        List<Integer>ll=new ArrayList<>();
        dfs(0,ll,flag);
        return list;
    }
    public void dfs(int length,List<Integer>ll,boolean[]flag)
    {
        if(length==nums.length)
        {
         list.add(new ArrayList<>(ll));
            return;
         }
        for(int i=0;i<nums.length;i++)
        {
            if(flag[i])
                continue;
            ll.add(nums[i]);
            flag[i]=true;
            dfs(length+1,ll,flag);
            flag[i]=false;
            ll.remove(ll.size()-1);
        }
    }
}
