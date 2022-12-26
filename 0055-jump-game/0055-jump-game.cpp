class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int next = n-1;
        for(int i = n-2;i >= 0;i--){
            if(i+nums[i] >= next){
                next = i;
            }
        }
        return next == 0;
    }
};