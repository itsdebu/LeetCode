class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        vector<int>v;
        int mx=arr[arr.size()-1];
        int index=0;
        for(int i=1;i<=mx;i++)
        {
            if(i!=arr[index])v.push_back(i);
            else index++;
        }
        if(v.size()==0)
        {
            return mx+k;
            
        }
        else if(v.size()<k)
        {
            return (k-v.size())+mx;
        }
        return v[k-1];
    }
};