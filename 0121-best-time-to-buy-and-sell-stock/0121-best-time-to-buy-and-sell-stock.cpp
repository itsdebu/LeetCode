class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            if(mn>prices[i])mn=prices[i];
            mx=max(mx,prices[i]-mn);
        }return mx;
    }
};