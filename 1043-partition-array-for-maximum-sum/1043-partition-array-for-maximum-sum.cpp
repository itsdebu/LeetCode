class Solution {
public:
    int dp[501];
    int max_sum(int index,vector<int>&arr,int k,int n)
    {
        if(index==arr.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int len=0,mx=INT_MIN,mx_sum=INT_MIN;
        for(int j=index;j<min(n,index+k);j++)
        {
            len++;
            mx=max(mx,arr[j]);
            int sum= (mx*len) + max_sum(j+1,arr,k,n);
            mx_sum=max(mx_sum,sum);
        }return dp[index]=mx_sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return max_sum(0,arr,k,arr.size());
    }
};