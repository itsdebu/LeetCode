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
    int mx= INT_MIN;
    int max_sum(TreeNode* root)
    {
        if(!root)return 0;
        int l= max(0,max_sum(root->left));
        int r= max(0,max_sum(root->right));
        int new_sum= root->val +l+r;
        mx = max(mx,new_sum);
        return root->val +max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        max_sum(root);
        return mx;    
    }
    
    
};