class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            if((n&(n-1))==0)mp[n]++;
        }
        for(auto i:mp)v.push_back(i.first);
        sort(v.begin(),v.end());
        if(v[0]!=1)return 1;
        int i=0;
        for(i=0;i<v.size();i++)
        {
            if(v[i]!=pow(2,i))return pow(2,i);
        }
        return pow(2,i);
    }
};