class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int ans=0;
        unordered_map<string,int> mp;
        for(int i=0;i<n;++i){
            mp[nums[i]]++;
        }
        for(int i=0;i<n;++i){
            if(nums[i]==target.substr(0,nums[i].size())){
                string remaining=target.substr(nums[i].size());
                if(mp.find(remaining)!=mp.end()){
                    ans+=mp[remaining];
                    if(remaining==nums[i]){
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};