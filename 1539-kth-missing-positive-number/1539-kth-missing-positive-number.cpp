class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto i:arr)mp[i]++;
        vector<int>v;
        for(int i=1;i<=k+arr.size();i++)
        {
            if(mp.find(i)==mp.end())v.push_back(i);
        }return v[k-1];
    }
};