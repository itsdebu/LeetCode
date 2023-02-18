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
    unordered_map<int,int>mp;
    TreeNode* solve(TreeNode* root)
    {
        if(root==NULL)return NULL;
        mp[root->val]++;
        solve(root->left);
        solve(root->right);
        return NULL;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        solve(root);
        int mx=INT_MIN;
        for (auto i : mp) {
            mx=max(mx,i.second);
        }
        for(auto i:mp)
        {
            if(mx==i.second)v.push_back(i.first);
        }return v;
    }
};