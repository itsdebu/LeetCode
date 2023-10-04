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
    bool issame(TreeNode* root,TreeNode* subroot)
    {
        if(!root and !subroot)return 1;
        if(!root or !subroot)return 0;

        if(root->val!=subroot->val)return 0;
        return issame(root->left,subroot->left) and issame(root->right,subroot->right);
    }
    bool tree(TreeNode* root,TreeNode* subroot)
    {
        if(!root)return 0;

        bool left_subtree = tree(root->left,subroot);
        bool right_subtree = tree(root->right,subroot);

       if(issame(root,subroot))return 1;
        
        return left_subtree | right_subtree;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        return tree(root,subroot);
    }
};