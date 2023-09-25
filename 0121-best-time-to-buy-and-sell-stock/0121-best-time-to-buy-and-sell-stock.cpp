class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            mn = min(mn,prices[i]);

            if(prices[i]>mn)
            {
                mx = max(mx,prices[i]-mn);
            }
        }if(mx<0)return 0;
        return mx;
    }
};