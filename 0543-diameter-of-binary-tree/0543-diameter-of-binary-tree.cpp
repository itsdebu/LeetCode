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
    int fh(TreeNode * root,int &mx)
    {
        if(root==NULL)return 0;
        int lh = fh(root->left,mx);
        int rh = fh(root->right,mx);
        mx = max(mx ,lh+rh);
        return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
//         int lh = fh(root->left);
//         int rh = fh(root->right);
        
//         mx = max(mx,lh+rh);
        
//         diameterOfBinaryTree(root->left);
//         diameterOfBinaryTree(root->right);
        int mx=0;
        fh(root,mx);
        return mx;
    }
};