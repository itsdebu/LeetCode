class Solution {
public:
    int maxIceCream(vector<int>& cost, int coins) {
        sort(cost.begin(),cost.end());
        int sum=0,count=0;
        for(int i=0;i<cost.size();i++)
        {
            sum+=cost[i];
            cout<<sum<<" ";
            if(sum>=coins)break;
            count++;
        }if(sum==coins)count++;
        return count;
    }
};