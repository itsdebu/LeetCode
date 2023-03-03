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
    void helper(TreeNode* root,vector<vector<int>>&ans,int index)
    {
        if(root==NULL)return;
        if(index==ans.size())
        {
            ans.push_back({});
        }
        ans[index].push_back(root->val);
        helper(root->left,ans,index+1);
        helper(root->right,ans,index+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        helper(root,ans,0);
        return ans;
    }
};