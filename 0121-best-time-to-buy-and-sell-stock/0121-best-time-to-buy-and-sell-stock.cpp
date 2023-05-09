class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0],mx=prices[0];
        int max_profit=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mn)mn=prices[i];
            mx=prices[i];
            max_profit=max(max_profit,mx-mn);
        }return max_profit;
    }
};