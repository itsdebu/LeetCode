class Solution {
public:
    bool winnerOfGame(string nums) {
        int alice = 0;
        int bob = 0;

        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i-1]=='A' and nums[i]=='A' and nums[i+1]=='A')alice++;
            if(nums[i-1]=='B' and nums[i]=='B' and nums[i+1]=='B')bob++;
        }
        return alice>bob;
    }
};