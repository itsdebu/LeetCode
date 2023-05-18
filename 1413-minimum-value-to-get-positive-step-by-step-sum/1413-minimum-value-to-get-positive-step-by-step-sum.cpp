class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int i=1;
        while(1)
        {
            int sum=i;
            for(int j=0;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum<1)break;
            }
            if(sum>=1)return i;
            i++;
        }return 0;
    }
};