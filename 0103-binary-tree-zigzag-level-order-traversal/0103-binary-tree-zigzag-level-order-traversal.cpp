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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        int count=0;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>v(size);
            count++;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                v[i]=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(count%2==0)reverse(v.begin(),v.end());
            ans.push_back(v);
        }return ans;
    }
};