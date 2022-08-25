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
    bool help(TreeNode* a,TreeNode* b)
    {
        if(a==NULL or b==NULL)return (a==b);
        return (a->val==b->val) and help(a->left,b->right) and help(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return help(root->left,root->right);
    }
};