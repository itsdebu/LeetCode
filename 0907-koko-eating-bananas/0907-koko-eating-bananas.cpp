class Solution {
public:
    bool min_hour(vector<int>&piles,int k,int h)
    {
        long long ans = 0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%k==0)
            {
                ans += (piles[i]/k);
            }
            else ans += (piles[i]/k) + 1;
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(),piles.end());

        int low = 1,high = mx;
        int min_k = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            cout<<mid<<endl;
            bool mid_time = min_hour(piles,mid,h);
            if(mid_time)
            {
                min_k = min(min_k,mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return min_k;
    }
};