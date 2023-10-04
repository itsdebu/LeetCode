/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool pathSum(TreeNode* root,int target,int curr_sum)
    {
        if(!root)return 0;
        if(root->val+curr_sum == target and !root->left and !root->right)return 1;

        int left = pathSum(root->left,target,curr_sum+(root->val));
        int right = pathSum(root->right,target,curr_sum+(root->val));
        return left | right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root,targetSum,0);
    }
};