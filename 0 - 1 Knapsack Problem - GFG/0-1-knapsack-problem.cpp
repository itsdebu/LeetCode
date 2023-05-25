//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int max_score(int index,int given,int wt[],int val[],vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(given>=wt[index])return val[index];
            else return 0;
        }
        if(dp[index][given]!=-1)return dp[index][given];
        int not_take=0+max_score(index-1,given,wt,val,dp);
        int take=0;
        if(wt[index]<=given)
        {
            take=val[index]+max_score(index-1,given-wt[index],wt,val,dp);
        }
        return dp[index][given]=max(take,not_take);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return max_score(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends