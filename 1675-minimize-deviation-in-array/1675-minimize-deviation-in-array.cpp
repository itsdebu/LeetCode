class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX,mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2!=0)nums[i]*=2;
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        int diff=mx-mn;
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        while(pq.top()%2==0)
        {
            int top=pq.top();
            pq.pop();
            diff=min(diff,top-mn);
            top/=2;
            mn=min(top,mn);
            pq.push(top);
        }diff=min(diff,pq.top()-mn);
        return diff;
    }
};