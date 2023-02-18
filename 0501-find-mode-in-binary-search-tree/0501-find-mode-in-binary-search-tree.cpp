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
	//Initializing unordered map universally so tha we can use it anywhere also here we are using hashmap to store the frequency of elements in BST.
	unordered_map<int,int>mp;
	TreeNode* solve(TreeNode* root)
	{
		//Here we are using dfs to store elements in map in preoreder traversal;
		if(root==NULL)return NULL;
		mp[root->val]++;
		solve(root->left);
		solve(root->right);
		return NULL;
	}
	vector<int> findMode(TreeNode* root) {
		//initialize a vector to store the maximum frequent elements 
		vector<int>v;
		solve(root);//calling function solve to store elements in hashmap
		int mx=INT_MIN;
		for (auto i : mp) {
			mx=max(mx,i.second);//here we are finding maximum frequecy in BST of element.
		}
		for(auto i:mp)
		{
			if(mx==i.second)v.push_back(i.first);//here we are comparing the max frequency to every element if it does then push it in vector;
		}return v;//and then return it
	}
};
// Plss Upvote If You Found This Helpful