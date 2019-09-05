//448
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) -1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        for(int i = 0; i <nums.size(); i++)
            if(nums[i] > 0)
                res.push_back(i + 1);
        return res;
    }
};

//437
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        return pathSum(root->right, sum) + pathSum(root->left, sum) + dfs(root, sum);
    }
    int dfs(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        int cnt = 0;
        if(root->val ==  sum)
            cnt = 1;
        return cnt + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
    }
};
