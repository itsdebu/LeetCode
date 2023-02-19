class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
        help(root,0,ans);
        return ans;
    }
    
    void help(TreeNode* root,int depth, vector<vector<int>>&ans){
        if(!root) return;
        if(depth==ans.size()){
          ans.push_back(vector<int>());
        }
        if(depth%2==0){
            ans[depth].push_back(root->val);
        }else{
              ans[depth].insert(ans[depth].begin(),root->val);
        }
        help(root->left,depth+1,ans);
        help(root->right,depth+1,ans);
    }
};