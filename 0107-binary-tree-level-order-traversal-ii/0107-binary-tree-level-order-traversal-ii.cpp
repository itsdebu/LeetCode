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
    int height(TreeNode* root)
    {
        if(!root)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void helper(TreeNode* root,vector<vector<int>>&ans,int index)
    {
        if(!root)return;
        if(index==ans.size())ans.push_back({});
        ans[index].push_back(root->val);
        helper(root->left,ans,index-1);
        helper(root->right,ans,index-1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int index=height(root);
        vector<vector<int>>ans(index);
        index--;
        helper(root,ans,index);
        return ans;
    }
};