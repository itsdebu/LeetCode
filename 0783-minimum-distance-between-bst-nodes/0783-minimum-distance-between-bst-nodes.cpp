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
    // Inorder Traversal of Binary search tree give sorted values
    void bst(TreeNode* root,vector<int>&v){ //Inorder Traversal
        if(root==NULL )    return;
        bst(root->left,v);
        v.push_back(root->val);
        bst(root->right,v);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        bst(root,v);
        int m=INT_MAX;
        for(int i=1;i<v.size();i++)    m=min(m,v[i]-v[i-1]);
        
        return m;
    }
};