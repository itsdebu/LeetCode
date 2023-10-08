class Solution {
public:
    int dp[501][501];
    int max_product(int index1,int index2,vector<int>&nums1,vector<int>&nums2)
    {
        if(index1==nums1.size() or index2==nums2.size())return 0;

        if(dp[index1][index2]!=-1)return dp[index1][index2];

        int take_from_both = nums1[index1]*nums2[index2] + max_product(index1+1,index2+1,nums1,nums2);
        int not_take_from_nums1 = max_product(index1+1,index2,nums1,nums2);

        int not_take_from_nums2 = max_product(index1,index2+1,nums1,nums2);

        int not_take_from_both = max_product(index1+1,index2+1,nums1,nums2);

        return dp[index1][index2] = max({take_from_both,not_take_from_nums1,not_take_from_nums2,not_take_from_both});

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        memset(dp,-1,sizeof(dp));
        
        int ans = max_product(0,0,nums1,nums2);

        if(ans == 0)
        {
            int a = *max_element(nums1.begin(), nums1.end());
            int b = *min_element(nums1.begin(), nums1.end());
           
            int c = *max_element(nums2.begin(), nums2.end());
            int d = *min_element(nums2.begin(), nums2.end());
           
           return max(a*d, b*c);
        }
        return ans;
    }
};