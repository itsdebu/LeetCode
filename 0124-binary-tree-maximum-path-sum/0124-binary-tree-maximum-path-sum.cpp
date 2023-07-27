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
    
    int find_sum(TreeNode* root,int &mx)
    {
        if(!root)return 0;
        int lh = max(0,find_sum(root->left,mx));
        int rh = max(0,find_sum(root->right,mx));
        mx= max(mx,lh+rh+root->val);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int mx= INT_MIN;
        find_sum(root,mx);
        return mx;
    }
};