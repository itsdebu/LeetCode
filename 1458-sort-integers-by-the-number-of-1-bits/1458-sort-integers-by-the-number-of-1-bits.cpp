class Solution {
public:
    int BitsSetTable256[256];
    void initialize() 
    { 
        BitsSetTable256[0] = 0; 
        for (int i = 0; i < 256; i++)
        { 
            BitsSetTable256[i] = (i & 1) + 
            BitsSetTable256[i / 2]; 
        } 
    } 
    int countSetBits(int n) 
    { 
        return (BitsSetTable256[n & 0xff] + 
                BitsSetTable256[(n >> 8) & 0xff] + 
                BitsSetTable256[(n >> 16) & 0xff] + 
                BitsSetTable256[n >> 24]); 
    } 
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            int count = 0;

            count = __builtin_popcount(arr[i]);
            v.push_back({count,arr[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};