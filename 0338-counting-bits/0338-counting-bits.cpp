class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int bit_count = 0;
            int num = i;
            while(num!=0)
            {
                num&=num-1;
                bit_count++;
            }
            ans.push_back(bit_count);
        }
        return ans;
    }
};