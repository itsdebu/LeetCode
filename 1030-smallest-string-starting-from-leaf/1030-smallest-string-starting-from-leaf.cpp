class Solution {
public:
	void helper(TreeNode *root,string &s,string &ans){
		if(!root) return;
		s.push_back(root->val+'a');
		if(!root->left and !root->right){
			 string str=s;
			 reverse(str.begin(),str.end());
			 if(ans.empty() || str<ans)
				 ans=str;
		}
		helper(root->left,s,ans);
		helper(root->right,s,ans);
		s.pop_back();
	}
	string smallestFromLeaf(TreeNode* root) {
		string s="";
        string ans;
		helper(root,s,ans);
		return ans;
	}
};