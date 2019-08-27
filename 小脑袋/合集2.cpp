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
    int num = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root != NULL)
        {
            convertBST(root->right);
            root->val += num;
            num = root->val;
            convertBST(root->left);
            return root;
        }       
        return NULL;
    }
};

//283
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        for(int i = j; i < nums.size(); i++)
            nums[i] = 0;
    }
};
