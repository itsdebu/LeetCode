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
    void get_all_path(TreeNode* root,int target,vector<int>path,vector<vector<int>>&All_path)
    {
        if(!root)return;
        path.push_back(root->val);
        if(target==root->val and !root->left and !root->right)
        {
            // path.push_back(root->val);
            All_path.push_back(path);
            return;
        }

        get_all_path(root->left,target-(root->val),path,All_path);
        get_all_path(root->right,target-(root->val),path,All_path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>All_path;
        vector<int>path;
        get_all_path(root,targetSum,path,All_path);
        return All_path;
    }
};