class Solution {
public:
    void help(int n,int k,int st,vector<int>&ans,vector<vector<int>>&res)
    {
        if(ans.size()==k)
        {
            res.push_back(ans);
            return;
        }
        for(int i=st;i<=n;i++)
        {
            ans.push_back(i);
            help(n,k,i+1,ans,res);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>res;
        help(n,k,1,ans,res);
        return res;
    }
};