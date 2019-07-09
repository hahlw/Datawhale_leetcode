/*
编辑距离：
假设dp[i−1][j−1]表示一个长为i−1的字符串str1变为长为j−1的字符串str2的最短距离，如果我们此时想要把str1a这个字符串变成str2b这个字符串，我们有如下几种选择：
替换： 在str1变成str2的步骤后，我们将str1a中的a替换为b，就得到str2b (如果a和b相等，就不用操作)
增加： 在str1a变成str2的步骤后，我们再在末尾添加一个b，就得到str2b (str1a先根据已知距离变成str2，再加个b)
删除： 在str1变成str2b的步骤后，对于str1a，我们将末尾的a删去，就得到str2b (str1a将a删去得到str1，而str1到str2b的编辑距离已知)

若a和b相等：dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1])
若a和b不相等：dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1)
因为将一个非空字符串变成空字符串的最小操作数是字母个数（全删），反之亦然，所以：dp[0][j]=j, dp[i][0]=i

返回dp[m][n]即可，其中m是word1的长度，n是word2的长度

**
 * 递归算法
 * @param {string} a
 * @param {string} b
 * @param {number} i 字符串 a 的长度
 * @param {number} j 字符串 b 的长度
 * @returns {number} 从 a → b 的最小编辑距离
 *
function recursion(a, b, i, j) {
    if (j === 0) {
        return i;
    } else if (i === 0) {
        return j;
    } else if (a[i - 1] === b [j - 1]) {
        return recursion(a, b, i - 1, j - 1);
    } else {
        let m1 = recursion(a, b, i - 1, j) + 1;
        let m2 = recursion(a, b, i, j - 1) + 1;
        let m3 = recursion(a, b, i - 1, j - 1) + 1;
        return Math.min(m1, m2, m3);
    }
}
*/
public class Solution {
    public static int minEditDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        // 初始化空字符串的情况
        for(int i = 1; i <= m; i++){
            dp[i][0] = i;
        }
        for(int i = 1; i <= n; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                // 增加操作：str1a变成str2后再加上b，得到str2b
                int insertion = dp[i][j-1] + 1;
                // 删除操作：str1a删除a后，再由str1变为str2b
                int deletion = dp[i-1][j] + 1;
                // 替换操作：先由str1变为str2，然后str1a的a替换为b，得到str2b
                int replace = dp[i-1][j-1] + (word1.charAt(i - 1) == word2.charAt(j - 1) ? 0 : 1);
                // 三者取最小
                dp[i][j] = Math.min(replace, Math.min(insertion, deletion));
            }
        }
        return dp[m][n];
    }
    public static void main(String[] args) {  
        String source = "zhanghua";  
        String target = "zhanghau";  
        System.out.println("minDistance=" + minEditDistance(source, target));  
    }
}
