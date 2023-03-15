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
    int total_Node(TreeNode* root)
    {
        if(root == NULL) return 0;

         int ans = 1 + total_Node(root->left) + total_Node(root->right);
        return ans;
    }

    bool isCBT(TreeNode* root, int index, int total_Nodes)
    {
        if(root == NULL)   return true;

        if(index >= total_Nodes)    return false;

        else
        {
            bool left = isCBT(root->left, 2*index+1, total_Nodes);
            bool right = isCBT(root->right, 2*index+2, total_Nodes);
            index++;
            return (left && right);
        }
    }
    bool isCompleteTree(TreeNode* root)
    {
        int index = 0;
        int count_Node = total_Node(root);
        return isCBT(root, index, count_Node);
    }
};