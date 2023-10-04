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
    bool pathSum(TreeNode* root,int target)
    {
        if(!root)return 0;
        if(root->val==target and !root->right and !root->left)return 1;

        int left = pathSum(root->left,target-(root->val));
        int right = pathSum(root->right,target-(root->val));
        return left | right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root,targetSum);
    }
};