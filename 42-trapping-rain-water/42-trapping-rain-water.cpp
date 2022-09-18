class Solution {
public:
    int trap(vector<int>& arr) {
        stack<int>st;
        int n=arr.size();
        int mn[n],mx[n];
        mn[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            mn[i]=max(mn[i-1],arr[i]);
        }
        mx[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mx[i]=max(mx[i+1],arr[i]);
        }
        int water[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            water[i]=min(mn[i],mx[i])-arr[i];
            sum+=water[i];
        }return sum;
    }
};