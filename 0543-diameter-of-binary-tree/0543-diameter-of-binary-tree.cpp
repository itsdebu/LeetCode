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
    int mx=-1;
    int fh(TreeNode * root)
    {
        if(root==NULL)return 0;
        return 1+max(fh(root->left),fh(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int lh = fh(root->left);
        int rh = fh(root->right);
        
        mx = max(mx,lh+rh);
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return mx;
    }
};