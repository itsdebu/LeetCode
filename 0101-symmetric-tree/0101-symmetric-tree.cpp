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
    bool check(TreeNode* a,TreeNode* b)
    {
        if(!a or !b)return (a==b);
        return (a->val==b->val and check(a->left,b->right) and check(a->right,b->left));
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};