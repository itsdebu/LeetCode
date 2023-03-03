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
    void helper(TreeNode* root,vector<int>&v,int i)
    {
        if(!root)return;
        if(i==v.size())v.push_back(root->val);
        helper(root->right,v,i+1);
        helper(root->left,v,i+1);
    }
    vector<int> rightSideView(TreeNode* root) {
       vector<int>v;
        helper(root,v,0);
        return v;
    }
};