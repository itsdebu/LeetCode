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
    void sumOfLeft(TreeNode* root,int &sum,int index)
    {
        if(!root)return;
        if(index==0 and !root->left and !root->right)
        {
            sum+=root->val;
        }
        sumOfLeft(root->left,sum,0);
        sumOfLeft(root->right,sum,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(!root)return sum;
        sumOfLeft(root,sum,-1);

        return sum;

    }
};