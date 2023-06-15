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
    int maxLevelSum(TreeNode* root) {
        int level = 0,mx_sum_level=0;
        queue<TreeNode*>q;
        q.push(root);
        int mx=INT_MIN;
        while(!q.empty())
        {
            ++level;
            int sum=0;
            for(int i=q.size();i>0;i--)
            {
                TreeNode* temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(mx<sum)
            {
                mx=sum;
                mx_sum_level= level;
            }
        }
        return mx_sum_level;
    }
};