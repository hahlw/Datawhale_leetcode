//最长上升子序列
/*
时间复杂度：O(N^2)，因为有两个 for 循环，每个 for 循环的时间复杂度都是线性的。
空间复杂度：O(N)，要开和数组等长的状态数组，最后要拉通看一遍状态数组的最大值，因此空间复杂度是 O(N)
*/
import java.util.Arrays;

public class Solution {

    //【关键】将 dp 数组定义为：以 nums[i] 结尾的最长上升子序列的长度
    // 那么题目要求的，就是这个 dp 数组中的最大者
    // 以数组  [10, 9, 2, 5, 3, 7, 101, 18] 为例：
    // dp 的值： 1  1  1  2  2  3  4    4
    // 注意实现细节。
    public int lengthOfLIS(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        // 状态的定义是：以 i 结尾的最长上升子序列的长度
        // 状态转移方程：之前比最后那个数字小的最长上升子序列的长度 + 1
        int[] dp = new int[len];
        // 如果只有 1 个元素，那么这个元素自己就构成了最长上升子序列，所以设置为 1 是合理的
        Arrays.fill(dp, 1);
        // 从第 2 个元素开始，逐个写出 dp 数组的元素的值
        for (int i = 1; i < len; i++) {
            int curVal = nums[i];
            // 找出比当前元素小的哪些元素的最小值
            for (int j = 0; j < i; j++) {
                if (curVal > nums[j]) {
                    dp[i] = Integer.max(dp[j] + 1, dp[i]);
                }
            }
        }
        // 最后要全部走一遍，看最大值
        int res = dp[0];
        for (int i = 0; i < len; i++) {
            res = Integer.max(res, dp[i]);
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
        Solution solution = new Solution();
        int lengthOfLIS = solution.lengthOfLIS(nums);
        System.out.println(lengthOfLIS);
    }
}

