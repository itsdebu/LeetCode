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
    void solve(TreeNode* root,int c,int &ans)
    {
        if(!root)return;
        c=c*10+root->val;
        if(!root->right and !root->left)ans+=c;
        solve(root->left,c,ans);
        solve(root->right,c,ans);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return NULL;
        int ans=0;
        solve(root,0,ans);
        return ans;
    }
};