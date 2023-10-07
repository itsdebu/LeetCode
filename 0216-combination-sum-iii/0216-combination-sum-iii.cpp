class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& v,int num,int k,int n)
    {
        if(n<0 or v.size()>k)return;
        if(n==0 and v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        for(int i=num;i<=9;i++)
        {
            v.push_back(i);
            helper(v,i+1,k,n-i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        helper(v,1,k,n);
        return ans;
    }
};