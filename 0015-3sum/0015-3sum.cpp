class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int sum=0-nums[i];
            int l=i+1,h=nums.size()-1;
            while(l<h)
            {
                if(nums[l]+nums[h]==sum)
                {
                    st.insert({nums[i],nums[l],nums[h]});
                    l++,h--;
                }
                else if(nums[l]+nums[h]>sum)
                {
                    h--;
                }
                else l++;
            }
        }vector<vector<int>>v;
        for(auto i:st)v.push_back(i);
        return v;
        
    }
};